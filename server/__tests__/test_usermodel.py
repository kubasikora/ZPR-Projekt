import pytest, os
from main import User

def test_creates_user_mapper():
    user = User()
    assert user

def test_stores_password_correctly():
    user = User()
    user.hash_password("password")
    assert user.verify_password("password")

def test_throws_exception_when_generating_token_without_id():
    user = User()
    user.username = "operator"
    with pytest.raises(Exception):
        token = user.generate_auth_token()

def test_throws_exception_when_generating_token_without_username():
    user = User()
    user.id = 1
    with pytest.raises(Exception):
        token = user.generate_auth_token()

def test_generates_valid_token():
    user = User()
    user.id = 1
    user.username = "operator"
    assert user.generate_auth_token()