#!/bin/sh
set -e

chown -R nobody:nogroup /prometheus

exec setpriv --reuid=65534 --regid=65534 --init-groups \
    /usr/local/bin/prometheus \
    --config.file=/etc/prometheus/prometheus.yml \
    --storage.tsdb.path=/prometheus \
    --web.enable-lifecycle
