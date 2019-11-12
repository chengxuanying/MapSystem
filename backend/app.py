from flask import Flask, send_from_directory
import os
app = Flask(__name__,
            static_url_path="",
            static_folder="dist")
# 跨域支持
def after_request(resp):
    resp.headers['Access-Control-Allow-Origin'] = '*'
    return resp

app.after_request(after_request)


@app.route('/retrieve/test', methods=['GET'])
def test():
    r = os.popen('./test/cpp_backend sample')
    text = r.read()
    r.close()
    print(text)
    return text
    

if __name__ == '__main__':
    app.run()
