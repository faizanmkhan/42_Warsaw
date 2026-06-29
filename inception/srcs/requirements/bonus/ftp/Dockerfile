FROM unknown:tag

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        vsftpd \
    && rm -rf /var/lib/apt/lists/*

COPY conf/vsftpd.conf /etc/vsftpd.conf
COPY tools/ftp_setup.sh /usr/local/bin/ftp_setup.sh
RUN chmod +x /usr/local/bin/ftp_setup.sh && \
    mkdir -p /var/run/vsftpd/empty

EXPOSE 21 21100 21110

ENTRYPOINT ["/usr/local/bin/ftp_setup.sh"]
