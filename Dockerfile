FROM python:3.5.9-alpine

WORKDIR /mapsystem/backend

COPY . /mapsystem


RUN cp /mapsystem/cpp_backend/ubuntu_cpp_backend /mapsystem/backend/cpp_backend
RUN "/mapsystem/backend/cpp_backend"

RUN pip3 install flask

EXPOSE 5000
CMD ["python3", "app.py"]
