import React, { useState, useEffect } from "react";
import "./style.css";
import dulcemprendeLogo from "../../images/logo/logo.svg";
import { useDispatch, useSelector } from "react-redux";
import Cart from "../UI/Cart";
import menu from "../../images/menu.png"
import { login, signout, getCartItems, signup as _signup } from "../../actions";
import {
  Modal,
  MaterialInput,
  MaterialButton,
  DropdownMenu,
} from "../MaterialUI/MaterialUI";

const Header = (props) => {
  const auth = useSelector((state) => state.auth);
  const dispatch = useDispatch();
  const [nav, setNav] = useState(true)
  const [loginModal, setLoginModal] = useState(false);
  const [signup, setSignup] = useState(false);
  const [firstName, setFirstName] = useState("");
  const [lastName, setLastName] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");
  // state cart value
  const cart = useSelector((state) => state.cart);
  const userSignup = () => {
    const user = { firstName, lastName, email, password };
    if (
      firstName === "" ||
      lastName === "" ||
      email === "" ||
      password === ""
    ) {
      return;
    }

    dispatch(_signup(user));
  };

  const userLogin = () => {
    if (signup) {
      userSignup();
    } else {
      dispatch(login({ email, password }));
    }
  };

  const logout = () => {
    dispatch(signout());
  };

  useEffect(() => {
    if (auth.authenticate) {
      setLoginModal(false);
    }
  }, [auth.authenticate]);
  const logged = () => {
    return (
      <DropdownMenu
      menu={<a className="fullName">Hola {auth.user.fullName}!</a>}
      menus={[
        {
          label: "Ordenes",
          href: `/account/orders`,
          icon: null,
        },
        { label: "Cerrar sesión", href: "", icon: null, onClick: logout },
      ]}
    />
    )
  }

  const nonLogged = () => {
    return (
      <DropdownMenu
      menu={
        <a
          className="loginButton"
          onClick={() => {
            setSignup(false);
            setLoginModal(true);
          }}
          style={{ color: "#2874f0", cursor: "pointer" }}
        >
          No has iniciado sesión
        </a>
      }
      menus={[

      ]}
      firstMenu={
        <div className="firstmenu">
          <span>Nuevo en Dulcemprende?</span>
          <a
            onClick={() => {
              setLoginModal(true);
              setSignup(true);
            }}
            style={{ color: "#2874f0", cursor: "pointer" }}
          >
            Registrate
          </a>
        </div>
      }
    />
    )
  }

  const renderNav = () => {
    return (
      <ul>
      <li><a href={`/`}>Administra tu negocio!</a></li>
      <li><a href={`/chat`}>Chatea!</a></li>
      <li> <a href={`/cart`}>
            <span>Carrito</span>
          </a>
        </li>
      <li><a href={`/cart`}><Cart count={Object.keys(cart.cartItems).length}/></a></li>
       
      {auth.authenticate ? logged() : nonLogged()}
    </ul>
    )
  }


  return (
      <div className="Hcontainer">
          <Modal visible={loginModal} onClose={() => setLoginModal(false)}>
        <div className="authContainer">
          <div className="row">
            <div className="leftspace">
              <h2>Se parte de Dulcemprende</h2>
              <p>Chatea, compra y administra tu negocio!</p>
            </div>
            <div className="rightspace">
              <div className="loginInputContainer">
                {auth.error && (
                  <div style={{ color: "red", fontSize: 12 }}>{auth.error}</div>
                )}
                {signup && (
                  <MaterialInput
                    type="text"
                    label="Nombre"
                    value={firstName}
                    onChange={(e) => setFirstName(e.target.value)}
                  />
                )}
                {signup && (
                  <MaterialInput
                    type="text"
                    label="Apellido"
                    value={lastName}
                    onChange={(e) => setLastName(e.target.value)}
                  />
                )}

                <MaterialInput
                  type="text"
                  label="Correo"
                  value={email}
                  onChange={(e) => setEmail(e.target.value)}
                />
                <MaterialInput
                  type="password"
                  label="Contraseña"
                  value={password}
                  onChange={(e) => setPassword(e.target.value)}
                  // rightElement={<a href="#">Forgot?</a>}
                />
                <MaterialButton
                  title={signup ? "Registrate!" : "Inicia sesión"}
                  bgColor="#3ea175"
                  textColor="#ffffff"
                  style={{
                    margin: "40px 0 20px 0",
                  }}
                  onClick={userLogin}
                />
              </div>
            </div>
          </div>
        </div>
      </Modal>
        <div className="navbar">
        <div className="logo">
          <a href={`/store`}><img  src={dulcemprendeLogo} width="125px"/></a>
        </div>
        <nav>
            {nav ? renderNav() : ""}
        </nav>
        <img  src={menu} className="menu-icon" onClick={() => setNav(!nav)}/>
        </div>
        {/* <div className="row">
          <div className="col-2">
              <h1>Empieza a emprender con Dulcemprende!</h1>
              <p>El secreto de un gran negocio consiste en saber algo que nadie más sabe. Aristoteles Onassis</p>
              <a href="" className="btn">Comienza! <i class="fas fa-long-arrow-alt-right"></i></a>
          </div>
          <div className="col-2">
            <img src={emprende} />
          </div>
        </div>
      </div> */}
    </div>
  );
};

export default Header;
