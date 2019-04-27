import * as actionTypes from "../../actionTypes";
import loginStart from "../../actions/loginStart"

describe('Action tests', ()=>{
    const login = "USER";
    const password = "PASSWORD";

  test("loginStart should create LOGIN_OK action", ()=>{
      expect(loginStart(login, password)).toEqual({
         type: actionTypes.LOGIN_OK 
        
      })
  })
})