import { connect } from 'react-redux'
import LoginPanelView from './LoginPanelView'
import authenticate from "../../actions/authenticate";

const mapStateToProps = (state, ownProps) => {
  return {
    error: state.auth.error
  }
}

const mapDispatchToProps = (dispatch, ownProps) => {
  return {
      authenticate: (login, password) => dispatch(authenticate(login, password))
  }
}

const LoginPanel = connect(
  mapStateToProps,
  mapDispatchToProps
)(LoginPanelView)

export default LoginPanel