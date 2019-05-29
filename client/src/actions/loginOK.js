import { LOGIN_OK } from "../actionTypes"

const loginOK = (response) => {
    return {
        type: LOGIN_OK,
        payload: response
    }
}

export default loginOK;