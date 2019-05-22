import React, { Component } from 'react';
import './App.css';
import LoginPanel from "./LoginPanel"
import MeasureGrid from "./MeasureGrid"
import axios from "axios";

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
        <header className="App-header"/>
        <LoginPanel/> 
        <MeasureGrid />
      </div>
    );
  }
}

export default App;
