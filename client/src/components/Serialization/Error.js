import React from "react"
import "./Error.css"

class Error extends React.Component {
  constructor(props) {
    super(props);

  }

  render() {
    return (
      <div className="error-panel">
        {this.props.content}
      </div>
    )
  }
}


export default Error;