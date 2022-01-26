#!/bin/bash
minikube start --driver=virtualbox

minikube addons enable metallb
minikube addons enable dashboard
minikube addons enable metrics-server

eval $(minikube docker-env)

docker pull metallb/speaker:v0.8.2
docker pull metallb/controller:v0.8.2
docker pull kubernetesui/dashboard:v2.1.0
docker pull kubernetesui/metrics-scraper:v1.0.4

kubectl apply -f srcs/yaml/configmap.yaml
docker build -t nginx-img srcs/nginx/
kubectl apply -f srcs/yaml/nginx.yaml
docker build -t wordpress-img srcs/wordpress/
kubectl apply -f srcs/yaml/wordpress.yaml
docker build -t phpmyadmin-img srcs/phpmyadmin/
kubectl apply -f srcs/yaml/phpmyadmin.yaml
docker build -t mysql-img srcs/mysql/
kubectl apply -f srcs/yaml/mysql.yaml
docker build -t ftps-img srcs/ftps/
kubectl apply -f srcs/yaml/ftps.yaml
docker build -t telegraf-img srcs/telegraf/
kubectl apply -f srcs/yaml/telegraf.yaml
docker build -t influxdb-img srcs/influxdb/
kubectl apply -f srcs/yaml/influxdb.yaml
docker build -t grafana-img srcs/grafana/
kubectl apply -f srcs/yaml/grafana.yaml
