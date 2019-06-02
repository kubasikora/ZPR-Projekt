import * as actionTypes from "../../actionTypes";
import loginStart from "../../actions/loginStart"
import loginOK from "../../actions/loginOK";
import loginError from "../../actions/loginError"
describe('Action tests', () => {
    const login = "USER";
    const password = "PASSWORD";

    test("loginStart should create LOGIN_START action", () => {
        expect(loginStart(login, password)).toEqual({
            type: actionTypes.LOGIN_START

        })
    })

    test("loginOK should create LOGIN_OK action", () => {
        expect(loginOK()).toEqual({
            type: actionTypes.LOGIN_OK

        })
    })

    test("loginError should create LOGIN_ERROR action", () => {
        expect(loginError("401")).toEqual({
            type: actionTypes.LOGIN_ERROR,
            error: "401"

        })
    })

    test("loginError should return null when called without argument", () => {
        expect(loginError()).toEqual({"type": null})
    });

})