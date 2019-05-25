import React, { Component } from 'react';
import './App.css';
import LoginPanel from "./LoginPanel"
import MeasureGrid from "./MeasureGrid"
import ParameterPanel from "./ParameterPanel"
import Page404 from "./Page404";
import axios from "axios";
import { BrowserRouter as Router, Route, Link, Redirect, Switch } from "react-router-dom";


const PrivateRoute = ({ component: Component, ...rest}) => {
  let isAuthenticated = true;
  return (
    <Route
      {...rest}
      render={props =>
        isAuthenticated ? (
          <Component {...props} />
        ) : (
          <Redirect to={{pathname: "/", state: {from: props.location }}} />
        )} 
      />
  )
}


class App extends Component {

  componentDidMount(){
    axios.get(`http://localhost:5000/login`, {
       auth: {
        username: 'admin',
        password: 'admin'
       }
    })
			.then(response => console.log(response))
			.catch(error => console.log(error))	
  }

  render() {
    return (
      <div className="App">
        <Router>  
            <Switch>
            <Route path="/" exact component={LoginPanel} />
            <PrivateRoute path="/home" exact component={MeasureGrid} />
            <PrivateRoute path="/figures" exact component={ParameterPanel} />
            <Route component={Page404} />
          </Switch>
        </Router>
      </div>
    );
  }
}

export default App;
