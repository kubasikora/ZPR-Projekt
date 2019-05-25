import React, { Component } from 'react';
import LoginPanel from "./LoginPanel"
import MeasureGrid from "./MeasureGrid"
import axios from "axios";
import Header from "./Header";
import { BrowserRouter as Router, Switch, Route, Link } from 'react-router-dom';
import Serialization from './Serialization';
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
      <Router>
        <Header />
        <Switch>
              <Route exact path='/' component={LoginPanel} />
              <Route path='/home' component={MeasureGrid} />
              <Route path='/figures' component={Serialization} />
          </Switch>
      </Router>
    );
  }
}

export default App;
