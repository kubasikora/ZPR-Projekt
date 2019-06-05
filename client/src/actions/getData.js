import {GET_DATA_START, GET_DATA_OK, GET_DATA_ERROR} from "../actionTypes"
import axios from 'axios';
import endpoint from "../index";

const getData = state => {
  return dispatch => {
      dispatch({type: GET_DATA_START});
      const basicAuth = localStorage.getItem('basicAuth');
      let promises = state.checked.map(element => {
        let args = {
          'startTime': state.startDate,
          'stopTime': state.endDate,
          'deviceId': element
        };
        return axios.get(`${endpoint}/getSerializedData`, 
        {headers: {
            'Access-Control-Allow-Origin': '*',
            'Authorization': basicAuth
          },
            params: args})
      });

      Promise.all(promises).then(responses => {
        responses.forEach(response => dispatch({type: GET_DATA_OK, data: response.data}));
      }).catch(error => dispatch({type: GET_DATA_ERROR}));
      /*
      state.checked.forEach(element => {
        let args = {
          'startTime': state.startDate,
          'stopTime': state.endDate,
          'deviceId': element
        }
        const basicAuth = localStorage.getItem('basicAuth');
        axios.get(`${endpoint}/getSerializedData`, 
        {headers: {
            'Access-Control-Allow-Origin': '*',
            'Authorization': basicAuth
          },
            params: args})
        .then (response => {
          dispatch({type: GET_DATA_OK, data: response.data});
        })
        .catch(error => dispatch({type: GET_DATA_ERROR}))
       })*/
      };
      
}


export default getData;