import React from 'react'
import mano from "../../images/mano.svg"
import chat from "../../images/chat.svg"
import shopping from "../../images/shopping.svg"
import admin from "../../images/admin.svg"
import Footer from "../Footer/Footer";

const MainNonLogged = () => {
    return (
              <>
        <article className="home sect">
            <div className="content">
              <h3>¿Qué esperas para <span>emprender?</span></h3>
              <a href="#emprende" className="abtn">Emprende!</a>
            </div>
            <div className="image">
              <img src={mano} alt="mano" />
            </div>
          </article>
          <article className="features" id="features">
              <h1 className="heading" id="emprende">Disfruta de lo que ofrede Dulcemprende</h1>

              <div className="box-container">
                <div className="box">
                  <img src={shopping} alt="shopping" />
                  <h3>Compra al mejor precio!</h3>
                  <p>En Dulcemprende encontrarás los dulces más vendidos de México
                    al mejor precio para que puedas comenzar a emprender!
                  </p>
                </div>
                <div className="box">
                  <img src={admin} alt="hombre" />
                  <h3>Aministra tu emprendimiento!</h3>
                  <p>Dulcemprende te ofrece un apartado para que puedas admnistrar tu negocio.
                    Puedes ver cuanto has invertido, vendido, además de tus ganancias!
                  </p>
                </div>
                <div className="box">
                  <img src={chat} alt="chhat" />
                  <h3>Chatea!</h3>
                  <p>En Dulcemprende puedes unirte a un canal de chat donde puedes pedir o dar
                    consejos para comenzar a emprender!
                  </p>
                </div>
              </div>
          </article>
          <Footer />

      </>
    )
}

export default MainNonLogged
