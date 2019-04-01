import pytest
from scada import MeasurementController

db = {
        "host": "localhost",
        "user": "test",
        "password": "test",
        "port": "1111"
    }

TEAPOT_CODE = 418

def test_creates_measurement_controller():
    controller = MeasurementController(db)
    assert controller

def test_throws_when_creating_controller_without_db():
    with pytest.raises(Exception):
        controller = MeasurementController()

def test_has_handler_method():
    assert hasattr(MeasurementController, "postNewMeasurement")
    
def test_has_status_code_method():
    assert hasattr(MeasurementController, "getStatusCode")

def test_handler_is_a_teapot_before_handling_request():
    controller = MeasurementController(db)
    assert controller.getStatusCode() == TEAPOT_CODE