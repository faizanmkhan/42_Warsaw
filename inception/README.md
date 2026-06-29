
*This project has been created as part of the 42 curriculum by `faikhan`.*

# Inception

A small, self-built Docker infrastructure: WordPress on its own
php-fpm container, talking to a dedicated MariaDB container, served
to the world exclusively through an NGINX reverse proxy on TLS — plus
a full bonus stack (Redis cache, FTP, a portfolio showcase site, Adminer,
and a Prometheus + Grafana observability stack).

Everything here is built from scratch (own Dockerfiles, Debian base
images, no pulled application images) and orchestrated with a single
`docker-compose.yml`, driven by one `Makefile`.

## Table of contents

- [Description](#description)
- [Architecture](#architecture)
- [Instructions](#instructions)
- [Project description](#project-description)
  - [Docker & the sources in this repo](#docker--the-sources-in-this-repo)
  - [Virtual Machines vs Docker](#virtual-machines-vs-docker)
  - [Secrets vs Environment Variables](#secrets-vs-environment-variables)
  - [Docker Network vs Host Network](#docker-network-vs-host-network)
  - [Docker Volumes vs Bind Mounts](#docker-volumes-vs-bind-mounts)
- [Further documentation](#further-documentation)
- [Resources](#resources)

## Description

**Inception** is a 42 school system-administration project. The goal
is to learn real-world Docker usage by hand-building a small but
realistic web infrastructure rather than relying on ready-made images:

- **NGINX** — the single entrypoint into the infrastructure, on port
  443 only, speaking TLSv1.2/TLSv1.3 exclusively.
- **WordPress + php-fpm 8.2** — no bundled web server, no bundled
  database; just the application layer.
- **MariaDB** — WordPress's database, on its own volume.
- **Bonus**: a Redis object cache for WordPress, an FTP server onto
  the WordPress volume, a showcase website, Adminer for
  database administration, and a Prometheus + Grafana observability
  stack (with node-exporter) — the "service of my
  choice" for this build.

Every container restarts automatically on crash, every image is
versioned (never `latest`), every password lives in a Docker secret,
and every non-secret setting lives in one `.env` file.

## Architecture

```
                                   ┌──────────────┐
                 :443 (TLS only)   │    nginx     │
   client ───────────────────────▶ │ (entrypoint) │
                                   └──────┬───────┘
                                          │ fastcgi :9000
                                   ┌──────▼───────┐        ┌────────────┐
                                   │  wordpress   │◀──────▶│   redis    │
                                   │  (php-fpm)   │  :6379 │  (cache)   │
                                   └──────┬───────┘        └────────────┘
                                          │ :3306
                                   ┌──────▼───────┐        ┌────────────┐
                                   │   mariadb    │        │    ftp     │
                                   └──────────────┘        │ (vsftpd)   │
                                                           └─────┬──────┘
                                                                 │shares the
                                                       wordpress_data volume

   Bonus, each on its own published port:
   static-website :7070   adminer :8080   grafana :3000   prometheus :9090
                                          (scraped by node exporter)
```

All containers share one user-defined bridge network (`inception`),
never `network: host`, never `--link`.

## Instructions

### 0. Prerequisites

- A Linux VM (It must run inside a VM).
- Docker Engine + the Docker Compose plugin (`docker compose`, not the
  old standalone `docker-compose`).
- `make`.

### 1. Configure

```bash
git clone <repo> inception && cd inception
```

Edit **`srcs/.env`** and replace the placeholder `login` on the very
first line (`LOGIN=login`) with your actual 42 login — the domain
name and WordPress URL are derived from it automatically.

Edit every file in **`secrets/`** and replace each placeholder
password with a real one:

```
secrets/db_root_password.txt
secrets/db_password.txt
secrets/wp_admin_password.txt
secrets/wp_user_password.txt
secrets/ftp_password.txt
secrets/grafana_admin_password.txt
```

Make your domain resolve locally:

```bash
#add "127.0.0.1  <login>.42.fr" to /etc/hosts
```

### 2. Build & run

```bash
make  # creates /home/<login>/data/*, builds, and starts everything
```

### 3. Visit it

| What | URL |
|---|---|
| WordPress site | `https://faikhan.42.fr` (self-signed cert — browser will give warning) |
| WordPress admin | `https://faikhan.42.fr/wp-admin` |
| Adminer (bonus) | `http://localhost:8082` |
| Static site (bonus) | `http://localhost:8081` |
| Grafana (bonus) | `http://localhost:3000` |
| Prometheus (bonus) | `http://localhost:9090` |

### 4. Stop / clean up

```bash
make down     # stop containers, keep data
make fclean   # stop, remove images/volumes, wipe /home/faikhan/data
```

See **[DEV_DOC.md](DEV_DOC.md)** for every Makefile/Compose command in
detail, and **[USER_DOC.md](USER_DOC.md)** for day-to-day,
non-technical usage.

## Project description

### Docker & the sources in this repo

```
.
├── Makefile                 # build/run/clean entry point
├── secrets/                 # one password per file, gitignored
└── srcs/
    ├── .env                 # all non-secret configuration
    ├── docker-compose.yml   # the whole stack, one file
    └── requirements/
        ├── mariadb/         # MariaDB only, own Dockerfile + entrypoint
        ├── nginx/           # NGINX only, TLS termination + reverse proxy
        ├── wordpress/       # WordPress + php-fpm 8.2 only
        └── bonus/
            ├── redis/                # WordPress object cache
            ├── ftp/                  # vsftpd onto the WordPress volume
            ├── portfolio/            # placeholder static site (no PHP)
            ├── adminer/              # single-file DB admin UI
            └── observability/
                ├── prometheus/       # metrics collection
                ├── grafana/          # dashboards, pre-provisioned
                ├── node-exporter/    # host metrics
```

Every service is **one Dockerfile, one container, one job** — built
from `debian:bookworm` (Debian 12, the penultimate stable release
behind Debian 13 "trixie"), with the actual software installed via
`apt` or downloaded from its own official release artifacts at build
time. Nothing here is `docker pull`-ed except the Debian base image
itself, which the subject explicitly allows.

Design choices worth calling out:

- **PHP 8.2** is Debian bookworm's *native* php-fpm branch, so no
  third-party APT repository is needed for it.
- **MariaDB 10.11** is likewise bookworm's native version.
- Every container's `ENTRYPOINT` ends by `exec`-ing the real,
  long-running server process in the foreground (`nginx -g "daemon
  off;"`, `exec mariadbd ...`, `exec php-fpm8.2 -F`, `redis-server`
  with `daemonize no`, …) so it is PID 1.
  Crash recovery is handled by Docker's `restart: unless-stopped`,
  not by a any loop.
- WordPress's admin account is named `siteowner` (configurable in
  `.env`), deliberately avoiding "admin"/"administrator" per the
  subject's requirement; a second, regular `editor` account is
  created alongside it.

### Virtual Machines vs Docker

| | Virtual Machine | Docker container |
|---|---|---|
| What it virtualizes | Hardware (via a hypervisor) | The OS's process/namespace layer |
| Kernel | Its own, full guest kernel per VM | Shared with the host kernel |
| Boot time | Tens of seconds to minutes | Milliseconds to a few seconds |
| Image size | Several GB (full OS) | Tens to hundreds of MB |
| Isolation strength | Very strong (separate kernel) | Weaker (namespaces/cgroups, shared kernel) |
| Density | A handful per host | Dozens to hundreds per host |
| Typical use here | The outer "machine" this whole project runs inside, per the subject | Each individual service (NGINX, WordPress, MariaDB, …) |

In this project the two are complementary, not competing: the subject
requires the *whole infrastructure* to run inside one VM, and *inside*
that VM, Docker is used to isolate and orchestrate each service
cheaply, without paying the overhead of one full VM per service.

### Secrets vs Environment Variables

Both are ways to get configuration into a container, but they trade
off differently:

| | Environment variables (`.env`) | Docker secrets (`secrets/`) |
|---|---|---|
| Storage | Plain text in the compose process / container environment | Mounted as a file under `/run/secrets/<name>`, in tmpfs |
| Visible via `docker inspect` | Yes, often in full | No, only the secret's *name*, never its content |
| Visible via `ps`/`/proc/<pid>/environ` in the container | Yes | No (it's a file, not an env var, unless the app copies it into one) |
| Intended for | Non-sensitive config (hostnames, usernames, feature flags, ports) | Sensitive config (passwords, keys, tokens) |
| Used here for | `DOMAIN_NAME`, `MYSQL_USER`, `WP_TITLE`, … (`srcs/.env`) | `db_password`, `wp_admin_password`, `grafana_admin_password`, … |

This project follows the subject's split exactly: `.env` is tracked
in git (it holds no secrets) and feeds every non-sensitive setting via
`env_file:`; every password is a one-line file under `secrets/`,
referenced through Compose's top-level `secrets:` and read by each
entrypoint script (`cat /run/secrets/<name>`) — never baked into a
Dockerfile, never printed, never committed (see `.gitignore`).

### Docker Network vs Host Network

| | `network_mode: host` | User-defined bridge network (used here) |
|---|---|---|
| Network namespace | Shared with the host — container sees the host's interfaces directly | Its own namespace, connected to the host via a virtual bridge |
| Port collisions | Possible with other host services | None — each container has its own port space |
| Container-to-container discovery | None built in (would need host IP + manual port bookkeeping) | Built-in DNS: containers reach each other by **service name** (e.g. `wordpress` resolves to the WordPress container) |
| Isolation | Minimal | Containers are only reachable from each other and from explicitly published ports |
| Allowed by this subject | No (`network: host` is explicitly forbidden, as is `--link`) | Yes — required |

`docker-compose.yml` declares one bridge network, `inception`, shared
by every service. NGINX talks to `wordpress:9000`, WordPress talks to
`mariadb:3306` and `redis:6379`, Prometheus talks to
`node-exporter:9100` / `nginx-exporter:9113` / `mysqld-exporter:9104`
— all by container/service name, none of it hardcoded by IP.

### Docker Volumes vs Bind Mounts

| | Named volume | Bind mount |
|---|---|---|
| Managed by | Docker (`docker volume ls/inspect`) | The host filesystem directly |
| Location | Docker-chosen path under `/var/lib/docker/volumes/...` by default | Wherever you point it |
| Portability | Same `docker-compose.yml` works on any host | Tied to a specific host path |
| Typical use | "I don't care where it lives, just persist it" | "I need this data at *this exact* host path" |

This project actually uses a **named volume with a `local` driver and
bind-mount `driver_opts`** — the best of both: it's declared and
managed like a normal named volume in `docker-compose.yml` (so
`docker volume ls`, backups, etc. all work normally), but its data is
forced onto a specific host path, `/home/faikhan/data/<service>`, as
required by the subject. `mariadb_data` and `wordpress_data` are
mandatory; `redis_data`, `grafana_data`, and `prometheus_data` extend
the same pattern to the bonus services that need to persist data.

## Further documentation

- **[USER_DOC.md](USER_DOC.md)** — for anyone who just wants to use
  the running site: what's running, how to start/stop it, where to
  find credentials, how to check everything is healthy.
- **[DEV_DOC.md](DEV_DOC.md)** — for anyone who wants to set the
  project up from a clean machine, build it, and work on it.

## Resources

Classic references used while building this project:

- [Docker documentation](https://docs.docker.com/)
- [Docker workshop](https://docs.docker.com/get-started/workshop/)
- [Docker Volumes](https://docs.docker.com/get-started/workshop/06_bind_mounts/#quick-volume-type-comparisons)
- [Compose file reference](https://docs.docker.com/reference/compose-file/)
- [Docker secrets in Compose](https://docs.docker.com/compose/how-tos/use-secrets/)
- [NGINX documentation](https://nginx.org/en/docs/)
- [Wordpress/NGINX/PHP_FPM](https://www.digitalocean.com/community/tutorials/how-to-install-wordpress-with-lemp-nginx-mariadb-and-php-on-debian-10)
- [TLS v1.2](https://my-ssl.com/learn/nginx-ssl-installation?ct=1780771200725)
- [WP-CLI documentation](https://wp-cli.org/)
- [MariaDB Knowledge Base](https://mariadb.com/kb/en/)
- [vsftpd documentation](https://security.appspot.com/vsftpd.html)
- [Prometheus documentation](https://prometheus.io/docs/)
- [Grafana documentation](https://grafana.com/docs/)
- [Debian wiki — Debian releases](https://wiki.debian.org/DebianReleases)
- [Containerization](https://docs.docker.com/guides/nodejs/containerize/)

### How AI was used

Concretely, AI was used for:

- Understanding the subject and it requirement.
- Planning and dividing the task for suitability.
- Researching current, real version numbers and install methods for
  every piece of software used (Debian's current/penultimate stable
  release, PHP/MariaDB's native versions in Debian 12, and the latest
  stable releases of Prometheus, Grafana, node_exporter, Adminer) via live web search, rather than relying on outdated memorized versions.
- Writing the Grafana provisioning (datasource + dashboard JSON) and
  the Prometheus scrape configuration for the observability bonus.
- Debugging and fixing the container and its configuration.
- Drafting README and the USER_DOC.md / DEV_DOC.md files.
