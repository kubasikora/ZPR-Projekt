
import axios from 'axios'
import endpoint from "../index";

import loginStart from "./loginError";
import loginOK from "./loginOK";
import loginError from "./loginError";

const authenticate = (login, password) => {
	return dispatch => {
		dispatch(loginStart());
		const basicAuth = 'Basic ' + btoa(login + ":" + password);
		axios.get(`${endpoint}/login`, {
			headers: {
					'Authorization': basicAuth
			}
        })
		.then(response => {
			localStorage.setItem('basicAuth', basicAuth);
			localStorage.setItem('username', login);
			window.location = '/home';
			dispatch(loginOK(response));
		})
		.catch(error => dispatch(loginError(error)))	
	}
}

export default authenticate;