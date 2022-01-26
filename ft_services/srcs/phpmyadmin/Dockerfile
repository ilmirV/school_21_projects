FROM alpine:3.12

RUN apk update && \
	apk add wget nginx openssl supervisor php7 php7-fpm php7-opcache php7-gd \
			php7-mysqli php7-zlib php7-curl php7-mbstring php7-json \
			php7-session && \
	mkdir -p /run/nginx /run/php /var/log/php-fpm && \
	wget https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-all-languages.tar.gz && \
	tar -xzvf phpMyAdmin-4.9.2-all-languages.tar.gz && \
	mv phpMyAdmin-4.9.2-all-languages /var/www/phpmyadmin && \
	rm phpMyAdmin-4.9.2-all-languages.tar.gz 

COPY nginx.conf /etc/nginx/
COPY supervisord.conf /etc/
COPY config.inc.php /var/www/phpmyadmin/

EXPOSE 5000

CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
