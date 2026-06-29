FROM debian:bookworm

ARG PROMETHEUS_VERSION=3.12.0

RUN apt-get update && \
    apt-get install -y --no-install-recommends ca-certificates wget && \
    wget -qO /tmp/prometheus.tar.gz \
      "https://github.com/prometheus/prometheus/releases/download/v${PROMETHEUS_VERSION}/prometheus-${PROMETHEUS_VERSION}.linux-amd64.tar.gz" && \
    mkdir -p /tmp/prom /etc/prometheus /prometheus && \
    tar -xzf /tmp/prometheus.tar.gz -C /tmp/prom --strip-components=1 && \
    cp /tmp/prom/prometheus /tmp/prom/promtool /usr/local/bin/ && \
    apt-get purge -y --auto-remove wget && \
    rm -rf /var/lib/apt/lists/* /tmp/*

COPY conf/prometheus.yml   /etc/prometheus/prometheus.yml
COPY tools/prometh_setup.sh   /usr/local/bin/prometh_setup.sh

RUN chmod +x /usr/local/bin/prometh_setup.sh

EXPOSE 9090

ENTRYPOINT ["/usr/local/bin/prometh_setup.sh"]
