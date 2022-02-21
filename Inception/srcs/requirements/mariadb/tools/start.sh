[ "$(ls -A /var/lib/mysql/)" ] && echo "Not Empty" || mv /files/* /var/lib/mysql/
mysqld_safe 