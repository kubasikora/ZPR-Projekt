import React from "react";
import Navbar from "react-bootstrap/Navbar";

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

                    <Navbar.Collapse className="justify-content-end">
                        <Navbar.Text>
                            Signed in as: <a href="#login">admin</a>
                        </Navbar.Text>
                    </Navbar.Collapse>
                </Navbar>
            </React.Fragment>
        );
    }
};

export default Header;