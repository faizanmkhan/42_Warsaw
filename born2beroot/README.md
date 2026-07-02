# Born2beRoot

42 System Administration Project — Virtualization, Linux Security, and Server Hardening

---

## Project Overview

**Born2beRoot** is an introductory system administration project from the 42 curriculum.
The objective is to configure a secure Linux server inside a virtual machine while applying
strict security policies and system monitoring.

This project focuses on:

- Virtualization
- Disk partitioning with encrypted LVM
- User and group management
- SSH hardening
- Firewall configuration
- System monitoring via scripting
- Secure service deployment (Bonus: LAMP + WordPress)

---

## Virtual Machine Setup

- **Virtualization:** VirtualBox
- **OS:** Debian (minimal installation)
- No graphical interface
- Encrypted LVM partitions
- Proper hostname configuration (login42 or 42login)

---

## Mandatory Configuration

### Partitioning (Encrypted LVM)

The system uses encrypted LVM with separate logical volumes for:

- `/`
- `/home`
- `/var`
- `/srv`
- `/tmp`
- `/var/log`

This ensures:

- Better security
- Easier storage management
- Fault isolation

---

### User and Group Management

- Create a non-root user (named after your 42 login)
- Add user to the `sudo` group
- Add user to a group named after your login (e.g. `user42`)
- Root login disabled via SSH

#### Password Policy

Configured using PAM (`/etc/pam.d/common-password` and `/etc/login.defs`):

- Minimum 10 characters
- Uppercase and lowercase letters required
- At least one number
- At least one special character
- Password must differ from the previous one
- Password expiration policy enforced (max 30 days)
- Minimum password age enforced (2 days)
- Password change warning 7 days before expiration
- Password history restriction (cannot reuse last 3 passwords)
- Maximum login attempts limited (via `libpam-pwquality` / `faillock`)

---

### Sudo Policy

Configured in `/etc/sudoers` (or `/etc/sudoers.d/`):

- Maximum 3 authentication attempts
- Custom sudo log file (`/var/log/sudo/sudo.log`)
- Secure `PATH` defined for sudo sessions
- TTY required for sudo usage
- Informative error message on authentication failure

---

### SSH Configuration

Configured in `/etc/ssh/sshd_config`:

- SSH runs on a custom port (e.g. `4242`) instead of the default 22
- Root login via SSH is disabled (`PermitRootLogin no`)
- Connection is only possible with the configured non-root user

---

### Firewall (UFW)

- UFW enabled and active
- Only the custom SSH port allowed
- All other incoming connections denied

```bash
ufw allow 4242
ufw enable
ufw status
```

---

### Monitoring Script

A Bash script (`monitoring.sh`) that displays key system information every 10 minutes
via `wall`, using a `cron` job. It reports:

- Architecture and kernel version
- Number of physical/virtual CPUs
- RAM usage (used / total, in percentage)
- Disk usage (used / total, in percentage)
- CPU load
- Last boot date and time
- LVM active status (yes/no)
- Number of active TCP connections
- Number of users currently logged in
- IPv4 address and MAC address
- Number of commands executed via sudo

Example crontab entry:

```bash
*/10 * * * * root /root/monitoring.sh
```

---

## Bonus Part

Once the mandatory part is fully validated, bonus features may include:

- WordPress with its dependencies (excluding `php-fpm`), configured with Lighttpd
- MySQL/MariaDB service for WordPress data
- An additional service of your choice (e.g. FTP server, second website, etc.)
- A script that automatically sets up a new persistent partition

---

## Usage

1. Install VirtualBox and create a new VM with a Debian minimal ISO.
2. Follow the partitioning steps to set up encrypted LVM.
3. Configure the non-root user, groups, and password policy.
4. Harden SSH and configure UFW.
5. Deploy the `monitoring.sh` script and schedule it via `cron`.
6. (Optional) Complete the bonus part with LAMP/LEMP and WordPress.

---

## Resources

- [42 Born2beRoot Subject (PDF)](https://cdn.intra.42.fr/pdf/pdf/)
- [Debian Documentation](https://www.debian.org/doc/)
- [UFW Documentation](https://help.ubuntu.com/community/UFW)
- [PAM Documentation](https://www.man7.org/linux/man-pages/man8/pam.8.html)

---
