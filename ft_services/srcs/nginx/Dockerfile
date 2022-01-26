FROM alpine:3.12

RUN apk update && \
	apk add nginx openssl openssh supervisor && \
	mkdir -p /run/nginx && \
	openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
			-out /etc/ssl/felisabe.crt \
			-keyout /etc/ssl/felisabe.key \
			-subj "/C=RU/ST=Tatarstan/L=Kazan/O=21School/OU=Education/CN=localhost" && \
	ssh-keygen -A && \
	adduser -D felisabe && \
	echo "felisabe:felisabe" | chpasswd

COPY nginx.conf /etc/nginx/
COPY supervisord.conf /etc/

EXPOSE 22 80 443

CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
