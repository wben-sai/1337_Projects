FROM debian:buster
ARG MYSQL_DATABASE
ENV MYSQL_DATABASE=${MYSQL_DATABASE}
ARG MYSQL_PASSWORD
ENV MYSQL_PASSWORD=${MYSQL_PASSWORD}
ARG MYSQL_USER
ENV MYSQL_USER=${MYSQL_USER}
RUN apt update
RUN mkdir -p files
RUN apt -y upgrade
RUN apt -y install mariadb-server
COPY tools/mariadb.sh /
COPY tools/start.sh /
COPY tools/wpdb.sql /
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d
RUN sh ./mariadb.sh
CMD sh ./start.sh