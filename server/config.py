"""
Moduł konfiguracji aplikacji. Określa sposób w jaki działa
serwer aplikacji. Klasy ProdConfig i DevConfig pobierają ze zmiennych 
środowiskowych inforamcję na temat bazy danych.
"""

import os

class Config(object):
    """
    Bazowa klasa konfiguracji serwera aplikacji
    """
    RESTFUL_JSON = {
        'ensure_ascii': False
    }


class ProdConfig(Config):
    """
    Produkcyjna klasa konfiguracji serwera aplikacji
    """
    DB_HOST = os.environ['PROD_DB_HOST']
    DB_USER = os.environ['PROD_DB_USER']
    DB_PASSWORD = os.environ['PROD_DB_PASSWORD']
    DB_PORT = os.environ['PROD_DB_PORT']


class DevConfig(Config):
    """
    Deweloperska klasa konfiguracji serwera aplikacji
    """
    DEBUG = True
    DB_HOST = os.environ['DEBUG_DB_HOST']
    DB_USER = os.environ['DEBUG_DB_USER']
    DB_PASSWORD = os.environ['DEBUG_DB_PASSWORD']
    DB_PORT = os.environ['DEBUG_DB_PORT']