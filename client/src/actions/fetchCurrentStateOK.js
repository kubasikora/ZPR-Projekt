import { FETCH_CURRENT_STATE_OK } from "../actionTypes"

const fetchCurrentStateOK = payload => {
    return {
        type: FETCH_CURRENT_STATE_OK,
        payload
    }
}

export default fetchCurrentStateOK;