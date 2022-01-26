#!/bin/sh

openrc boot
/etc/init.d/mariadb setup
rc-service mariadb start
mysql -u root mysql < create_base
mysql -u root wordpress < wordpress.sql
rc-service mariadb stop
mysqld -uroot
