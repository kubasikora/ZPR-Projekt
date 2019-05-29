import {GET_DATA_START, GET_DATA_OK, GET_DATA_ERROR} from "../actionTypes"
import axios from 'axios';
import endpoint from "../index";

function getData (state) {
 
   return async dispatch =>{
    try{
      dispatch({type: GET_DATA_START});
      let args = {
        'startTime': state.startDate,
        'stopTime': state.endDate,
        'deviceId': state.checked[0]
      }
      let response = axios.get(`${endpoint}/getSerializedData`, {params: args});
      dispatch({type: GET_DATA_OK})

    
  }catch(err){
    console.log(err)
    dispatch({type: GET_DATA_ERROR})
  }
 }
}


export default getData;