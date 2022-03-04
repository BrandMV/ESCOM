import React, { useState, useEffect } from 'react';
import Layout from '../../components/Layout/Layout';
import { Container, Form, Row, Col, Button } from 'react-bootstrap';
import Input from '../../components/UI/Input/Input';
import { login } from '../../actions';
import { useDispatch, useSelector } from 'react-redux';
import { Redirect } from 'react-router-dom';

const Signin = (props) => {

    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const auth = useSelector(state => state.auth);
    const user = useSelector(state => state.user);
    console.log(user);
    const dispatch = useDispatch();

    


    const userLogin = (e) => {

        e.preventDefault();

        const user = {
            email, password
        }

        dispatch(login(user));
    }

    if(auth.authenticate){
        return <Redirect to={`/`} />
    }

    return (
        <Layout sidebar>
            <Container style={{marginLeft: "10px"}}>
                <Row style={{ marginTop: '50px', fontSize: 30 }}>
                    <Col md={{span: 6, offset: 3}}>
                        <Form onSubmit={userLogin}>
                            <Input 
                                label="Correo"
                                placeholder="Correo"
                                value={email}
                                type="email"
                                onChange={(e) => setEmail(e.target.value)}
                            />

                            <Input 
                                label="Contraseña"
                                placeholder="Contraseña"
                                value={password}
                                type="password"
                                onChange={(e) => setPassword(e.target.value)}
                            />
                            <Button variant="primary" type="submit">
                                Inciar sesión
                            </Button>
                        </Form>
                        {user.message}

                    </Col>
                </Row>
                
            </Container>
        </Layout>
    )

}

export default Signin