import React from "react";
import Form from "react-bootstrap/Form";
import Button from "react-bootstrap/Button";

const LoginForm = props => {
    return (
        <Form className="login-form">
            <Form.Group controlId="formBasicEmail">
                <Form.Label style={{fontWeight: "bold"}}>Login</Form.Label>
                <Form.Control type="email" placeholder="Enter login" />
                <Form.Text className="text-muted">
                    {props.info}
                </Form.Text>
            </Form.Group>

            <Form.Group controlId="formBasicPassword">
                <Form.Label style={{fontWeight: "bold"}}>Password</Form.Label>
                <Form.Control type="password" placeholder="Password" />
            </Form.Group>
            <Button variant="primary" type="submit" style={{backgroundColor: "#2DC5C9", color: "black", fontWeight: "bold"}}>
                Submit
            </Button>
        </Form>)
};

export default LoginForm;