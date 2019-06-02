import * as actionTypes from "../../actionTypes";
import fetchCurrentStateError from "../../actions/fetchCurrentStateError"
import fetchCurrentStateOK from "../../actions/fetchCurrentStateOK";
import fetchCurrentStateStart from "../../actions/fetchCurrentStateStart";
describe('fetchCurrentState tests', () => {
 

    test("fetchCurrentStateStart should create FETCH_CURRENT_STATE action", () => {
        expect(fetchCurrentStateStart()).toEqual({
            type: actionTypes.FETCH_CURRENT_STATE_START

        })
    })

    test("fetchCurrentStateOK should create FETCH_CURRENT_STATE_OK action", () => {
        expect(fetchCurrentStateOK("OK")).toEqual({
            type: actionTypes.FETCH_CURRENT_STATE_OK,
            payload: "OK"

        })
    })

    test("fetchCurrentStateError should create LOGIN_ERROR action", () => {
        expect(fetchCurrentStateError("401")).toEqual({
            type: actionTypes.FETCH_CURRENT_STATE_ERROR,
            error: "401"

        })
    })

    test("fetchCurrentStateError should return null when called without argument", () => {
        expect(fetchCurrentStateError()).toEqual({
        error: undefined,
         type: "FETCH_CURRENT_STATE_ERROR"})
    });

})