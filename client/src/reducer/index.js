import { combineReducers } from "redux";
import authReducer from "./authReducer.js";
import dataReducer from "./dataReducer.js";
import processStateReducer from "./processStateReducer";
const reducer = combineReducers({
    auth: authReducer,
    data: dataReducer,
    processState: processStateReducer
});

export default reducer;
