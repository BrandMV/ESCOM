import React from 'react';
import Header from '../Header/Header';
import { Container, Row, Col } from 'react-bootstrap'; 
import { NavLink } from 'react-router-dom';
import './style.css';

const Layout = (props) => {
  return(
    <>
       <Header />
       {
         props.sidebar ?
         <Container fluid>
          <Row>
            <Col md={2} className="sidebar">
              <ul>
                <li><NavLink to={`/category`}><i className="fas fa-stream"></i> Categorias</NavLink></li>
                <li><NavLink to={`/products`}><i className="fas fa-candy-cane"></i> Productos</NavLink></li>
                <li><NavLink to={`/orders`}><i className="fas fa-shopping-cart"></i> Ordenes</NavLink></li>
              </ul>
            </Col>
            <Col md={10} style={{ marginLeft: 'auto', paddingTop: '60px' }}>
              {props.children}
            </Col>
          </Row>
        </Container>
        :
        props.children
       }
        
        
    </>
   )

 }

export default Layout;