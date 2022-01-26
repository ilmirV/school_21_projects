FROM alpine:3.12

RUN	apk update && \
	apk add grafana --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted

COPY custom.ini /usr/share/grafana/conf/
COPY influxdb.yaml /usr/share/grafana/conf/provisioning/datasources/
COPY dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/

COPY dashboard.json /var/lib/grafana/dashboards/

EXPOSE 3000

CMD ["/usr/sbin/grafana-server", "--homepath=/usr/share/grafana"]
