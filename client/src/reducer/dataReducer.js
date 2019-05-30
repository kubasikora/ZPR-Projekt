import initialState from "./initialState"
import {
    GET_DATA_ERROR,
    GET_DATA_START,
    GET_DATA_OK
} from "../actionTypes"

const reducers = (state = initialState.data, action) => {
    switch (action.type) {
        
        case GET_DATA_START:
            return {
                ...state,
                loading: true,
                data : []
            }
        case GET_DATA_OK:
            return {
                ...state,
                loading: false,
                data: [...state.data,
                     action.data]
            }
        case GET_DATA_ERROR:
            return {
                ...state,
                loading: false,
            }
        default:
            return state;
    }
};
export default reducers;