class Config(object):
    RESTUFL_JSON = {
        'ensure_ascii': False
    }

class ProdConfig(object):
    DB_PASS = '.db_pass'

class DevConfig(object):
    DEBUG = True
    DB_PASS = '.debug_db_pass'