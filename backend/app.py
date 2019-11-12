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
    start = (page - 1) * page_size
    end = page * page_size
    return json.dumps({"result": database['result'][start: end], "tot": database['cnt']})


@app.route('/retrieve/sort/<string:column>/<string:order>', methods=['GET'])
def sort_page(column, order):
    if order == 'null':
        refresh()
        return json.dumps({"result": None})

    a = {
        'ascending': 'up',
        'descending': 'down',
    }

    r = os.popen('./test/cpp_backend sort {} {}'.format(column, a[order]))
    text = r.read()
    r.close()

    global database
    database = json.loads(text)

    return json.dumps({"result": None})


@app.route('/retrieve/<string:arg1>/<string:arg2>', methods=['GET'])
def retrieve_something(arg1, arg2):
    r = os.popen('./test/cpp_backend retrieve {} {}'.format(arg1, arg2))
    text = r.read()
    r.close()

    return text


@app.route('/sort', methods=['GET'])
def sort():
    # r = os.popen('./test/cpp_backend sort'.format(arg1, arg2))
    # text = r.read()
    # r.close()
    text = [
        {'数据量': '10', '冒泡排序': 1393, '插入排序': 1093},
        {'数据量': '100', '冒泡排序': 3530, '插入排序': 3230},
        {'数据量': '1000', '冒泡排序': 2923, '插入排序': 2623},
        {'数据量': '10000', '冒泡排序': 1723, '插入排序': 1423},
        {'数据量': '20000', '冒泡排序': 3792, '插入排序': 3492},
        {'数据量': '50000', '冒泡排序': 4593, '插入排序': 4293}
    ]
    return json.dumps({"result": text})


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
