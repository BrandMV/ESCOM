import React from 'react'
import './About.css'
import dulce from '../../images/dulce.svg'
import Footer from '../Footer/Footer'

const About = () => {
    return (
        <>
    <div className="sAbout">

  
        <div className="about" id="about">
            <h1 className="heading">Sobre Dulcemprende</h1>
            <div className="column">
                <div className="image">
                    <img src={dulce} alt="dulce" />
                </div>
                <div className="aContent">
                    <h3>Para aquellas personas emprendedoras</h3>
                    <p>Dulcemprende es una plataforma que te permite comenzar con un
                        emprendimiento del area de dulces, un mercado altamente demandado
                        y con futuro.
                    </p>
                    <p>Ofrecemos distintas herramientas como lo es un completo ecommerce,
                        un chat para que los usuarioas de Dulcemprende puedan compartir consejos,
                        ideas y recomendaciones. Además de un apartado de administración donde el
                        usuario puede ver lo que ha invertido, lo que ha ganado y lo que
                        ha vendido de su negocio propio.
                    </p>
                    <div className="buttons">
                        <a href="https://github.com/BrandMV/Dulcemprende" className="abtn"><i className="fab fa-github"></i>Repositorio de Github</a>
                    </div>
                </div>
            </div>
        </div>
        </div>
        <Footer />
        </>
    )
}

export default About
