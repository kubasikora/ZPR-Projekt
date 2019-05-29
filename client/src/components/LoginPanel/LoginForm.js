import React from "react";
import Form from "react-bootstrap/Form";
import Button from "react-bootstrap/Button";

const LoginForm = props => {
    return (
        <Form className="login-form">
            <Form.Group controlId="formBasicEmail">
                <Form.Label style={{fontWeight: "bold", display: "block", textAlign: "center"}}>Login</Form.Label>
                <Form.Control id="login-form" type="login" placeholder="Wprowadź login" />
                <Form.Text style={{marginLeft: "1vw", color: "#ff0000"}}>
                    {props.info}
                </Form.Text>
            </Form.Group>

            <Form.Group controlId="formBasicPassword">
                <Form.Label style={{fontWeight: "bold", display: "block", textAlign: "center"}}>Hasło</Form.Label>
                <Form.Control id="password-form" type="password" placeholder="Hasło" />
            </Form.Group>
            <Button variant="primary" 
                    style={{backgroundColor: "#2DC5C9", width: "5rem", display: "block", margin: "auto", color: "black", fontWeight: "bold"}}
                    onClick={() => {
                        const login = document.getElementById("login-form").value;
                        const password = document.getElementById("password-form").value;
                        console.log(login + ":" + password);
                        props.login(login, password)}}>
                Zaloguj
            </Button>
        </Form>)
};

export default LoginForm;