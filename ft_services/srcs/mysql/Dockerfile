FROM alpine:3.12

RUN apk update && \
	apk add mariadb	mariadb-client mysql mysql-client openrc libc6-compat && \
	mkdir -p /var/log/mysql

COPY start.sh  .
COPY wordpress.sql .
COPY my.cnf /etc/
COPY create_base .

RUN chmod -R 755 /start.sh

VOLUME /sys/fs/cgroup
VOLUME ["/var/lib/mysql"]

EXPOSE 3306

CMD ["sh", "start.sh"]
