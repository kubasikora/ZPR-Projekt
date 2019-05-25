import React from "react";
import Card from "react-bootstrap/Card";
import Container from 'react-bootstrap/Container';
import Row from 'react-bootstrap/Row';
import Col from 'react-bootstrap/Col';


import LoginForm from "./LoginForm";


import "./LoginPanel.css"
class LoginPanelView extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      login: "",
      password: ""
    }
    this.changeLogin = this.changeLogin.bind(this);
    this.changePassword = this.changePassword.bind(this);
    this.onButtonClick = this.onButtonClick.bind(this);
  }

  changeLogin(e) {
    this.setState({ login: e.target.value })

  }
  changePassword(e) {
    this.setState({ password: e.target.value })

  }

  onButtonClick(e) {
    e.preventDefault();
    this.props.onClick(this.state.login, this.state.password);

  }
  render() {
    return (
      <Container>
        <Row>
          <Col md={2} />
          <Col md={8}>
            <Card style={{ width: "auto", margin: "10rem auto", backgroundColor: "#8093C1" }}>
              <Card.Body>
                <img src="./logo.png" style={{display: "block", margin: "auto"}} />
                <LoginForm />
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