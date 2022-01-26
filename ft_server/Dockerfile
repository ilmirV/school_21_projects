FROM debian:buster

RUN apt update
RUN apt install -y	wget \
					nginx \
					mariadb-server \
					openssl \
					php-fpm \
					php-mysql \
					php-mbstring

RUN wget https://wordpress.org/latest.tar.gz && \
	tar zxvf latest.tar.gz && \
	rm latest.tar.gz && \
	mv /wordpress /var/www/html

COPY srcs/wp-config.php /var/www/html/wordpress/

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz && \
	tar zxvf phpMyAdmin-5.0.4-english.tar.gz && \
	rm phpMyAdmin-5.0.4-english.tar.gz && \
	mv phpMyAdmin-5.0.4-english /var/www/html/phpmyadmin

COPY srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 \
				-x509 \
				-sha256 \
				-days 365 \
				-nodes \
				-out /etc/nginx/ssl/felisabe.crt \
				-keyout /etc/nginx/ssl/felisabe.key \
				-subj "/C=RU/ST=Tatarstan/L=Kazan/O=21School/OU=Education/CN=localhost"

COPY srcs/nginx-config /etc/nginx/sites-available/
RUN rm /etc/nginx/sites-enabled/default && \
	ln -s /etc/nginx/sites-available/nginx-config /etc/nginx/sites-enabled/

RUN chown -R www-data:www-data /var/www
RUN service mysql start && \
	mysql --execute="CREATE DATABASE wordpress; \
					CREATE USER 'felisabe'@'localhost' IDENTIFIED BY '4815162342'; \
					GRANT ALL PRIVILEGES ON wordpress.* TO 'felisabe'@'localhost'; \
					FLUSH PRIVILEGES;"

EXPOSE 80 443

CMD service php7.3-fpm start && \
	service mysql start && \
	service nginx start && \
	bash
