# Developer Documentation

This file is for anyone setting the project up to build on it, debug
it, or extend it. For non-technical usage, see
[USER_DOC.md](USER_DOC.md).

## 1. Setting up the environment from scratch

### Prerequisites

- A Linux virtual machine.
- `git`.
- Docker Engine ≥ 24 with the Compose **plugin** (`docker compose ...`
  — check with `docker compose version`; the legacy standalone
  `docker-compose` binary is *not* required and not used here).
- `make`.
- `sudo` rights (only needed for `make hosts` and `make fclean`).

### Clone and configure

```bash
git clone <this-repo> inception
cd inception
```

**Configuration files you need to touch before the first build:**

1. `srcs/.env` — replace `LOGIN=login` with your real 42 login on the
   very first variable. Everything else in the file (domain name, WP
   URL, e-mails) is derived from `${LOGIN}` automatically. The rest of
   `.env` (database name, WordPress title, usernames, ports, …) can be
   left as-is or tuned to taste — none of it is secret.
2. `secrets/*.txt` — six files, one password each. Replace every
   placeholder (`changeme_...`) with a real password:

   ```
   secrets/db_root_password.txt
   secrets/db_password.txt
   secrets/wp_admin_password.txt
   secrets/wp_user_password.txt
   secrets/ftp_password.txt
   secrets/grafana_admin_password.txt
   ```

   These files have **no trailing newline** (so a plain `cat file`
   reads back exactly the password, nothing more) — keep that
   property if you regenerate them, e.g.:

   ```bash
   printf '%s' 'my-new-strong-password' > secrets/db_password.txt
   ```

Both `srcs/.env` and `secrets/` are read by `docker-compose.yml`
*and* by the `Makefile` (it `include`s `srcs/.env` to know your
`LOGIN` for the host data directories) — there is exactly one place to
edit each setting.

## 2. Building and launching the project

```bash
make # = make data-dirs, then make up
```

What `make` actually does, target by target:

| Target | What it does |
|---|---|
| `make` / `make all` | `data-dirs` then `up` |
| `make build` | Builds every image, doesn't start anything |
| `make up` | Creates host data dirs, then `docker compose up -d --build` |
| `make down` | Stops and removes containers (volumes are kept) |
| `make start` / `make stop` | Start/stop existing containers without rebuilding |
| `make restart` | `down` then `up` |
| `make logs` | `docker compose logs -f` (all services) |
| `make ps` / `make status` | `docker compose ps` |
| `make hosts` | Idempotently appends `127.0.0.1 <login>.42.fr` to `/etc/hosts` (sudo) |
| `make data-dirs` | `mkdir -p` every `/home/<login>/data/<service>` directory |
| `make clean` | `down` + `docker system prune -f` |
| `make fclean` | `down -v --rmi all --remove-orphans`, then wipes `/home/<login>/data` (sudo) |
| `make re` | `fclean` then `all` |

You can always call Compose directly if you need a flag the Makefile
doesn't expose:

```bash
docker compose -f srcs/docker-compose.yml --env-file srcs/.env <command>
```

### Build order / dependencies

`docker-compose.yml` declares 12 services. `depends_on` only
sequences container **start order**; actual readiness is handled
inside each entrypoint script (e.g. WordPress's entrypoint polls
MariaDB with `mysqladmin ping` — bounded retries, not an infinite
loop — before running `wp core install`).

```
mariadb ──┐
          ├─▶ wordpress ──▶ nginx ──▶ nginx-exporter
redis ────┘        │
                   └─▶ ftp (shares the wordpress_data volume)

docker  ──────▶ host system  ──┐
                               ├─▶ (scraped by) prometheus ──▶ grafana
node-exporter ─────────────────┘

adminer ──▶ (talks to) mariadb directly, no build-order dependency needed
portfolio website ──▶ standalone, no dependencies
```

## 3. Managing containers and volumes

### Containers

```bash
make ps  #(status of every service)
docker compose -f srcs/docker-compose.yml logs -f <service>
docker compose -f srcs/docker-compose.yml exec <service> bash
docker compose -f srcs/docker-compose.yml restart <service>
```

Service names match the keys in `srcs/docker-compose.yml`: `mariadb`,
`wordpress`, `nginx`, `redis`, `ftp`, `portfolio`, `adminer`,
`prometheus`, `grafana`, `node-exporter`.

Rebuilding a single service after editing its Dockerfile or conf:

```bash
docker compose -f srcs/docker-compose.yml --env-file srcs/.env \
    up -d --build <service>
```

### Volumes

```bash
docker volume ls | grep srcs  # Compose prefixes volume names with the project name
docker volume inspect srcs_wordpress_data
```

Every persistent volume (`mariadb_data`, `wordpress_data`,
`redis_data`, `grafana_data`, `prometheus_data`) is a named volume
whose `driver_opts` force it onto a fixed bind path on the host —
inspect it with `docker volume inspect` and you'll see
`Mountpoint`/`Options.device` pointing straight at
`/home/<login>/data/<service>`. That means you can also just `ls`
that directory directly on the host; no Docker command required.

### Secrets

Docker secrets are mounted read-only at `/run/secrets/<name>` inside
each container that declares them in `docker-compose.yml`. To inspect
which secret a container actually received (without printing the
password to your shell history):

```bash
docker compose -f srcs/docker-compose.yml exec wordpress \
    bash -c 'wc -c < /run/secrets/db_password'
```

### Stress Testing

Install `stress-ng` and then run the following to check vm resouces being used

```bash
stress-ng --cpu 4 --timeout 60s
stress-ng --vm 2 --vm-bytes 512M --timeout 60s
```

## 4. Where project data lives and how it persists

| Data | Host path | Backed by |
|---|---|---|
| MariaDB data files | `/home/<login>/data/mariadb` | `mariadb_data` volume |
| WordPress core + uploads + plugins | `/home/<login>/data/wordpress` | `wordpress_data` volume (also mounted, read-only, into `nginx`; read-write into `ftp`) |
| Redis dataset (if persistence is ever enabled) | `/home/<login>/data/redis` | `redis_data` volume |
| Grafana DB (dashboards, users, …) | `/home/<login>/data/grafana` | `grafana_data` volume |
| Prometheus TSDB | `/home/<login>/data/prometheus` | `prometheus_data` volume |

Because these are real bind-mounted host directories, data survives
`make down`, `docker compose down`, container restarts/crashes, and
even image rebuilds — it's only removed by `make fclean` (which
deletes `/home/<login>/data` outright, with a `sudo` prompt) or by a
manual `rm -rf`.

`secrets/*.txt` and `srcs/.env` are **not** containers' runtime data —
they're this repo's own configuration, read once at container start.
Editing them and running `make restart` is enough to pick up new
non-secret config; for passwords, see the note in
[USER_DOC.md](USER_DOC.md#4-locating-and-managing-credentials) about
keeping the secret file and the actual application account in sync.

## 5. Adding a new service

1. `mkdir -p srcs/requirements/bonus/<name>` (or under
   `requirements/` directly for a mandatory-style service).
2. Write `Dockerfile` (+ `conf/`, `tools/` as needed) following the
   existing services as a template: Debian base, `apt`/official
   release download, an entrypoint that ends with `exec <real
   process>` in the foreground.
3. Add a `services.<name>:` block to `srcs/docker-compose.yml`
   (`build.context`, `networks: [inception]`, `restart:
   unless-stopped`, and whatever `ports`/`volumes`/`secrets` it
   needs).
4. `make build` (or `up -d --build <name>`) to test it in isolation
   before wiring it into anything else.
