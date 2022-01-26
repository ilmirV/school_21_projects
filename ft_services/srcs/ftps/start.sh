#!/bin/sh
openrc boot
rc-update add vsftpd
rc-service vsftpd start
nc -z 127.0.0.121
addgroup -S ftps_group
adduser -S felisabe -G ftps_group -h /var/www/files
echo "felisabe:felisabe" | chpasswd
chmod -R 777 /var/www
chown -R ftps_usr:ftps_group /var/www
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf
