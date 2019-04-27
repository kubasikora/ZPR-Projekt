import { connect } from 'react-redux'
import MeasureGridView from './MeasureGridView'

const mapStateToProps = (state, ownProps) => {
  return {
    
  }
}

const mapDispatchToProps = (dispatch, ownProps) => {
  return {
   
  }
}

const  MeasureGrid = connect(
  mapStateToProps,
  mapDispatchToProps
)( MeasureGridView)

export default MeasureGrid