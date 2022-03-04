import React from "react";
import "./style.css";
import B from "../../images/Creators/B.jpg";
import D from "../../images/Creators/D.jpeg";
import Di from "../../images/Creators/Di.jpg";
import Footer from "../Footer/Footer";
import wave from "../../images/Creators/wave.svg";

export const AboutCreators = () => {
  return (
    <>
      <div className="cCards">
        <h1>Creadores de Dulcemprende</h1>
        <div className="cCard">
          <div className="cImage">
            <img src={D} alt="D" />
          </div>
          <div className="cContent">
            <h2>Briones Tapia Daniela</h2>
            <p>
              Organizada y con gran motivación, adaptable a cualquier
              circunstancia y dando siempre lo mejor de mí en cualquier
              proyecto.
            </p>
            <div className="cIcons">
              <a href="">
                <i class="fab fa-github-square"></i>
              </a>
              <a href="https://www.facebook.com/DannyBriones05">
                <i class="fab fa-facebook"></i>
              </a>
            </div>
          </div>
        </div>
        <div className="cCard">
          <div className="cImage">
            <img src={B} alt="B" />
          </div>
          <div className="cContent">
            <h2>Meza Vargas Brandon David</h2>
            <p>
              Apasionado por la tecnología, siempre aprendiendo cosas nuevas y
              descubriendo de lo que soy capaz.
            </p>
            <div className="cIcons">
              <a href="https://github.com/BrandMV">
                <i class="fab fa-github-square"></i>
              </a>
              <a href="https://www.facebook.com/brand14k/">
                <i class="fab fa-facebook"></i>
              </a>
            </div>
          </div>
        </div>
        <div className="cCard">
          <div className="cImage">
            <img src={Di} alt="Di" />
          </div>
          <div className="cContent">
            <h2>Torres Jimenez Diego Antonio</h2>
            <p>
              Soy un tipo de trabajador que está acostumbrado al trabajo bajo
              presión, tengo varios años de experiencia en atención al cliente y
              en búsqueda de oportunidades comerciales. También me considero una
              persona resolutiva, con buen ánimo y capaz de resolver problemas
              fácilmente.
            </p>
            <div className="cIcons">
              <a href="">
                <i class="fab fa-github-square"></i>
              </a>
              <a href="https://www.facebook.com/drego44/">
                <i class="fab fa-facebook"></i>
              </a>
            </div>
          </div>
        </div>
      </div>
      <Footer />
    </>
  );
};
