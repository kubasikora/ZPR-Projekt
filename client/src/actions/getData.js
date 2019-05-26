import {GET_DATA_START, GET_DATA_OK, GET_DATA_ERROR} from "../actionTypes"
import axios from 'axios';
 function getData(state) {
    return { type: GET_DATA_START
    }
  }

export default getData;