import { connect } from 'react-redux'
import ParameterPanelView from './ParameterPanelView'

const mapStateToProps = (state, ownProps) => {
  return {
    
  }
}

const mapDispatchToProps = (dispatch, ownProps) => {
  return {
   
  }
}

const  ParameterPanel = connect(
  mapStateToProps,
  mapDispatchToProps
)( ParameterPanelView)

export default ParameterPanel