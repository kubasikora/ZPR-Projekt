import React, { Component } from 'react';
import LoginPanel from "./LoginPanel"
import MeasureGrid from "./MeasureGrid"
import Serialization from './Serialization';
import Page404 from "./Page404";
import axios from "axios";
import { BrowserRouter as Router, Route, Link, Redirect, Switch } from "react-router-dom";

class App extends Component {
  render() {
    return (
      <div className="App">
        <Router>  
            <Switch>
            <Route path="/" exact component={LoginPanel} />
            <Route path="/home" exact component={MeasureGrid} />
            <Route path="/figures" exact component={Serialization} />
            <Route component={Page404} />
          </Switch>
        </Router>
      </div>
    );
  }
}

export default App;
