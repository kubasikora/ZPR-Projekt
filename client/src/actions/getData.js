import {GET_DATA_START, GET_DATA_OK, GET_DATA_ERROR} from "../actionTypes"
import axios from 'axios';
 const getData =(state) =>{
   return async dispatch =>{
    try{
      dispatch({type: GET_DATA_START});
      let params = {
        'startTime': state.startTime,
        'stopTime': state.stopTime,
        'deviceId': state.deviceId
      }
      let response = await(()=>axios.get("localhost:5000/getSerializedData", {params}));
      console.log(response)
      dispatch({type: GET_DATA_OK})
    
  }catch(err){
    console.log(err)
    dispatch({type: GET_DATA_ERROR})
  }
 }
}


export default getData;