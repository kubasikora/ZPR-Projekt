import React from "react"
import Container from 'react-bootstrap/Container';
import Row from 'react-bootstrap/Row';
import Col from 'react-bootstrap/Col';

import DeviceCard from "./DeviceCard";
import Header from "../Header";



class MeasureGridView extends React.Component {
  constructor(props) {
    super(props);
    this.id = null;
  }

  componentDidMount() {
    this.id = window.setInterval(async () => this.props.updateState(), 500);
  }

  componentWillUnmount() {
    clearInterval(this.id);
  }

  render() {
    return (
      <div>
        <Header />
        <Container>
          <Row style={{ marginTop: "5rem" }}>
            {this.props.processState.map(device => {
              return (
                <Col sm={12} md={6} >
                  <DeviceCard
                    description={device.deviceLabel}
                    value={device.deviceValue}
                    name={device.deviceName}
                    unit={device.deviceUnit}
                    serial={device.deviceSerial} />
                </Col>
              )
            })}
          </Row>
        </Container>
      </div>
    );
  }

}


export default MeasureGridView;