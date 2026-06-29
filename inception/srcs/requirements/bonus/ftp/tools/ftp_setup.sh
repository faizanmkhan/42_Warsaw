#!/bin/bash

set -euo pipefail

: "${FTP_USER:?}"; : "${FTP_PASSWORD_FILE:?}"

FTP_PASSWORD="$(cat "$FTP_PASSWORD_FILE")"

if ! id "${FTP_USER}" >/dev/null 2>&1; then
    useradd --home-dir /var/www/wordpress --shell /usr/sbin/nologin \
        --gid www-data "${FTP_USER}"
fi

echo "${FTP_USER}:${FTP_PASSWORD}" | chpasswd
echo "/usr/sbin/nologin" >> /etc/shells

if [ -n "${PASV_ADDRESS:-}" ]; then
    if ! grep -q "^pasv_address=" /etc/vsftpd.conf; then
        echo "pasv_address=${PASV_ADDRESS}" >> /etc/vsftpd.conf
    fi
fi

chmod -R g+rwX /var/www/wordpress 2>/dev/null || true

echo "[FTP] Starting vsftpd in the foreground..."
exec /usr/sbin/vsftpd /etc/vsftpd.conf
