service mysql start
mysql -u root -e "CREATE DATABASE $MYSQL_DATABASE;"
mysql -u root -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'"
mysql -u root -e "use $MYSQL_DATABASE;GRANT ALL PRIVILEGES ON * TO '$MYSQL_USER'@'%' WITH GRANT OPTION;"
mysql -u root $MYSQL_DATABASE < wpdb.sql
mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '123';FLUSH PRIVILEGES;"
service mysql stop
mv -f /var/lib/mysql/* /files
