import { connect } from 'react-redux'
import ParameterPanelView from './ParameterPanelView'
import getData from "../../actions/getData"

const mapStateToProps = (state, ownProps) => {
  return {
    loading: state.data.loading
  }
}

const mapDispatchToProps = (dispatch, ownProps) => {
  return {
    getData: (state) => {dispatch(getData(state));}
  }
}

const ParameterPanel = connect(
  mapStateToProps,
  mapDispatchToProps
)(ParameterPanelView)

export default ParameterPanel