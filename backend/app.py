from flask import Flask, send_from_directory
import os
import json

app = Flask(__name__,
            static_url_path="",
            static_folder="dist")

# 跨域支持
def after_request(resp):
    resp.headers['Access-Control-Allow-Origin'] = '*'
    return resp

app.after_request(after_request)
database = None



@app.route('/retrieve/test', methods=['GET'])
def test():
    r = os.popen('./test/cpp_backend sample')
    text = r.read()
    r.close()
    return text


@app.route('/retrieve/tot', methods=['GET'])
def get_tot():
    return json.dumps({"tot": database['cnt']})


@app.route('/retrieve/page_size/<int:page_size>/page/<int:page>', methods=['GET'])
def get_page(page_size, page):
    start = (page - 1 ) * page_size
    end = page * page_size
    return json.dumps({"result": database['result'][start: end]})


def get_list():
    r = os.popen('./test/cpp_backend list')
    text = r.read()
    r.close()
    return text


def refresh():
    global database
    database = json.loads(get_list())


if __name__ == '__main__':
    refresh()
    app.run()
