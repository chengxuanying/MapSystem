import json
import os
import time

from flask import Flask, redirect, send_from_directory, session, request
#from requests import get

cur_id = 1



app = Flask(__name__,
            static_url_path="/dist",
            static_folder="dist")

# 跨域支持
def after_request(resp):
    resp.headers['Access-Control-Allow-Origin'] = '*'
    id_(resp)
    return resp


app.after_request(after_request)

database = None

@app.route('/sessionid', methods=['GET'])
def id_(resp):
    cookie = request.cookies.get('cooid')
    
    if(not cookie):
        global cur_id
        resp.set_cookie('cooid',str(cur_id))
        cur_id+=1

    
@app.route('/', methods=['GET'])
def app_index():
    return redirect('/index.html')

@app.route('/assets/<path:filename>')
def custom_static(filename):
    return send_from_directory('assets',
                               filename)

@app.route('/api/retrieve/test', methods=['GET'])
def test():
    r = os.popen('{} sample'.format(app_dir))
    text = r.read()
    r.close()
    return text


@app.route('/api/retrieve/tot', methods=['GET'])
def get_tot():
    return json.dumps({"tot": database['cnt']})


@app.route('/api/retrieve/page_size/<int:page_size>/page/<int:page>', methods=['GET'])
def get_page(page_size, page):
    start = (page - 1) * page_size
    end = page * page_size
    return json.dumps({"result": database['result'][start: end], "tot": database['cnt']})


@app.route('/api/retrieve/sort/<string:column>/<string:order>', methods=['GET'])
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


@app.route('/api/retrieve/<string:arg1>/<string:arg2>', methods=['GET'])
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

generator_dic ={}


@app.route('/api/sort/<string:col>', methods=['GET'])
def sort(col):
    global generator_dic
    _id = int(request.cookies.get('cooid'))
    print(_id)
    generator_dic[_id] = mysort(col)
    #generator_obj = mysort(col)
    return ""


@app.route('/api/sort/next', methods=['GET'])
def sort_next():
    global generator_dic
    _id = int(request.cookies.get('cooid'))
    print(_id)
    return next(generator_dic[_id])


@app.route('/index.html', methods=['GET'])
def index():
    return app.send_static_file('index.html')


def get_list():
    r = os.popen('{} list'.format(app_dir))
    text = r.read()
    r.close()
    return text


def refresh():
    global database
    database = json.loads(get_list())



if __name__ == '__main__':

    # debug 时候取消这个
    global app_dir
    # app_dir = "../cpp_backend/my_cpp_backend"
    app_dir = "/mapsystem/backend/ubuntu_cpp_backend"

    refresh()
    app.run(host='0.0.0.0', port=5000)
