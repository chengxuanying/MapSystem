FROM ubuntu
WORKDIR /mapsystem/backend

COPY . /mapsystem

RUN apt-get install -y cmake build-essential
RUN cd /mapsystem/cpp_backend && cmake CMakeLists.txt && make
RUN cp /mapsystem/cpp_backend/cpp_backend /mapsystem/backend/

RUN apt-get update && apt-get install -y python3 python3-pip
RUN pip3 install flask

EXPOSE 5000
CMD ["bash", "first.sh"]
