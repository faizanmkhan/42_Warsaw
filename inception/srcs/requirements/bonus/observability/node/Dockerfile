FROM debian:bookworm

ARG NODE_EXPORTER_VERSION=1.10.2

RUN apt-get update && \
    apt-get install -y --no-install-recommends ca-certificates wget && \
    wget -qO /tmp/node_exporter.tar.gz \
      "https://github.com/prometheus/node_exporter/releases/download/v${NODE_EXPORTER_VERSION}/node_exporter-${NODE_EXPORTER_VERSION}.linux-amd64.tar.gz" && \
    mkdir -p /tmp/ne && \
    tar -xzf /tmp/node_exporter.tar.gz -C /tmp/ne --strip-components=1 && \
    cp /tmp/ne/node_exporter /usr/local/bin/ && \
    apt-get purge -y --auto-remove wget && \
    rm -rf /var/lib/apt/lists/* /tmp/*

    USER nobody

EXPOSE 9100

ENTRYPOINT ["/usr/local/bin/node_exporter"]
CMD [ \
    "--path.procfs=/host/proc", \
    "--path.sysfs=/host/sys", \
    "--path.rootfs=/rootfs", \
    "--collector.filesystem.mount-points-exclude=^/(sys|proc|dev|host|rootfs)($|/)" \
]
