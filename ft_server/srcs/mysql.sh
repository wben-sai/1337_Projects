service php7.3-fpm start
chown -R mysql: /var/lib/mysql
service mysql start
mysql -u root -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'root';"
mysql -u root -e "CREATE DATABASE wpdb; use wpdb; source /wpdb.sql;"
mysql -u root -e "GRANT ALL ON *.* TO 'admin'@'localhost'; FLUSH PRIVILEGES;"
service nginx start
