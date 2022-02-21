[ "$(ls -A /var/www/html/)" ] && echo "Not Empty" || mv /wordpress/* /var/www/html/
/usr/sbin/php-fpm7.3 --nodaemonize