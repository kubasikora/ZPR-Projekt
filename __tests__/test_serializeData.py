import pytest, os
from scada import SerializeDataController, MeasurementController

db = {
    "host": os.environ['DEBUG_DB_HOST'],
    "user": os.environ['DEBUG_DB_USER'],
    "password": os.environ['DEBUG_DB_PASSWORD'],
    "port": os.environ['DEBUG_DB_PORT']
}

TEAPOT_CODE = 400
OK_CODE = 201

def test_creates_serialize_data_controller():
    controller = SerializeDataController(db)
    assert controller

def test_exposes_handler_method():
    assert hasattr(SerializeDataController, "getSerializedData")



def test_handler_is_a_teapot_before_handling_request():
    controller = SerializeDataController(db)
    assert controller.getStatusCode() == TEAPOT_CODE