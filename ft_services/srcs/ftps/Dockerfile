FROM alpine:3.12

RUN apk update && \
	apk add openssl openrc vsftpd && \
	mkdir -p /var/log/ftp /var/www/files && \
	touch /var/log/ftp/xferlog && \
	openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
			-out /etc/ssl/felisabe.pem \
			-keyout /etc/ssl/felisabe.key \
			-subj "/C=RU/ST=Tatarstan/L=Kazan/O=21School/OU=Education/CN=localhost"

COPY start.sh .
COPY vsftpd.conf /etc/vsftpd/

RUN chmod 755 start.sh && \
	chmod 777 /etc/vsftpd/vsftpd.conf

EXPOSE 21 21000

CMD ["sh", "start.sh"]
