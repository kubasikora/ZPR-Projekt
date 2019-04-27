import app from "../../reducers"
import initialState from "../../initialState"
import * as actionTypes from "../../actionTypes"

describe("Reducers test",()=>{
    it('Logging starts',()=>{
        const action ={
            type: actionTypes.LOGIN_START
        };
        expect(app(initialState, action)).toEqual({
            logged: false
        });

    });
    it('Logging OK',()=>{
        const action ={
            type: actionTypes.LOGIN_OK
        }
        expect(app(initialState, action)).toEqual({
            logged: true
        })

    });
    it('Logging error',()=>{
        const action ={
            type: actionTypes.LOGIN_ERROR
        }
        expect(app(initialState, action)).toEqual({
            logged: false
        })

    });
})