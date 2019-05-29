import { combineReducers } from "redux";
import authReducer from "./authReducer.js";
import dataReducer from "./dataReducer.js";
const reducer = combineReducers({
    auth: authReducer,
    data: dataReducer
});

export default reducer;
