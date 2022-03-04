import React, { useState } from "react";
import Layout from "../../components/Layout/Layout";
import emprende from "../../images/emprende.svg";
import carlos from "../../images/carlos.jpg";
import mamut from "../../images/mamut.jpg";
import bubu from "../../images/bubu.jpg";
import duraz from "../../images/duraz.jpg";
import nusi from "../../images/nusi.jpg";
import roc from "../../images/roc.jpg";
import wa from "../../images/wa.jpg";
import boli from "../../images/boli.jpg";
import va from "../../images/va.jpg";
import paya from "../../images/paya.jpg";
import "./style.css";
import { Link } from "react-router-dom";
import dulces from "../../images/dulces.svg";
import Sidebar from "../../components/Sidebar/Sidebar";
import Navbar from "../../components/Navbar/Navbar";

const HomeStore = (props) => {
  let element = "Tienda";
  const [sidebarOpen, setSidebarOpen] = useState(false);
  const openSidebar = () => {
    setSidebarOpen(true);
  };

  const closeSidebar = () => {
    setSidebarOpen(false);
  };

  return (
    <>
      <div className="container">
        <Navbar
          sidebarOpen={setSidebarOpen}
          openSidebar={openSidebar}
          element={element}
        />

        <main>
          <Layout>
            <div className="headerStore">
              <div className="Hcontainer">
                <div className="row">
                  <div className="col-2">
                    <h1>Empieza a emprender con Dulcemprende!</h1>
                    <p>
                      El secreto de un gran negocio consiste en saber algo que
                      nadie más sabe. Aristoteles Onassis
                    </p>
                    <a href="#comienza" className="btn">
                      Comienza! <i class="fas fa-long-arrow-alt-right"></i>
                    </a>
                  </div>
                  <div className="col-2">
                    <img src={emprende} />
                  </div>
                </div>
              </div>
            </div>

            <div className="small-container">
              <h2 className="title" id="comienza">
                <Link
                  to={`Dulces-mas-vendidos-1N_KvLZYf?cid=60b5cb7788b9c648043e6374&type=store`}
                >
                  Productos Más Vendidos
                </Link>
              </h2>
              <div className="row">
                <div className="col-4">
                  <img src={mamut} alt="" />
                  <h4>Mini Mamut</h4>
                  <p>$33</p>
                </div>
                <div className="col-4">
                  <img src={carlos} alt="" />
                  <h4>Carlos V stick</h4>
                  <p>$23</p>
                </div>
                <div className="col-4">
                  <img src={bubu} alt="" />
                  <h4>Mini Bubulubu</h4>
                  <p>$45</p>
                </div>
                <div className="col-4">
                  <img src={duraz} alt="" />
                  <h4>Lucky Gummys Durazno</h4>
                  <p>$60</p>
                </div>
              </div>
            </div>

            <div className="small-container">
              <h2 className="title">
                <Link
                  to={`Dulces-mas-vendidos-1N_KvLZYf?cid=60b5cb7788b9c648043e6374&type=store`}
                >
                  Productos en Oferta
                </Link>
              </h2>
              <div className="row">
                <div className="col-4">
                  <img src={nusi} alt="" />
                  <h4>Nucita Chocolate-Vainillat</h4>
                  <p>$12</p>
                </div>
                <div className="col-4">
                  <img src={roc} alt="" />
                  <h4>Mini Rocko</h4>
                  <p>$33</p>
                </div>
                <div className="col-4">
                  <img src={paya} alt="" />
                  <h4>Paleta Payaso</h4>
                  <p>$74</p>
                </div>
                <div className="col-4">
                  <img src={wa} alt="" />
                  <h4>Galleta Wafer Chocolate</h4>
                  <p>$13</p>
                </div>
                <div className="col-4">
                  <img src={boli} alt="" />
                  <h4>Bolitochas Sandía</h4>
                  <p>$58</p>
                </div>
                <div className="col-4">
                  <img src={va} alt="" />
                  <h4>Galleta Wafer Vainilla</h4>
                  <p>$13</p>
                </div>
              </div>
            </div>

            <div className="offer">
              <div className="small-container">
                <div className="row">
                  <div className="col-2">
                    <img src={dulces} className="offer-img" />
                  </div>
                  <div className="col-2">
                    <h1>Dulces al mejor precio!</h1>
                  </div>
                </div>
              </div>
            </div>
            <div className="testimonial">
              <div className="small-container">
                <div className="row">
                  <div className="col-3">
                    <i class="fas fa-quote-right"></i>
                    <p>
                      Aprende del negocio. Muchos emprendedores primerizos
                      fallan en esos pequeños detalles de organización que son
                      críticos para un buen modelo de negocios. Cuando no puedes
                      traducir tus ideas al plano financiero y económico, corres
                      el riesgo de no poder replicar el éxito ni hacerte
                      entender por otros interesados.
                    </p>
                  </div>
                  <div className="col-3">
                    <i class="fas fa-quote-right"></i>
                    <p>
                      Rodéate de gente talentosa. Un buen emprendedor sabe sumar
                      a su causa el personal necesario para complementar su
                      visión. Hay que ser paciente para conseguir personas que
                      amen hacer lo que tú odias y también les apasione lo que
                      quieres lograr. No temas despedir a alguien si no están en
                      sintonía con tu misión y valores.
                    </p>
                  </div>
                  <div className="col-3">
                    <i class="fas fa-quote-right"></i>
                    <p>
                      Prepárate para los imprevistos. Para conseguir todos los
                      beneficios del emprendedurismo, debes saber que habrá
                      obstáculos por superar. Si bien no puedes controlarlo
                      todo, asegúrate de que el negocio pueda funcionar sin
                      tener que estar encima de cada situación. Lo ideal es
                      tener un balance entre tu vida personal y profesional.
                    </p>
                  </div>
                  <div className="col-3">
                    <i class="fas fa-quote-right"></i>
                    <p>
                      Abraza tu pasión. Por lo general, un emprendimiento
                      surgirá de aquello que te apasiona o que más llama tu
                      atención. Lo más difícil es mantener la llama viva con el
                      tiempo, así que debes asegurarte de nutrirla cada día.
                      Enfócate en los problemas de tus clientes y las razones
                      que te impulsaron a dar soluciones inteligentes.
                    </p>
                  </div>
                  <div className="col-3">
                    <i class="fas fa-quote-right"></i>
                    <p>
                      Escucha a tus futuros compradores. La clave para que una
                      empresa sea bien recibida en el mercado está en darle al
                      cliente lo que necesita. ¿Sólo eso? No. Lo ideal es
                      superar sus expectativas. Uno de los errores más comunes
                      es creer que tu negocio será un éxito sólo porque a ti te
                      gusta.
                    </p>
                  </div>
                  <div className="col-3">
                    <i class="fas fa-quote-right"></i>
                    <p>
                      Analiza a tu competencia. Según el Centro de Consultoría e
                      Innovación Empresarial y Financiera del Tecnológico de
                      Monterrey, ocho de cada 10 emprendedores pasan por alto a
                      los “competidores” como un factor a evaluar. Esto sucede
                      básicamente porque el empresario tiene una gran autoestima
                      y se olvida de que existen otros actores en el mercado.
                    </p>
                  </div>
                </div>
              </div>
            </div>
          </Layout>
        </main>
        <Sidebar
          sidebarOpen={sidebarOpen}
          closeSidebar={closeSidebar}
          element={element}
        />
      </div>
    </>
  );
};

export default HomeStore;
