import React from "react"
import Container from 'react-bootstrap/Container';
import Row from 'react-bootstrap/Row';
import Col from 'react-bootstrap/Col';

import DeviceCard from "./DeviceCard";
import Header from "../Header";

class MeasureGridView extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <div>
        <Header/>
        <Container>
          <Row style={{marginTop: "5rem"}}>
            <Col sm={12} md={6} >
            <DeviceCard 
              description={"Temperatura gazu"}
              value={23.45} 
              name={"CS7"} 
              unit={"°C"} 
              serial={"b31edaf2-4fb7-11e9-8647-d663bd873d93"}/>
            </Col>
            <Col sm={12} md={6} >
            <DeviceCard 
              description={"Przepływ gazu"}
              value={2330} 
              name={"FLOMID XT5/XT5H"} 
              unit={"l/h"} 
              serial={"99e6c2cb-68a3-4f27-a289-5be85ce96669"}/>
            </Col>
          </Row>
          <Row style={{marginTop: "2rem"}}>
            <Col sm={12} md={6} >
            <DeviceCard 
              description={"Ciśnienie w rurociągu"}
              value={0.665} 
              unit={"bar"} 
              name={"ADZ-SML-10.0"} 
              serial={"b31edaf2-4fb7-11e9-8647-d663bd873d93"}/>
            </Col>
            <Col sm={12} md={6} >
            <DeviceCard 
              description={"Wilgotność gazu"}
              value={35} 
              unit={"%"} 
              name={"AM2302"} 
              serial={"b31edaf2-4fb7-11e9-8647-d663bd873d93"}/>
            </Col>
          </Row>
        </Container>
      </div>
    );
  }

}


export default MeasureGridView;