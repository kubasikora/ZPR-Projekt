import React from "react";
import {Container, Row, Col, Card, Image} from "react-bootstrap";
import Header from "../Header";

const Page404 = () => {
    return (
        <div>
            <Header/>
            <Container>
                <Col>
                    <Row md={12}>
                    <Card style={{ width: "100%", height: "30rem", margin: "10rem auto", backgroundColor: "#8093C1" }}>
                        <Card.Body>
                            <div style={{margin: "4rem"}}>
                                <img src="./logo.png" />
                                <div style={{marginTop: "20px", fontSize:"32px", fontFamily:"Montserrat"}}> 
                                    404 <br/>
                                    Podana strona nie istnieje
                                </div>
                            </div>
                        </Card.Body>
                        </Card>
                    </Row>  
                </Col>
            </Container>
        </div>
    )
};

export default Page404;