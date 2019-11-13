from flask import Flask, stream_with_context, Response, render_template
import os
import json
import time
import locale
locale.setlocale(locale.LC_ALL,'zh_CN.UTF-8')

app_dir = "/mapsystem/backend/cpp_backend"
# app_dir = "../cpp_backend/my_cpp_backend"

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
    r = os.popen('{} sample'.format(app_dir))
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

    r = os.popen('{} sort {} {}'.format(app_dir, column, a[order]))
    text = r.read()
    r.close()

    global database
    database = json.loads(text)

    return json.dumps({"result": None})


@app.route('/retrieve/<string:arg1>/<string:arg2>', methods=['GET'])
def retrieve_something(arg1, arg2):
    r = os.popen('{} retrieve {} {}'.format(app_dir, arg1, arg2))
    text = r.read()
    r.close()

    return text


def mysort(col='linkid'):
    N = [10, 100, 500, 1000, 5000, 7000, 9000, 10000, 20000, 30000, 40000, 50000]
    M = ['our', 'stdsort', 'qsort', 'bucketsort', 'heapsort', 'insertsort', 'bubblesort']

    back = [{} for i in range(len(N))]

    for j, method in enumerate(M):
        for i, n in enumerate(N):
            back[i]['n'] = str(n)

            cmd = '{} benchmark {} {} {}'.format(app_dir, method, col, n)
            # print(cmd)
            r = os.popen(cmd)
            text = r.read()
            r.close()

            text = json.loads(text)
            back[i][method] = int(round(text["time"]))
            if int(round(text["time"])) < 20 * 1000:
                time.sleep(0.15)

            yield json.dumps({"result": back})


@app.route('/sort/<string:col>', methods=['GET'])
def sort(col):
    global generator_obj
    generator_obj = mysort(col)
    return ""


@app.route('/sort/next', methods=['GET'])
def sort_next():
    return next(generator_obj)


def get_list():
    r = os.popen('{} list'.format(app_dir))
    text = r.read()
    r.close()
    return text


def refresh():
    global database
    database = json.loads(get_list())


if __name__ == '__main__':
    refresh()
    app.run(host='127.0.0.1', port=5000)
