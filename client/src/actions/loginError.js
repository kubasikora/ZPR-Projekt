import { LOGIN_ERROR } from "../actionTypes"

const loginError = (error) => {
    if(!error) return {
        type: null
    };
    
    return {
        type: LOGIN_ERROR,
        error
    }
}

export default loginError;