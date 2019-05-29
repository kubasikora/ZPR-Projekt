#!/usr/bin/env python
from flask import Flask, Response, request, g, jsonify
from flask_cors import CORS
from config import DevConfig, ProdConfig

from flask_sqlalchemy import SQLAlchemy
from flask_httpauth import HTTPBasicAuth
from passlib.apps import custom_app_context as pwd_context
from itsdangerous import (TimedJSONWebSignatureSerializer as Serializer, BadSignature, SignatureExpired)

from scada import MeasurementController, SerializeDataController, StateController
import os, sys
import json

app = Flask(__name__)
CORS(app)
if len(sys.argv) > 1 and sys.argv[1] == '-d':
    AUTH = False
    Config = DevConfig()
else:
    AUTH = True
    Config = ProdConfig()

app.config.from_object(Config)

db_config = {
    "host": Config.DB_HOST,
    "user": Config.DB_USER,
    "password": Config.DB_PASSWORD,
    "port": Config.DB_PORT
}

DB_URL = 'postgresql+psycopg2://{user}:{pw}@{url}/{db}'.format(user=Config.DB_USER, pw=Config.DB_PASSWORD, url=Config.DB_HOST ,db=Config.DB_USER)

app.config['SECRET_KEY'] = os.environ['SECRET_KEY']
app.config['SQLALCHEMY_DATABASE_URI'] = DB_URL
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)
auth = HTTPBasicAuth()

class User(db.Model):
    __tablename__ = 'users'
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(32), index=True)
    password_hash = db.Column(db.String(64))

    def __repr__(self):
        return "id: {0}, username: {1}, password_hash: {2}".format(self.id, self.username, self.password_hash)

    def hash_password(self, password):
        self.password_hash = pwd_context.encrypt(password)

    def verify_password(self, password):
        return pwd_context.verify(password, self.password_hash)

    def generate_auth_token(self, expiration = 600):
        s = Serializer(app.config['SECRET_KEY'], expires_in = expiration)
        return  s.dumps({ 'id': self.id})

    @staticmethod
    def verify_auth_token(token):
        s = Serializer(app.config['SECRET_KEY'])
        try:
            data = s.loads(token)
        except SignatureExpired:
            return None    # valid token, but expired
        except BadSignature:
            return None    # invalid token
        user = User.query.get(data['id'])
        return user
    
@auth.verify_password
def verify_password(username_or_token, password):
    if not AUTH:
        return True 
    # first try to authenticate by token
    user = User.verify_auth_token(username_or_token)
    if not user:
        # try to authenticate with username/password
        user = User.query.filter_by(username=username_or_token).first()
        if not user or not user.verify_password(password):
            return False
    g.user = user
    return True

@auth.error_handler
def auth_error():
    return "Access Denied"

@app.route('/register', methods=['POST'])
def new_user():
    username = request.form.get('username')
    password = request.form.get('password')
    if username is None or password is None:
         return Response(response="Missing username or password")
    if User.query.filter_by(username = username).first() is not None:
        return Response(response="User already exists")
    user = User(username = username)
    user.hash_password(password)
    db.session.add(user)
    db.session.commit()

    return Response(response="User added", statusCode=201)


@app.route('/login', methods=['GET'])
@auth.login_required
def login():
    return "Logged in"

### resources 

@app.route('/measurement', methods = ['POST'])
@auth.login_required
def measurement():
    controller = MeasurementController(db_config)
    response = controller.postNewMeasurement(request.form)
    statusCode = controller.getStatusCode()
    return Response(response=response, status=statusCode)

@app.route('/getSerializedData', methods = ['GET'])
@auth.login_required
def getSerializedData():
    controller = SerializeDataController(db_config)
    response = json.dumps(controller.getSerializedData(request.args))
    statusCode = controller.getStatusCode()
    return Response(response=response, status=statusCode)

@app.route('/state', methods = ['GET'])
@auth.login_required
def state():
    controller = StateController()
    response = json.dumps(controller.getState())
    statusCode = controller.getStatusCode()
    return Response(response=response, status=statusCode)

if __name__ == '__main__':
    app.run(threaded=True)
