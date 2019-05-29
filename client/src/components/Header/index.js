import React from "react";
import { connect } from 'react-redux';
import Navbar from "react-bootstrap/Navbar";
import Nav from "react-bootstrap/Nav";
import OverlayTrigger from "react-bootstrap/OverlayTrigger";
import Tooltip from "react-bootstrap/Tooltip";
import { Link, Redirect } from "react-router-dom";

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

        const login = localStorage.getItem('username');

        if(!login) return <Redirect to="/" />

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
                                <a href="/" onClick={() => {
                                    localStorage.removeItem('username');
                                    localStorage.removeItem('basicAuth');
                                }}>{login}</a>
                            </OverlayTrigger>
                        </Navbar.Text>
                    </Navbar.Collapse>
                </Navbar>
            </React.Fragment>
        );
    }
};

const mapStateToProps = (state, ownProps) => {
  return {
    login: state.auth.login
  }
}

const mapDispatchToProps = (dispatch, ownProps) => {
  return {
  }
}

const LoginPanel = connect(
  mapStateToProps,
  mapDispatchToProps
)(Header)

export default Header;