import React from "react"
import Header from "../Header";
import Container from 'react-bootstrap/Container';
import Row from 'react-bootstrap/Row';
import Col from 'react-bootstrap/Col';

import DeviceCard from "./DeviceCard";

class MeasureGridView extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <div>
        <Header />
        <Container>
          <Row style={{marginTop: "8rem"}}>
            <Col sm={12} md={6} >
            <DeviceCard value={23.45} name={"CS7 - Introl"} serial={"b31edaf2-4fb7-11e9-8647-d663bd873d93"}/>
            </Col>
            <Col sm={12} md={6} >
            <DeviceCard />
            </Col>
          </Row>
          <Row style={{marginTop: "2rem"}}>
            <Col sm={12} md={6} >
            <DeviceCard />
            </Col>
            <Col sm={12} md={6} >
            <DeviceCard />
            </Col>
          </Row>
        </Container>
      </div>
    );
  }

}


export default MeasureGridView;