FROM ubuntu
WORKDIR /mapsystem/backend

COPY . /mapsystem

RUN apt-get update && apt-get install -y wget cmake build-essential
RUN mkdir -p /application/tools && cd /application/tools && wget -c https://ftp.gnu.org/pub/gnu/libiconv/libiconv-1.15.tar.gz && tar -zxvf libiconv-1.15.tar.gz -C /usr/local && cd /usr/local/libiconv-1.15 && ./configure --prefix=/usr/local/libiconv-1.15 && make && make install && ln -s /usr/local/libiconv-1.15/lib/libiconv.so.2.6.0 /usr/lib/libiconv.so

RUN cd /mapsystem/cpp_backend && cmake CMakeLists.txt && make
RUN cp /mapsystem/cpp_backend/cpp_backend /mapsystem/backend/
RUN "/mapsystem/backend/cpp_backend"

RUN apt-get install -y python3 python3-pip
RUN pip3 install flask


EXPOSE 5000
CMD ["python3", "app.py"]
