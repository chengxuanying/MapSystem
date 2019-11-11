from flask import Flask, send_from_directory

app = Flask(__name__,
            static_url_path="",
            static_folder="dist")


if __name__ == '__main__':
    app.run()
