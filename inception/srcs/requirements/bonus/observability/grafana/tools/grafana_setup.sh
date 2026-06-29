#!/bin/bash

set -e

if [ -f /run/secrets/grafana_admin_password ]; then
    GF_SECURITY_ADMIN_PASSWORD="$(cat /run/secrets/grafana_admin_password)"
    export GF_SECURITY_ADMIN_PASSWORD
else
    echo "WARNING: grafana_admin_password secret not found." >&2
fi

chown -R grafana:grafana /var/lib/grafana /var/log/grafana /etc/grafana

exec setpriv --reuid=472 --regid=472 --init-groups \
    /usr/share/grafana/bin/grafana server \
    --homepath=/usr/share/grafana \
    --config=/etc/grafana/grafana.ini
