FROM alpine:3.12

RUN	apk update && \
	apk add wget openrc && \
	wget https://dl.influxdata.com/telegraf/releases/telegraf-1.17.3_linux_amd64.tar.gz \
		https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk && \
	tar -xzvf telegraf-1.17.3_linux_amd64.tar.gz && \
	cp -r /telegraf-1.17.3/* . && \
	rm -rf telegraf-1.17.3_linux_amd64.tar.gz telegraf-1.17.3 && \
	apk add glibc-2.28-r0.apk --allow-untrusted && \
	telegraf -sample-config telegraf.conf --input-filter cpu:mem --output-filter influxdb > telegraf.conf

COPY telegraf.conf /etc/telegraf/

CMD ["telegraf"]
