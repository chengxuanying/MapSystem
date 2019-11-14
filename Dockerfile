FROM ubuntu

WORKDIR /mapsystem/backend

COPY . /mapsystem
RUN cp /mapsystem/cpp_backend/ubuntu_cpp_backend /mapsystem/backend/

RUN apt-get update && apt-get install -y locales
RUN locale-gen zh_CN.UTF-8  
ENV LANG zh_CN.UTF-8
ENV LANGUAGE zh_CN.UTF-8
ENV LC_ALL zh_CN.UTF-8

RUN apt-get install -y python3 python3-pip
RUN pip3 install flask

EXPOSE 5000
CMD ["python3", "app.py"]
