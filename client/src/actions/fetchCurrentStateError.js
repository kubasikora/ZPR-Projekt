import { FETCH_CURRENT_STATE_ERROR } from "../actionTypes"

const fetchCurrentStateError = error => {
    return {
        type: FETCH_CURRENT_STATE_ERROR,
        error
    }
}

export default fetchCurrentStateError;