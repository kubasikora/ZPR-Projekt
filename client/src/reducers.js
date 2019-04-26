import {LOGIN_START, LOGIN_OK, LOGIN_ERROR} from "./actionTypes"
import startState from "./startState"
 const reducers = (state=startState, action) => {
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
      default:
        return state;
      }
  };
  export default reducers;