import os

"""
Bazowa klasa konfiguracji serwera aplikacji
"""
class Config(object):
    RESTFUL_JSON = {
        'ensure_ascii': False
    }

"""
Produkcyjna klasa konfiguracji serwera aplikacji
"""
class ProdConfig(Config):
    DB_HOST = os.environ['PROD_DB_HOST']
    DB_USER = os.environ['PROD_DB_USER']
    DB_PASSWORD = os.environ['PROD_DB_PASSWORD']
    DB_PORT = os.environ['PROD_DB_PORT']

"""
Deweloperska klasa konfiguracji serwera aplikacji
"""
class DevConfig(Config):
    DEBUG = True
    DB_HOST = os.environ['DEBUG_DB_HOST']
    DB_USER = os.environ['DEBUG_DB_USER']
    DB_PASSWORD = os.environ['DEBUG_DB_PASSWORD']
    DB_PORT = os.environ['DEBUG_DB_PORT']