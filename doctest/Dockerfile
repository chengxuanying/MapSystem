FROM python:alpine
WORKDIR /backend
COPY . /backend
RUN pip install --trusted-host pypi.mirrors.ustc.edu.cn/simple/ -r requirements.txt
EXPOSE 8010
CMD ["python", "app.py"]
