import { connect } from 'react-redux'
import GraphsView from "./GraphsView"
const mapStateToProps = (state, ownProps) => {
  return {
    data : state.data.data,
    colors : ["75,192,192","148, 123, 194","112, 210, 159","116, 189, 237"]
  }
}

const mapDispatchToProps = (dispatch, ownProps) => {
  return {
  }
}

const Graphs = connect(
  mapStateToProps,
  mapDispatchToProps
)(GraphsView)

export default Graphs;