import React from "react";
import dulcemprendeLogof from "../../images/logo/logof.svg";
import "./style.css";
const Footer = () => {
  return (
    <div className="footer">
      <div className="Hcontainer">
        <div className="row">
          <div className="footer-col-1">
            <h3>Checa el repositorio!</h3>
            <p>Puedes ver el repositorio del proyecto</p>
            <div className="app-logo">
              <a href="https://github.com/BrandMV/Dulcemprende">
                <i className="fab fa-github"></i>
              </a>
            </div>
          </div>
          <div className="footer-col-2">
            <img src={dulcemprendeLogof} alt="" />
            <p>
              Dulcemprende esta enfocado a emprendedores como tú! Queremos que
              hagas tus sueños realidad
            </p>
          </div>
          <div className="footer-col-3">
            <h3>Otros Links</h3>
            <ul>
              <a href={`/about`}>
                <li>Sobre Dulcemprende</li>
              </a>
              <a href={`/about-creators`}>
                <li>Sobre los creadores</li>
              </a>
            </ul>
          </div>
        </div>
        <hr />
        <p className="copyrigth">Copyright 2021 - Dulcemprende</p>
      </div>
    </div>
  );
};

export default Footer;
