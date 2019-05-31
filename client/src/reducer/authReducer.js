import initialState from "./initialState"
import {
    LOGIN_START, 
    LOGIN_OK, 
    LOGIN_ERROR
} from "../actionTypes"

const reducers = (state = initialState.auth, action) => {
    switch (action.type) {

        case LOGIN_START:
            return {
                ...state,
                loading: true
            }
        case LOGIN_OK:
            return {
                ...state,
                loading: false
            }
        case LOGIN_ERROR:
            return {
                ...state,
                loading: false,
                error: action.error
            }
        default:
            return state;
    }
};
export default reducers;