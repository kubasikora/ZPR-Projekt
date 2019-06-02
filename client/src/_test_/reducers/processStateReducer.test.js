import app from "../../reducer"
import initialState from "../../reducer/initialState"
import * as actionTypes from "../../actionTypes"

describe("processStateReducer test",()=>{
    it('ProcessState data starts',()=>{
        const action ={
            type: actionTypes.FETCH_CURRENT_STATE_START
        };
        expect(app(initialState, action).processState).toEqual(initialState.processState)   });

    
    it('ProcessState data OK',()=>{
        const action ={
            type: actionTypes.FETCH_CURRENT_STATE_START,
            payload:{ data:[ {
                    deviceId: 1,
                    value: 500.000010
                },
                {
                    deviceId: 2,
                    value: 500.000010
                },
                {
                    deviceId: 3,
                    value: 500.000010
                },
                {
                    deviceId: "4",
                    value: 500.000010
                }]
            }
        }
        expect(app(initialState, action).processState).toEqual(
            initialState.processState)

    });
    it('Getting data error',()=>{
        const action ={
            type: actionTypes.FETCH_CURRENT_STATE_ERROR
        }
        expect(app(initialState, action).processState).toEqual(initialState.processState)

    });
})