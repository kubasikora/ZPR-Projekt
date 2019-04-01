import pytest
from scada import MeasurementController

def test_creates_measurement_controller():
    db = {
        "host": "localhost",
        "user": "test",
        "password": "test",
        "port": "1111"
    }
    controller = MeasurementController(db)
    assert controller

def test_throws_when_creating_controller_without_db():
    with pytest.raises(Exception):
        controller = MeasurementController()

