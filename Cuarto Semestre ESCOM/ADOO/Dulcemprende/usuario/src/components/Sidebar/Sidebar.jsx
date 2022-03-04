import React, {useState, useEffect} from 'react'
import "./sidebar.css"
import logo from "../../images/logo/logof.svg"
import { useDispatch, useSelector } from "react-redux";
import { login, signout, signup as _signup } from "../../actions";
import {
    Modal,
    MaterialInput,
    MaterialButton,
  } from "../MaterialUI/MaterialUI";
const Sidebar = ({ sidebarOpen, closeSidebar, element}) => {

    let c, i, q, cr, t
    const auth = useSelector((state) => state.auth);
    const dispatch = useDispatch();
    const [loginModal, setLoginModal] = useState(false);
    const [signup, setSignup] = useState(false);
    const [firstName, setFirstName] = useState("");
    const [lastName, setLastName] = useState("");
    const [email, setEmail] = useState("");
    const [password, setPassword] = useState("");

    if(element === "Chat")
      c = true
    if(element === "Inicio")
      i = true
    if(element === "Sobre Dulcemprende")
      q = true
    if(element === "Sobre los creadores")
      cr = true
    if(element === "Tienda"){
      t = true
    }

    const userSignup = () => {
        const user = { firstName, lastName, email, password};
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

    const renderLoggedInSidebar = () => {
        return (
            <div className={sidebarOpen ? "sidebar_responsive" : ""} id="sidebar">
            <div className="sidebar__title">
                <div className="sidebar__img">
                    <img src={logo} width="100%"/>
                </div>
                <i className="fas fa-times" id="sidebarIcon" onClick={() => closeSidebar()}></i>
            </div>

            <div className="sidebar__menu">
                <div className={ i ? "sidebar__link active_menu_link": "sidebar__link"}>
                    <i className="fas fa-home"></i>
                    <a href={`/`}>Administración</a>
                </div>
                <h2>Menú</h2>
                <div className={ t ? "sidebar__link active_menu_link": "sidebar__link"}>
                    <i className="fas fa-store"></i>
                    <a href={`/store`}>Tienda</a>
                </div>
                <div className={ c ? "sidebar__link active_menu_link": "sidebar__link"}>
                    <i className="fas fa-comments"></i>
                    <a href={`/chat`}>Chat</a>
                </div>
                <h2>Usuario</h2>
                <div className="sidebar__link">
                    <i className="fas fa-sign-out-alt"></i>
                    <a href="#" onClick={logout}>Cerrar sesión</a>
                </div>
                <h2>Nosotros</h2>
                <div className={ q ? "sidebar__link active_menu_link": "sidebar__link"}>
                    <i className="fas fa-question"></i>
                    <a href={`/about`}>¿Qué es Dulcemprende?</a>
                </div>
                <div className={ cr ? "sidebar__link active_menu_link": "sidebar__link"}>
                    <i className="fas fa-users"></i>
                    <a href={`/about-creators`}>Creadores</a>
                </div>
              
            </div>
            
        </div>
        )
    }

const renderNonLoggedInSidebar = () => {
    return (
        <div className={sidebarOpen ? "sidebar_responsive" : ""} id="sidebar">
        <div className="sidebar__title">
            <div className="sidebar__img">
                <img src={logo} alt="logo" />
                <h1>Dulcemprende</h1>
            </div>
            <i className="fas fa-times" id="sidebarIcon" onClick={() => closeSidebar()}></i>
        </div>

        <div className="sidebar__menu">
            <div className={ i ? "sidebar__link active_menu_link": "sidebar__link"}>
                <i className="fas fa-home"></i>
                <a href={`/`}>Administración</a>
            </div>
            <h2>Menú</h2>
            <div className={ t ? "sidebar__link active_menu_link": "sidebar__link"}>
                <i className="fas fa-store"></i>
                <a href={`/store`}>Tienda</a>
            </div>
            <div className={ c ? "sidebar__link active_menu_link": "sidebar__link"}>
                <i className="fas fa-comments"></i>
                <a href={`/chat`}>Chat</a>
            </div>
            <h2>Usuario</h2>
            <div className="sidebar__link">
                <i className="fas fa-sign-out-alt"></i>
                <a  href="#" onClick={() => {
              setSignup(false);
              setLoginModal(true);
            }}>Iniciar sesión</a>
            </div>
            <div className="sidebar__link">
                <i className="fas fa-sign-out-alt"></i>
                <a href="#" onClick={() => {
                setLoginModal(true);
                setSignup(true);
              }}>Registrate!</a>
            </div>
            <h2>Nosotros</h2>
            <div className={ q ? "sidebar__link active_menu_link": "sidebar__link"}>
                <i className="fas fa-question"></i>
                <a href={`/about`}>¿Qué es Dulcemprende?</a>
            </div>
            <div className={ cr ? "sidebar__link active_menu_link": "sidebar__link"}>
                <i className="fas fa-users"></i>
                <a href={`/about-creators`}>Creadores</a>
            </div>
          
        </div>
        
    </div>
    )
}
    
    return (
        <>
        <Modal visible={loginModal} onClose={() => setLoginModal(false)}>
        <div className="authContainer">
          <div className="row">
            <div className="leftspace">
              <h2>Se parte de Dulcemprende</h2>
              <p>Chatea, compra y administra tu negocio!</p>
            </div>
            <div className="rightspace">
              <div className="loginInputContainer">
                {console.log(auth)}
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
                  title={signup ? "Registrate!" : "Iniciar sesión"}
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
      {auth.authenticate ? renderLoggedInSidebar() : renderNonLoggedInSidebar()}

    </>
        
    )
}

export default Sidebar
