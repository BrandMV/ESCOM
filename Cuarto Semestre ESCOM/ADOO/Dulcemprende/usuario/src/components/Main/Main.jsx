import React, { useState, useEffect } from "react";
import "./main.css";
import "./nonLogged.css";
import { addStatistics, getOrders, getStatistics } from "../../actions";
import { useDispatch, useSelector } from "react-redux";
import mano from "../../images/mano.svg"
import chat from "../../images/chat.svg"
import shopping from "../../images/shopping.svg"
import admin from "../../images/admin.svg"
import Footer from "../Footer/Footer";
import MainNonLogged from "../MainNonLogged/MainNonLogged";
let tot = 0;
let tot2 = 0;
let earn = 0;
let totSell = 0;
let profit = 0
const Main = () => {
  const auth = useSelector((state) => state.auth);
  const dispatch = useDispatch();
  const [sell, setSell] = useState();
  const [earned, setEarned] = useState(0);
  const user = useSelector((state) => state.user);
  const [invest, setInvest] = useState();
  const [lastInvest, setLastInvest] = useState(0);
  const [totalSell, setTotalSell] = useState(0);
  useEffect(() => {
    dispatch(getOrders());
    dispatch(getStatistics())
  }, []);
  console.log(user);

const onSubmitStatistics = () => {
  let profit = totSell
  let selled = earn
  const payload = {
    statistics: {
      invest,
      profit,
      selled,
    },
  }
  console.log(payload);
  dispatch(addStatistics(payload))
}

  useEffect(() => {
    {
      user.orders.map((order) => {
        order.items.map((item, key) => {
          tot = tot + item.payablePrice * item.purchasedQty;
          tot2 = item.payablePrice * item.purchasedQty;
        });
      });
    }
    setInvest(tot);
    setLastInvest(tot2);

    setTotalSell(
      JSON.parse(localStorage.getItem(`${auth.user._id} total vendido`))
    );
    earn = JSON.parse(localStorage.getItem(`${auth.user._id} ganancias`));
    setEarned(earn);
    console.log(tot, earn);

    tot = 0;
  }, [user.orders]);

  const handleBenefits = (e) => {
    e.preventDefault();
    totSell = totalSell + parseFloat(sell);
    setTotalSell(totSell);
    earn = totSell - invest;
    setEarned(earn);

    console.log(earned, totalSell);
    localStorage.setItem(`${auth.user._id} ganancias`, JSON.stringify(earn));
    localStorage.setItem(
      `${auth.user._id} total vendido`,
      JSON.stringify(totSell)
    );
    setSell("");
    onSubmitStatistics()
  };
  const handleUpdateEarned = () => {
    setTotalSell(
      JSON.parse(localStorage.getItem(`${auth.user._id} total vendido`))
    );

    earn = totalSell - invest;
    setEarned(earn);
    localStorage.setItem(`${auth.user._id} ganancias`, JSON.stringify(earn));
  };
  console.log(auth);

  const loggedInMain = () => {
    return (
      <div className="main__container">
        <div className="main__title">
          <div className="main__greeting">
            <h1>Hola {auth.user.fullName}</h1>
            <p>Bienvenido a Dulcemprende. Administra tu emprendimiento!</p>
          </div>
        </div>
        <div className="main__cards">
          <div className="card">
            <i className="fa fa-user fa-2x text-lightblue"></i>
            <div className="card_inner">
              <p className="text-primary-p">Vendido: </p>
              <form onSubmit={handleBenefits}>
                <span>
                  <input
                    value={sell}
                    type="number"
                    onChange={(e) => setSell(e.target.value)}
                  />
                </span>
                <button type="submit">💸</button>
              </form>
            </div>
          </div>
        </div>

        <div className="charts">
          <div className="charts__left">
            <div className="charts__left__title">
              <div>
                <h1>Ventas</h1>
                <p>Tu emprendimiento</p>
              </div>
              <i className="fas fa-dollar-sign"></i>
            </div>

            <div>
              <div className="card1">
                <h1>Inversión Total</h1>
                <h3>{invest} MXN</h3>
              </div>
              <div className="card2">
                <h1>Última Inversión</h1>
                <h3>{lastInvest} MXN</h3>
              </div>
            </div>
          </div>
          <div className="charts__right">
            <div className="charts__right__title">
              <div>
                <h1>Estadisticas</h1>
                <p>Asi va tu negocio!</p>
              </div>
              <i className="fas fa-dollar-sign"></i>
            </div>

            <div className="charts__right__cards">
              <div className="card3">
                <h1>Total vendido</h1>
                <h3>{totalSell} MXN</h3>
              </div>
              <div className="card4">
                <h1>Ganancias</h1>
                <h3>{earned} MXN</h3>
                <button onClick={handleUpdateEarned}>Actualizar</button>
              </div>
            </div>
          </div>
        </div>
      </div>
    );
  };

  const nonLoggedInMain = () => {
    return (
      <MainNonLogged />

    )
  };

  return <main>{auth.authenticate ? loggedInMain() : nonLoggedInMain()}</main>;
};

export default Main;
