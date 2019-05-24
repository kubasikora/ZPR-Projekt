import React from "react";
import Navbar from "react-bootstrap/Navbar";
import Nav from "react-bootstrap/Nav";
import OverlayTrigger from "react-bootstrap/OverlayTrigger";
import Tooltip from "react-bootstrap/Tooltip";

class Header extends React.Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <React.Fragment>
                <Navbar variant="dark" style={{ backgroundColor: "#8093A0" }}>
                    <Navbar.Brand href="/">
                        <img
                            alt=""
                            src="../logo.png"
                            width="30"
                            height="30"
                            className="d-inline-block align-top"
                        />
                        {' ZPR Projekt '}
                    </Navbar.Brand>
                    <Nav className="mr-auto">
                        <Nav.Link href="/home">Dashboard</Nav.Link>
                        <Nav.Link href="/figures">Serie danych</Nav.Link>
                    </Nav>

                    <Navbar.Collapse className="justify-content-end">
                        <Navbar.Text>
                            {"Zalogowano jako: "}
                            <OverlayTrigger
                                key="bottom"
                                placement="bottom"
                                overlay={
                                    <Tooltip>
                                        Wyloguj
                                    </Tooltip>
                                }>
                                <a href="/">admin</a>
                            </OverlayTrigger>
                        </Navbar.Text>
                    </Navbar.Collapse>
                </Navbar>
            </React.Fragment>
        );
    }
};

export default Header;