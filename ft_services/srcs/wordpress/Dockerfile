FROM alpine:3.12

RUN apk update && \
	apk add wget nginx openssl supervisor php7 php7-session php7-json php7-gd \
			php7-curl php7-mysqli php7-fpm php7-opcache php7-zlib php7-mbstring && \
	mkdir -p /run/nginx /run/php /run/log/php-fpm && \
	wget https://wordpress.org/latest.tar.gz && \
	tar -xzvf latest.tar.gz -C /var/www/ && \
	rm latest.tar.gz

COPY nginx.conf /etc/nginx/
COPY supervisord.conf /etc/
COPY wp-config.php /var/www/wordpress/

EXPOSE 5050

CMD ["usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
