import React from "react"
import ParameterPanel from "../ParameterPanel"
import Graphs from "../Graphs"
import "./Serialization.css"
import Spinner from 'react-bootstrap/Spinner'
import Container from 'react-bootstrap/Container';
import Row from 'react-bootstrap/Row';
import Col from 'react-bootstrap/Col';
import Header from "../Header";
import Error from "./Error"
class SerializationView extends React.Component {
  constructor(props) {
    super(props);

  }

  render() {
    return (
      <div>
        <Header />
        <Container fluid={true}>
          <Row>
            <Col md={8}>
              <div className="graphs">
                {this.props.loading ?
                  <Spinner animation="border" role="status" className="spinner" size="m">
                    <span className="sr-only">Ładowanie...</span>
                  </Spinner> : this.props.data[0] ? <Graphs /> : 
                  <Error content={this.props.error} />}
              </div>
            </Col>
            <Col md={4}>
              <ParameterPanel />
            </Col>
          </Row>
        </Container>
      </div>
    )
  }
}


export default SerializationView;