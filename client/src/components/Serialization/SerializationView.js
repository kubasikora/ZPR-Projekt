import React from "react"
import ParameterPanel from "../ParameterPanel"
import Graphs from "../Graphs"
import "./Serialization.css"
import Spinner from 'react-bootstrap/Spinner'
class SerializationView extends React.Component {
    constructor(props) {
      super(props);
     
    }




    render() {
      console.log(this.props)
        return (
            <div className="serialization-panel">
                <ParameterPanel />
            <div className="graphs">
            {this.props.loading ? 
              <Spinner animation="border" role="status" className = "spinner" size="m">
                     <span className="sr-only">Ładowanie...</span>
              </Spinner>:  this.props.data[0]? <Graphs />: null}
            </div>
        </div>
        )
  }
}


export default  SerializationView;