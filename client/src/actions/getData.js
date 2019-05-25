import {GET_DATA_START, GET_DATA_OK, GET_DATA_ERROR} from "../actionTypes"

 function getData(login, password) {
    return { type: GET_DATA_START
    }
  }

export default getData;