FROM python:alpine
WORKDIR /mapsystem/backend

COPY . /mapsystem

RUN pip install flask

RUN cd /backend/cpp_backend
RUN make
RUN cp cpp_backend ../backend

EXPOSE 5000
CMD ["bash", "first.sh"]
