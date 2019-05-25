import { connect } from 'react-redux'
import ParameterPanelView from './ParameterPanelView'
import getData from "../../actions/getData"

const mapStateToProps = (state, ownProps) => {
  return {
    
  }
}

const mapDispatchToProps = (dispatch, ownProps) => {
  return {
    onClick: (state) => {
      dispatch(getData(state))
  }
 }
}

const  ParameterPanel = connect(
  mapStateToProps,
  mapDispatchToProps
)( ParameterPanelView)

export default ParameterPanel