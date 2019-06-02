import app from "../../reducer/authReducer"
import initialState from "../../reducer/initialState"
import * as actionTypes from "../../actionTypes"

describe("Reducers test",()=>{
    it('Logging starts',()=>{
        const action ={
            type: actionTypes.LOGIN_START
        };
        expect(app(initialState, action).auth).toEqual({
            login: null,
            password: null
        });

    });
    it('Logging OK',()=>{
        const action ={
            type: actionTypes.LOGIN_OK
        }
        expect(app(initialState, action).auth).toEqual({
            login: null,
            password: null
        })

    });
    it('Logging error',()=>{
        const action ={
            type: actionTypes.LOGIN_ERROR,
            error: "error"
        }
        expect(app(initialState, action).auth).toEqual({
            login: null,
            password: null,
        })

    });
})