import pytest, os
from scada import StateController, MeasurementController

db = {
    "host": os.environ['DEBUG_DB_HOST'],
    "user": os.environ['DEBUG_DB_USER'],
    "password": os.environ['DEBUG_DB_PASSWORD'],
    "port": os.environ['DEBUG_DB_PORT']
}

TEAPOT_CODE = 418
OK_CODE = 200

def insert_new_measurement(deviceId, value):
    request = {
        "deviceId": str(deviceId),
        "value": str(value)
    }
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(request)


def test_creates_state_controller():
    controller = StateController()
    assert controller

def test_exposes_handler_method():
    assert hasattr(StateController, "getState")

def test_exposes_handler_method():
    assert hasattr(StateController, "getStatusCode")

def test_handler_is_a_teapot_before_handling_request():
    controller = StateController()
    assert controller.getStatusCode() == TEAPOT_CODE

def test_adds_new_value_to_state():
    first_measurement = {
        "deviceId": 1,
        "value": 34.5
    }
    controller = StateController()
    response = controller.getState()
    insert_new_measurement(first_measurement["deviceId"], first_measurement["value"])
    assert response[0]["value"] == first_measurement["value"]

def test_overwrites_new_value_in_state():
    first_measurement = {
        "deviceId": 1,
        "value": 34.5
    }
    second_measurement = {
        "deviceId": 1,
        "value": 40
    }
    insert_new_measurement(first_measurement["deviceId"], first_measurement["value"])
    insert_new_measurement(second_measurement["deviceId"], second_measurement["value"])
    controller = StateController()
    response = controller.getState()
    assert response[0]["value"] == second_measurement["value"]

def test_correctly_stores_more_than_one_value():
    first_measurement = {
        "deviceId": 1,
        "value": 34.5
    }
    second_measurement = {
        "deviceId": 2,
        "value": 35
    }
    insert_new_measurement(first_measurement["deviceId"], first_measurement["value"])
    insert_new_measurement(second_measurement["deviceId"], second_measurement["value"])
    controller = StateController()
    response = controller.getState()
    assert response[0]["value"] == first_measurement["value"] and response[1]["value"] == second_measurement["value"]

def test_returns_200_on_correct_get():
    controller = StateController()
    response = controller.getState()
    assert controller.getStatusCode() == OK_CODE