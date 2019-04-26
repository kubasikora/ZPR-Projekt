import { connect } from 'react-redux'
import LoginPanelView from './LoginPanelView'
import loginStart from "../../actions/loginStart"
const mapStateToProps = (state, ownProps) => {
  return {
    
  }
}

const mapDispatchToProps = (dispatch, ownProps) => {
  return {
    onClick: (login, password) => {
      dispatch(loginStart(login, password))
    }
  }
}

const LoginPanel = connect(
  mapStateToProps,
  mapDispatchToProps
)(LoginPanelView)

export default LoginPanel