# 🐧 Born2beRoot

> 42 System Administration Project — Virtualization, Linux Security, and Server Hardening

---

## 📌 Project Overview

**Born2beRoot** is an introductory system administration project from the 42 curriculum.

The objective is to configure a secure Linux server inside a virtual machine while applying strict security policies and system monitoring.

This project focuses on:

- Virtualization
- Disk partitioning with encrypted LVM
- User and group management
- SSH hardening
- Firewall configuration
- System monitoring via scripting
- Secure service deployment (Bonus: LAMP + WordPress)

---

# 🖥️ Virtual Machine Setup

- Virtualization: VirtualBox  
- OS: Debian (minimal installation)  
- No graphical interface  
- Encrypted LVM partitions  
- Proper hostname configuration  

---

# 🔐 Mandatory Configuration

## 🧱 Partitioning (Encrypted LVM)

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

## 👤 User & Group Management

- Create a non-root user  
- Add user to `sudo` group  
- Root login disabled via SSH  

### Password Policy

Configured using PAM:

- Minimum 10 characters  
- Uppercase and lowercase letters required  
- At least one number  
- Password expiration policy enforced  
- Password history restriction  
- Maximum login attempts limited  

---

## 🛡️ Sudo Policy

Configured in `/etc/sudoers`:

- Maximum 3 authentication attempts  
- Custom sudo log file  
- Secure path defined  
- TTY required for sudo usage  

---

## 🔥 Firewall (UFW)

- UFW enabled and active  
- Only SSH custom port allowed  
- All other incoming connections denied  

```bash
ufw allow <custom_port>
ufw enable