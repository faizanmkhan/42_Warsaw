# 🐳 Inception

> 42 System Administration / DevOps Project — Containerized Multi-Service Infrastructure

---

## 📌 Project Overview

**Inception** is a system administration project from the 42 curriculum focused on containerization and service orchestration using Docker.

The objective is to design and deploy a secure, production-like infrastructure composed of multiple isolated services, each running inside its own Docker container and orchestrated using Docker Compose.

This project emphasizes:

- Containerization principles
- Service isolation
- Reverse proxy configuration
- Persistent data management
- Secure inter-service communication
- Infrastructure-as-Code practices

---

# 🏗️ Architecture

The infrastructure consists of the following services:

- **Nginx** (Reverse Proxy with TLS)
- **WordPress** (PHP-FPM)
- **MariaDB**
- Docker network for secure internal communication
- Persistent volumes for database and website data
```
inception/
├── docker-compose.yml
├── .env
├── requirements/
│ ├── nginx/
│ │ ├── Dockerfile
│ │ └── conf/
│ ├── wordpress/
│ │ ├── Dockerfile
│ │ └── conf/
│ └── mariadb/
│ ├── Dockerfile
│ └── conf/
└── Makefile
```

---

# 🐳 Services

## 🌐 Nginx

- Acts as a reverse proxy
- Handles HTTPS connections
- Uses TLS certificates
- Forwards traffic to WordPress (PHP-FPM)

Key features:

- Runs in its own container
- No root process
- Only exposes port 443
- Configured with secure SSL settings

---

## 🧩 WordPress (PHP-FPM)

- Runs PHP-FPM (no Apache)
- Communicates internally with MariaDB
- Not publicly exposed
- Connected only through Docker network

Environment variables are used to configure:

- Database name
- Database user
- Database password
- WordPress admin credentials

---

## 🛢️ MariaDB

- Dedicated database container
- Persistent volume attached
- Not exposed to host machine
- Only accessible from WordPress container

Database is initialized automatically using environment variables.

---

# 🔐 Security Considerations

- Each service runs in an isolated container
- Containers run as non-root users
- Internal Docker network used for inter-service communication
- Only Nginx exposes a public port
- TLS encryption enabled
- Sensitive configuration handled through environment variables

---

# 📦 Volumes & Persistence

Persistent Docker volumes ensure data survives container restarts:

- WordPress files volume
- MariaDB database volume

This guarantees:

- No data loss
- Proper separation between application and data
- Production-like reliability

---

# 🚀 How to Run

### 1️⃣ Build and Start Containers

```bash
make
```
Manually 

```bash
docker-compose up --build 
```