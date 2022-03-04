import React, { useEffect } from "react";
import "./App.css";
import { BrowserRouter as Router, Route, Switch } from "react-router-dom";
import HomePage from "./containers/HomePage/HomePage";
import ProductListPage from "./containers/ProductListPage/ProductListPage";
import { useDispatch, useSelector } from "react-redux";
import { isUserLoggedIn, updateCart } from "./actions";
import ProductDetailsPage from "./containers/ProductDetailsPage/ProductDetailsPage";
import CartPage from "./containers/CartPage/CartPage";
import CheckoutPage from "./containers/CheckoutPage/CheckoutPage";
import OrderPage from "./containers/OrderPage/OrderPage";
import OrderDetailsPage from "./containers/OrderDetailsPage/OrderDetailsPage";
import HomeStore from "./containers/HomeStore/HomeStore";
import Chat from "./containers/Chat/Chat";
import AboutPage from "./containers/AboutPage/AboutPage";
import Creators from "./containers/Creators/Creators";

function App() {
  const dispatch = useDispatch();
  const auth = useSelector((state) => state.auth);

  useEffect(() => {
    if (!auth.authenticate) {
      dispatch(isUserLoggedIn());
    }
  }, [auth.authenticate]);

  useEffect(() => {
    console.log("App.js - updateCart");
    dispatch(updateCart());
  }, [auth.authenticate]);

  return (
    <div>
      <Router>
        <Switch>
          <Route path="/" exact component={HomePage} />
          <Route path="/store" component={HomeStore} />
          <Route path="/chat" component={Chat} />
          <Route path="/about" component={AboutPage} />
          <Route path="/about-creators" component={Creators} />
          <Route path="/cart" component={CartPage} />
          <Route path="/checkout" component={CheckoutPage} />
          <Route path="/account/orders" component={OrderPage} />
          <Route path="/order_details/:orderId" component={OrderDetailsPage} />
          <Route
            path="/:productSlug/:productId/p"
            component={ProductDetailsPage}
          />
          <Route path="/:slug" component={ProductListPage} />
        </Switch>
      </Router>
    </div>
  );
}

export default App;
