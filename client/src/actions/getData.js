import {GET_DATA_START, GET_DATA_OK, GET_DATA_ERROR} from "../actionTypes"
import axios from 'axios';
function getData (state) {
   return async dispatch =>{
    try{
      dispatch({type: GET_DATA_START});
      let args = {
        'startTime': state.startTime,
        'stopTime': state.stopTime,
        'deviceId': state.deviceId
      }
      let response = await(()=>axios.get("http://127.0.0.1:5000/getSerializedData", {args}));
      console.log(response)
      dispatch({type: GET_DATA_OK})
      console.log(response)
    
  }catch(err){
    console.log(err)
    dispatch({type: GET_DATA_ERROR})
  }
 }
}


export default getData;