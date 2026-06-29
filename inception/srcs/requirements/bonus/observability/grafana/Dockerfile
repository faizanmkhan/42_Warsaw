FROM debian:bookworm

ARG GRAFANA_VERSION=13.0.2

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        ca-certificates tzdata libfontconfig1 wget && \
    wget -qO /tmp/grafana.tar.gz \
      "https://dl.grafana.com/grafana/release/${GRAFANA_VERSION}/grafana_${GRAFANA_VERSION}_26816849631_linux_amd64.tar.gz" && \
    mkdir -p /usr/share/grafana && \
    tar -xzf /tmp/grafana.tar.gz -C /usr/share/grafana --strip-components=1 && \
    apt-get purge -y --auto-remove wget && \
    rm -rf /var/lib/apt/lists/* /tmp/*

RUN groupadd -g 472 grafana && \
    useradd -u 472 -g 472 -M -s /usr/sbin/nologin grafana && \
    mkdir -p /var/lib/grafana /var/log/grafana

COPY conf/grafana.ini /etc/grafana/grafana.ini
COPY conf/provisioning/ /etc/grafana/provisioning/
COPY tools/grafana_setup.sh /usr/local/bin/grafana_setup.sh

RUN chmod +x /usr/local/bin/grafana_setup.sh && \
    chown -R grafana:grafana /usr/share/grafana /var/lib/grafana /var/log/grafana /etc/grafana

EXPOSE 3000

ENTRYPOINT ["/usr/local/bin/grafana_setup.sh"]
