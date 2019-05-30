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
                <ParameterPanel />
            <div className="graphs">
            {!this.props.loading? <Graphs/>: null}
            </div>
        </div>
        )
  }
}


export default  SerializationView;