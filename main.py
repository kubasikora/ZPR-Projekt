from flask import Flask, Response
from config import DevConfig, ProdConfig
from scada import scada

app = Flask(__name__)
app.config.from_object(DevConfig)

@app.route('/')
def home():
    return Response(scada.getData())

if __name__ == '__main__':
    app.run()
