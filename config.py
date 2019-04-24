class Config(object):
    RESTUFL_JSON = {
        'ensure_ascii': False
    }

class ProdConfig(Config):
    DB_PASS = '.db_pass'

class DevConfig(Config):
    DEBUG = True
    DB_PASS = '.debug_db_pass'