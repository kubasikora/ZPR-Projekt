import pytest
from scada import MeasurementController

db = {
        "host": "localhost",
        "user": "zpr",
        "password": "zpr",
        "port": "5432"
}

TEAPOT_CODE = 418
CREATED_CODE = 201
ERROR_CODE = 400

valid_request_form = {
	"deviceId": "1",
	"value": "34.5"
}

missing_deviceId_request_form = {
	"value": "34.5"
}

missing_value_request_form = {
	"deviceId": "1"
}

invalid_deviceId_request_form = {
	"deviceId": "AAA",
	"value": "34.5"
}

invalid_value_request_form = {
	"deviceId": "1",
	"value": "AAA"
}

empty_request_form = {}

def test_creates_measurement_controller():
    controller = MeasurementController(db)
    assert controller

def test_throws_when_creating_controller_without_db():
    with pytest.raises(Exception):
    	controller = MeasurementController()

def test_exposes_handler_method():
    assert hasattr(MeasurementController, "postNewMeasurement")
    
def test_exposes_status_code_method():
    assert hasattr(MeasurementController, "getStatusCode")

def test_handler_is_a_teapot_before_handling_request():
    controller = MeasurementController(db)
    assert controller.getStatusCode() == TEAPOT_CODE

def test_returns_OK_after_valid_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(valid_request_form)
    assert response == "OK"

def test_returns_200_after_valid_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(valid_request_form)
    assert controller.getStatusCode() == CREATED_CODE

def test_returns_error_msg_after_missing_deviceId_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(missing_deviceId_request_form)
    assert response == "Missing key deviceId"

def test_returns_400_after_missing_deviceId_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(missing_deviceId_request_form)
    assert controller.getStatusCode() == ERROR_CODE
	
def test_returns_error_msg_after_missing_value_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(missing_value_request_form)
    assert response == "Missing key value"

def test_returns_400_after_missing_value_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(missing_value_request_form)
    assert controller.getStatusCode() == ERROR_CODE
	
def test_returns_error_msg_after_invalid_deviceId_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(invalid_deviceId_request_form)
    assert response == "Invalid key"

def test_returns_400_after_minvalid_deviceId_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(invalid_deviceId_request_form)
    assert controller.getStatusCode() == ERROR_CODE
	
def test_returns_error_msg_after_invalid_value_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(invalid_value_request_form)
    assert response == "Invalid key"

def test_returns_400_after_invalid_value_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(invalid_value_request_form)
    assert controller.getStatusCode() == ERROR_CODE
	
def test_returns_error_msg_after_empty_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(empty_request_form)
    assert response != "OK"

def test_returns_400_after_empty_data_insert():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(empty_request_form)
    assert controller.getStatusCode() == ERROR_CODE