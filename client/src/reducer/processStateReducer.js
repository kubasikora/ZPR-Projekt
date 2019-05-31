import initialState from "./initialState"
import {
    FETCH_CURRENT_STATE_START,
    FETCH_CURRENT_STATE_OK,
    FETCH_CURRENT_STATE_ERROR
} from "../actionTypes"

const reducers = (state = initialState.processState, action) => {
    switch (action.type) {
        case FETCH_CURRENT_STATE_START:
            return {
                ...state,
            }

        case FETCH_CURRENT_STATE_OK:
            let newProcessState = [ ...state.devices ];
            const data = action.payload.data;

            data.map(element => {
                newProcessState.find(x => x.deviceId == element.deviceId).deviceValue = element.value.toPrecision(4).toString();
            });

            return {
                ...state,
                devices: newProcessState
            };

        case FETCH_CURRENT_STATE_ERROR:
            return {
                ...state
            }

        default:
            return state;
    }
};

export default reducers;