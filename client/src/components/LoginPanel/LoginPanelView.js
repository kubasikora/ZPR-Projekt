import React from "react"
import Form from "react-bootstrap/Form"
import Button from "react-bootstrap/Button"

class LoginPanelView extends React.Component {
    constructor(props) {
      super(props);
      this.state = {
          login:"",
          password : ""
      }
      this.changeLogin= this.changeLogin.bind(this);
      this.changePassword= this.changePassword.bind(this);
      this.onButtonClick= this.onButtonClick.bind(this);
    }

    changeLogin(e){
        this.setState({login: e.target.value})

    }
    changePassword(e){
        this.setState({password: e.target.value})

    }

    onButtonClick(e){
        e.preventDefault();
        this.props.onClick(this.state.login, this.state.password);

    }
    render() {
        console.log(this.state);
        
        return (
            <Form>
            <Form.Group controlId="formLogin">
              <Form.Label>Login</Form.Label>
              <Form.Control type="login" placeholder="Enter login" onChange={this.changeLogin} />
            </Form.Group>
          
            <Form.Group controlId="formBasicPassword">
              <Form.Label>Password</Form.Label>
              <Form.Control type="password" placeholder="Password" onChange={this.changePassword}/>
            </Form.Group>
            <Button variant="primary" type="submit" onClick={this.onButtonClick}>
              Submit
            </Button>
          </Form>
        );
      }
    
  }


export default LoginPanelView;