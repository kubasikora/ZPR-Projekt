import { connect } from 'react-redux'
import SerializationView from './SerializationView'

const mapStateToProps = (state, ownProps) => {
  return {
    dataValid : state.dataValid
  }
}

const mapDispatchToProps = (dispatch, ownProps) => {
  return {
   
  }
}

const  Serialization = connect(
  mapStateToProps,
  mapDispatchToProps
)( SerializationView)

export default Serialization