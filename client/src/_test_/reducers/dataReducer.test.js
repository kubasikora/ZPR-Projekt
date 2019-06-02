import app from "../../reducer"
import initialState from "../../reducer/initialState"
import * as actionTypes from "../../actionTypes"

describe("dataReducers test",()=>{
    it('Getting data starts',()=>{
        const action ={
            type: actionTypes.GET_DATA_START
        };
        expect(app(initialState, action).data).toEqual({
            loading: true,
            data : []
        });

    });
    it('Getting data OK',()=>{
        const action ={
            type: actionTypes.GET_DATA_OK,
            data: "OK"
        }
        expect(app(initialState, action).data).toEqual({
            loading: false,
            data: ["OK"]
        })

    });
    it('Getting data error',()=>{
        const action ={
            type: actionTypes.GET_DATA_ERROR,
        }
        expect(app(initialState, action).data).toEqual({
            loading: false,
            data: []
        })

    });
})