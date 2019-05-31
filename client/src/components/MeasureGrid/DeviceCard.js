import React from "react";
import Card from "react-bootstrap/Card";


const DeviceCard = props => {
    let { value, unit, name, description, serial } = props;

    return (
        <Card style={{ width: "auto", backgroundColor: "#8093A0", marginBottom: "3vh" }}>
            <Card.Body>
                <Card.Title style={{ color: "#2DC5C9", fontFamily: "Montserrat", fontSize: "120px", textAlign: "left" }}>
                    {value} 
                    <span style={{ color: "#2DC5C9", fontFamily: "Montserrat", fontSize: "32px", textAlign: "center" }}>
                        {unit}
                    </span>
                </Card.Title>

                <Card.Text style={{ color: "white", fontFamily: "Montserrat", fontSize: "32px", textAlign: "left" }}>
                    {description}
                </Card.Text>
                <Card.Text style={{ color: "white", fontFamily: "Montserrat", fontSize: "20px", textAlign: "left" }}>
                    {name}
                    <div style={{ color: "lightgray", fontFamily: "Roboto Mono", fontSize: "16px", textAlign: "left" }}>
                    {serial}
                    </div>
                </Card.Text>
            </Card.Body>
        </Card>
    );
};

export default DeviceCard;