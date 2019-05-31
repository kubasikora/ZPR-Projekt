import { connect } from 'react-redux'
import MeasureGridView from './MeasureGridView'
import fetchCurrentState from '../../actions/fetchCurrentState';

const mapStateToProps = (state, ownProps) => {
  return {
    processState: state.processState.devices
  }
}

const mapDispatchToProps = (dispatch, ownProps) => {
  return {
    updateState: () => dispatch(fetchCurrentState())
  }
}

const  MeasureGrid = connect(
  mapStateToProps,
  mapDispatchToProps
)( MeasureGridView)

export default MeasureGrid