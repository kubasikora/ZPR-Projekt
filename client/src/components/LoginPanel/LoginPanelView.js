import React from "react"
import Form from "react-bootstrap/Form"
import Button from "react-bootstrap/Button"

//import "./LoginPanel.css"
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
      <Form className="login-form">
        <Form.Group controlId="formBasicEmail">
          <Form.Label>Email address</Form.Label>
          <Form.Control type="email" placeholder="Enter email" />
          <Form.Text className="text-muted">
            We'll never share your email with anyone else.
          </Form.Text>
        </Form.Group>

        <Form.Group controlId="formBasicPassword">
          <Form.Label>Password</Form.Label>
          <Form.Control type="password" placeholder="Password" />
        </Form.Group>
        <Form.Group controlId="formBasicChecbox">
          <Form.Check type="checkbox" label="Check me out" />
        </Form.Group>
        <Button variant="primary" type="submit">
          Submit
        </Button>
      </Form>
    );

    {/*<Form>
            <Form.Group className="login-form" controlId="formLogin" >
              <Form.Label className = "login-label">Login</Form.Label>
              <Form.Control className = "login-control" type="login" placeholder="Enter login" onChange={this.changeLogin} />
            </Form.Group>
          
            <Form.Group className="password-form"controlId="formBasicPassword">
              <Form.Label className = "password-label" >Password</Form.Label>
              <Form.Control className = "password-control" type="password" placeholder="Password" onChange={this.changePassword}/>
            </Form.Group>
            <Button className = "logger-button" variant="primary" type="submit" onClick={this.onButtonClick}>
              Submit
            </Button>
    </Form>*/}
  }

}


export default LoginPanelView;