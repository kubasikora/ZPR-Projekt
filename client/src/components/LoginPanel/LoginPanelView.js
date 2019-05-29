import React from "react";
import Card from "react-bootstrap/Card";
import Container from 'react-bootstrap/Container';
import Row from 'react-bootstrap/Row';
import Col from 'react-bootstrap/Col';
import { Redirect } from 'react-router-dom';
import LoginForm from "./LoginForm";


import "./LoginPanel.css"
class LoginPanelView extends React.Component {
  constructor(props) {
    super(props);
  }

  componentDidMount(){
    const buttonId = "login-button";
    document.addEventListener("keyup", event => {
      event.preventDefault();
      if (event.keyCode === 13) {
        document.getElementById(buttonId).click();
      }
    });
  }

  render() {
    const basicAuth = localStorage.getItem('basicAuth');
    if(basicAuth){
      return <Redirect to="/home" />
    }

    let infoText = "";
    if(this.props.error){
      switch(this.props.error.response.status){
        case 401:
          infoText = "Login lub hasło są błędne. Proszę spróbuj ponownie";
          break;
        case 500:
          infoText = "Wystąpił bład serwera. Proszę spróbuje ponownie później";
      }
    }

    return (
      <Container>
        <Row>
          <Col md={2} />
          <Col md={8}>
            <Card style={{ width: "auto", margin: "10rem auto", backgroundColor: "#8093C1" }}>
              <Card.Body>
                <img src="./logo.png" style={{ display: "block", margin: "auto" }} />
                <LoginForm info={infoText} login={(login, password) => this.props.authenticate(login, password)} />
              </Card.Body>
            </Card>

          </Col>
          <Col md={2} />
        </Row>
      </Container>

    );
  }
}

export default LoginPanelView;