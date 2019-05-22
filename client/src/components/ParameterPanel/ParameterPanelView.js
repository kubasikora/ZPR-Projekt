import React from "react"
import DatePicker from "react-datepicker"
import "react-datepicker/dist/react-datepicker.css";
import {Dropdown, ButtonToolbar, Button} from "react-bootstrap"
import "bootstrap/dist/css/bootstrap.min.css"
class ParameterPanelView extends React.Component {
    constructor(props) {
      super(props);
      this.state = {
        startDate: "",
        endDate: "",
        device: "Devices"
      }
    this.handleChangeEnd = this.handleChangeEnd.bind(this);
    this.handleChangeStart = this.handleChangeStart.bind(this);
    
    }


    handleChangeEnd(newEndDate){
        this.setState({endDate: newEndDate})
    }

    handleChangeStart(newStartDate){
        this.setState({startDate: newStartDate})
    }


    render() {
        return (
            <div>
                <ButtonToolbar>
                    <Dropdown>
                        <Dropdown.Toggle id="dropdown-item-button">{this.state.device}</Dropdown.Toggle>
                        <Dropdown.Menu className="super-colors">
                        <Dropdown.Item as="button" eventKey="1">CS7</Dropdown.Item>
                        <Dropdown.Item as="button" eventKey="2">FLOMID XT5/XT5H</Dropdown.Item>
                        <Dropdown.Item as="button" eventKey="3" >ADZ-SML-10.0</Dropdown.Item>
                        <Dropdown.Item as="button" eventKey="4">AM2302</Dropdown.Item>
                        <Dropdown.Divider />
                        <Dropdown.Item as="button" eventKey="5">All devices</Dropdown.Item>
                        </Dropdown.Menu>
                    </Dropdown>
                </ButtonToolbar>

                <DatePicker
                selected={this.state.startDate}
                selectsStart
                showTimeSelect
                startDate={this.state.startDate}
                endDate={this.state.endDate}
                onChange={this.handleChangeStart}
            />
            
            <DatePicker
                selected={this.state.endDate}
                selectsEnd
                showTimeSelect
                startDate={this.state.startDate}
                endDate={this.state.endDate}
                onChange={this.handleChangeEnd}
            />
            <ButtonToolbar>
                <Button variant="primary" type="submit">
                Get data!
                </Button>
            </ButtonToolbar>
        </div>
        )
  }
}


export default  ParameterPanelView;