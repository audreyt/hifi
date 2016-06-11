FROM ubuntu:14.04

RUN apt-get install -y software-properties-common
RUN add-apt-repository "deb http://debian.highfidelity.com stable main"
RUN apt-get update
RUN apt-get install -y hifi-qt hifi-domain-server hifi-assignment-client
RUN apt-get clean

# Work in progress
