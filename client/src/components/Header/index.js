import React from "react";
import Navbar from "react-bootstrap/Navbar";
import Nav from "react-bootstrap/Nav";
import OverlayTrigger from "react-bootstrap/OverlayTrigger";
import Tooltip from "react-bootstrap/Tooltip";
import {Link} from "react-router-dom";

class Header extends React.Component {
    constructor(props) {
        super(props);
    }

    render() {
        const navItemStyle={ 
            textDecoration: 'none',
            color: "white",
            margin: "10px"
        };

        return (
            <React.Fragment>
                <Navbar variant="dark" style={{ backgroundColor: "#8093A0" }}>
                    <Navbar.Brand href="/home">
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
                        <Link to="/home" style={navItemStyle}>Dashboard</Link>
                        <Link to="/figures" style={navItemStyle}>Serie danych</Link>
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