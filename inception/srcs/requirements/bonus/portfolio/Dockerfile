FROM debian:bookworm

RUN apt-get update && \
    apt-get install -y --no-install-recommends nginx && \
    rm -rf /var/lib/apt/lists/* && \
    rm -f /etc/nginx/sites-enabled/default /etc/nginx/conf.d/default.conf

COPY conf/portfolio.conf /etc/nginx/conf.d/portfolio.conf

COPY srcs/ /var/www/static/

EXPOSE 7070

ENTRYPOINT ["nginx", "-g", "daemon off;"]
