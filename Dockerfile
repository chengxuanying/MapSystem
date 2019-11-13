FROM ubuntu
WORKDIR /mapsystem/backend

COPY . /mapsystem

RUN apt-get update && apt-get install -y python3 python3-pip
RUN pip3 install flask


RUN apt-get install -y cmake build-essential
RUN cd /mapsystem/cpp_backend
RUN cmake CMakeLists.txt
RUN make
RUN cp cpp_backend ../backend

EXPOSE 5000
CMD ["bash", "first.sh"]
