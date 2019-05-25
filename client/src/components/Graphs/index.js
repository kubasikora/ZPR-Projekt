import { connect } from 'react-redux'
import GraphsView from "./GraphsView"
const mapStateToProps = (state, ownProps) => {
  return {
    
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