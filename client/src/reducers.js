import {LOGIN_START, LOGIN_OK, LOGIN_ERROR,
  GET_DATA_START, GET_DATA_OK, GET_DATA_ERROR} from "./actionTypes"
import initialState from "./initialState"
 const reducers = (state=initialState, action) => {
   console.log(state, action.type)
    switch (action.type) {
     
      case LOGIN_START:
         return {
          ...state,
            logged : false
         }
      case LOGIN_OK:
          return {
            ...state,
             logged : true
          }
      case LOGIN_ERROR:
          return {
        ...state,
          logged : false
          }
      case GET_DATA_OK:
          return {
            ...state,
            dataValid: true,
          }
      default:
        return state;
      }
  };
  export default reducers;