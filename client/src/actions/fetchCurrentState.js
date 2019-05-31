import axios from 'axios'
import endpoint from "../index";

import fetchCurrentStateStart from "./fetchCurrentStateStart";
import fetchCurrentStateOK from "./fetchCurrentStateOK";
import fetchCurrentStateError from "./fetchCurrentStateError";

const fetchCurrentState = () => {
	return dispatch => {
        dispatch(fetchCurrentStateStart());
        const basicAuth = localStorage.getItem('basicAuth');
		axios.get(`${endpoint}/state`, {
			headers: {
                'Access-Control-Allow-Origin': '*',
				'Authorization': basicAuth
			}
        })
		.then(response => {
			dispatch(fetchCurrentStateOK(response));
		})
		.catch(error => dispatch(fetchCurrentStateError(error)))	
	}
}

export default fetchCurrentState;