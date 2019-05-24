import React from "react";
import Card from "react-bootstrap/Card";


const DeviceCard = props => {
    let { value, name, serial } = props;

    return (
        <Card style={{ width: "auto", backgroundColor: "#8093A0"  }}>
            <Card.Body>
                <Card.Title style={{color: "#2DC5C9", fontSize: "128px", textAlign: "left"}}>{value}</Card.Title>
                <Card.Text style={{color: "white", fontSize: "32px", textAlign: "left"}}>
                    {name}
                </Card.Text>
                <Card.Text style={{color: "lightgray", fontSize: "16px", textAlign: "left"}}>
                    {serial}
                </Card.Text>
            </Card.Body>
        </Card>
    );
};

export default DeviceCard;