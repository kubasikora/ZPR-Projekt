import { connect } from 'react-redux'
import SerializationView from './SerializationView'

const mapStateToProps = (state, ownProps) => {
  return {
    loading : state.data.loading,
    data: state.data.data
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