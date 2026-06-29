FROM debian:bookworm

ARG ADMINER_VERSION=5.4.2

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        ca-certificates \
        php8.2-cli \
        php8.2-mysqli \
        curl \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/adminer && \
    curl -fsSL -o /var/www/adminer/index.php \
        "https://github.com/vrana/adminer/releases/download/v${ADMINER_VERSION}/adminer-${ADMINER_VERSION}.php"

WORKDIR /var/www/adminer
EXPOSE 8080

ENTRYPOINT ["php", "-S", "0.0.0.0:8080", "-t", "/var/www/adminer"]
