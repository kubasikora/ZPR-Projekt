import pytest, os
from scada import SerializeDataController, MeasurementController

db = {
    "host": os.environ['DEBUG_DB_HOST'],
    "user": os.environ['DEBUG_DB_USER'],
    "password": os.environ['DEBUG_DB_PASSWORD'],
    "port": os.environ['DEBUG_DB_PORT']
}
valid_request_form = {
    "deviceId": "1",
    "startTime": "2019-May-10 23:59:00",
    "stopTime": "2019-May-20 23:59:00"

}
TEAPOT_CODE = 418
OK_CODE = 201

def test_creates_serialize_data_controller():
    controller = SerializeDataController(db)
    assert controller

def test_exposes_handler_method():
    assert hasattr(SerializeDataController, "getSerializedData")

def test_handler_is_a_teapot_before_handling_request():
    controller = SerializeDataController(db)
    assert controller.getStatusCode() == TEAPOT_CODE

def test_getting_data():
    controller = SerializeDataController(db)
    response = controller.getSerializedData(valid_request_form)
    print(response)