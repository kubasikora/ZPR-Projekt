import React from "react"
import ParameterPanel from "../ParameterPanel"
import Graphs from "../Graphs"
import "./Serialization.css"
class SerializationView extends React.Component {
    constructor(props) {
      super(props);
     
    }




    render() {
        return (
            <div className="serialization-panel">
            <div className="graphs">
            {this.props.dataValid? <Graphs />: null}
            </div>
           
            <ParameterPanel />
        </div>
        )
  }
}


export default  SerializationView;