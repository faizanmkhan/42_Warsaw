# User Documentation

This file is for user who wants to **use** the running Inception
stack — no Docker knowledge required. If you want to build or modify
the project itself, see [DEV_DOC.md](DEV_DOC.md) instead.

## 1. What services are provided

| Service | What it is | How you reach it |
|---|---|---|
| WordPress site | The public website | `https://<login>.42.fr` |
| WordPress admin panel | Content/site management | `https://<login>.42.fr/wp-admin` |
| Adminer | Web UI to browse/edit the MariaDB database | `http://localhost:8082` |
| Static showcase site | A small placeholder static page | `http://localhost:8081` |
| FTP | File access to the WordPress files | any FTP client, `ftp://<login>.42.fr` (port 21) |
| Grafana | Dashboards for the metrics below | `http://localhost:3000` |
| Prometheus | Raw metrics / target health | `http://localhost:9090` |

Internally (not reachable from outside), the stack also runs MariaDB,
Redis (WordPress's cache), and three metrics exporters that feed
Grafana/Prometheus.

> Your browser will show a certificate warning on the WordPress site.
> That's expected — the certificate is self-signed (there's no public
> CA for a `*.42.fr` address). Click through ("Advanced → Proceed") to
> continue.

## 2. Starting and stopping the project

From the project's root directory, on the machine where it's
installed:

```bash
make            # start everything (builds the first time)
make down       # stop everything, keep all your data
make stop       # pause containers without removing them
make start      # resume previously stopped containers
make restart    # stop then start again
```

You don't need to run these as root; `make` will only ask for your
password (`sudo`) when it needs to edit `/etc/hosts` (`make hosts`) or
delete persisted data (`make fclean`).

## 3. Accessing the website and the administration panel

1. Make sure the project is running (`make` was run successfully).
2. Open `https://<login>.42.fr` in your browser for the public site.
3. Open `https://<login>.42.fr/wp-admin` for the admin panel and log
   in with the WordPress admin account (see below for the username
   and where its password lives).

If the domain doesn't resolve in your browser :
- add `127.0.0.1  <login>.42.fr` to your machine's hosts file by hand.

## 4. Locating and managing credentials

All usernames live in **`srcs/.env`**, all passwords live as plain
text in **one file per password** under **`secrets/`** (this is what we call "Docker secrets" — Docker hands each container only
the password file it actually needs, nothing more).

| Account | Username (in `srcs/.env`) | Password file |
|---|---|---|
| WordPress administrator | `WP_ADMIN_USER` (default: `siteowner`) | `secrets/wp_admin_password.txt` |
| WordPress regular user | `WP_USER` (default: `editor`) | `secrets/wp_user_password.txt` |
| MariaDB application user | `MYSQL_USER` (default: `wp_user`) | `secrets/db_password.txt` |
| MariaDB root | `root` | `secrets/db_root_password.txt` |
| FTP account | `FTP_USER` (default: `ftp_user`) | `secrets/ftp_password.txt` |
| Grafana administrator | `GRAFANA_ADMIN_USER` (default: `grafana_user`) | `secrets/grafana_admin_password.txt` |

**To change a password**, edit the relevant file under `secrets/`
with a text editor and run `make restart` — the new file is what gets
mounted into the container the next time it starts. (Passwords are
*not* re-applied to already-created WordPress/MariaDB accounts
automatically; for those, change them from inside the application —
e.g. WordPress's own "Users" admin screen, or `wp user update` — after
updating the secret file, so both stay in sync.)

Adminer needs no separate account of its own: log in to it with the
MariaDB credentials above (server: `mariadb`, system: MySQL/MariaDB).

## 5. Checking that everything is running correctly

```bash
make ps
```

Every service should show as `running` (or `Up ...`). If something
shows `Restarting` or `Exited`, check its logs:

```bash
make logs  # everything, live
docker compose -f srcs/docker-compose.yml logs <service-name>
```

(common names: `nginx`, `wordpress`, `mariadb`, `redis`, `ftp`,
`adminer`, `portfolio`, `prometheus`, `grafana`, `node`)

A few quick, no-login health checks:

- WordPress site responds: `curl -k https://<login>.42.fr/` returns
  HTML.
- Prometheus sees everything: open `http://localhost:9090/targets` —
  every target should be `UP`.
- Grafana has data: open `http://localhost:3000`, log in with the
  Grafana admin account above, and open the **Dashboards → Inception —
  VM Resources** dashboard (it's pre-loaded, you don't need to
  import anything).
