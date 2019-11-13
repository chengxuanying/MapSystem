FROM ubuntu:16.04
WORKDIR /mapsystem/backend

COPY . /mapsystem

RUN apt-get update && apt-get install -y python python-dev python3.5 python3.5-dev python-pip virtualenv libssl-dev libpq-dev git build-essential libfontconfig1 libfontconfig1-dev
RUN pip install flask

RUN cd /mapsystem/cpp_backend
RUN make
RUN cp cpp_backend ../backend

EXPOSE 5000
CMD ["bash", "first.sh"]
