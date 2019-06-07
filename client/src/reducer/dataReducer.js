import initialState from "./initialState"
import {
    GET_DATA_ERROR,
    GET_DATA_START,
    GET_DATA_OK
} from "../actionTypes"

const reducers = (state = initialState.data, action) => {
    console.log(action.type)
    switch (action.type) {
        case GET_DATA_START:
            return {
                ...state,
                loading: true,
                data : [],
                error: "",
            }
        case GET_DATA_OK:
            return {
                ...state,
                loading: false,
                data: [...state.data,
                     action.data],
                error: ""
            }
        case GET_DATA_ERROR:
            return {
                ...state,
                loading: false,
                error: action.payload
            }
        default:
            return state;
    }
};
export default reducers;