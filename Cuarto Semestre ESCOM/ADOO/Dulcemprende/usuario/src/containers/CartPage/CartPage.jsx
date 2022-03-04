import React, { useEffect, useState } from "react";
import { useDispatch, useSelector } from "react-redux";
import Layout from "../../components/Layout/Layout";
import CartItem from "./CartItem/CartItem";
import { addToCart, getCartItems, removeCartItem } from "../../actions";
import PriceDetails from "../../components/PriceDetails/PriceDetails";
import Sidebar from "../../components/Sidebar/Sidebar";
import Navbar from "../../components/Navbar/Navbar";
import "./style.css";
import { MaterialButton } from "../../components/MaterialUI/MaterialUI";

const CartPage = (props) => {
  let element = "Tienda";
  const [sidebarOpen, setSidebarOpen] = useState(false);
  const openSidebar = () => {
    setSidebarOpen(true);
  };

  const closeSidebar = () => {
    setSidebarOpen(false);
  };
  const cart = useSelector((state) => state.cart);
  const auth = useSelector((state) => state.auth);
  // const cartItems = cart.cartItems;
  const [cartItems, setCartItems] = useState(cart.cartItems);
  const dispatch = useDispatch();
  const [price, setPrice] = useState();

  const [qty, setQty] = useState(cartItems.qty);

  // const { _id, name, price, img } = cartItem;

  const onQuantityIncrementC = () => {
    setQty(qty + 1);
    onQuantityIncrement(cartItems._id, qty + 1);
  };

  const onQuantityDecrementC = () => {
    if (qty <= 1) return;
    setQty(qty - 1);
    onQuantityDecrement(cartItems._id, qty - 1);
  };

  useEffect(() => {
    setCartItems(cart.cartItems);
  }, [cart.cartItems]);

  useEffect(() => {
    if (auth.authenticate) {
      dispatch(getCartItems());
    }
  }, [auth.authenticate]);

  const onQuantityIncrement = (_id) => {
    //console.log({_id, qty});
    const { name, price, img } = cartItems[_id];
    dispatch(addToCart({ _id, name, price, img }, 1));
  };

  const onQuantityDecrement = (_id) => {
    const { name, price, img } = cartItems[_id];
    dispatch(addToCart({ _id, name, price, img }, -1));
  };

  const onRemoveCartItem = (_id) => {
    dispatch(removeCartItem({ productId: _id }));
  };

  if (props.onlyCartItems) {
    return (
      <>
        {Object.keys(cartItems).map((key, index) => (
          <CartItem
            key={index}
            cartItem={cartItems[key]}
            onQuantityInc={onQuantityIncrement}
            onQuantityDec={onQuantityDecrement}
          />
        ))}
      </>
    );
  }

  return (
    <div className="container">
      <Navbar
        sidebarOpen={setSidebarOpen}
        openSidebar={openSidebar}
        element={element}
      />

      <main>
        <Layout>
          <br />
          <br />
          <br />
          <div className="small-container cart-page">
            <table>
              <tr>
                <th>Producto</th>
                <th>Cantidad</th>
                <th>Total</th>
              </tr>
              {Object.keys(cartItems).map((key, index) => (
                <CartItem
                  key={index}
                  cartItem={cartItems[key]}
                  onQuantityInc={onQuantityIncrement}
                  onQuantityDec={onQuantityDecrement}
                  onRemoveCartItem={onRemoveCartItem}
                />
              ))}
            </table>
            <PriceDetails
              totalItem={Object.keys(cart.cartItems).reduce(function (
                qty,
                key
              ) {
                return qty + cart.cartItems[key].qty;
              },
              0)}
              totalPrice={Object.keys(cart.cartItems).reduce(
                (totalPrice, key) => {
                  const { price, qty } = cart.cartItems[key];
                  return totalPrice + price * qty;
                },
                0
              )}
            />
            <br />
            <br />

            <MaterialButton
              title="Pagar"
              onClick={() => props.history.push(`/checkout`)}
            />
          </div>
          <br />
          <br />
          <br />
          <br />
          <br />
          <br />
        </Layout>
      </main>
      <Sidebar
        sidebarOpen={sidebarOpen}
        closeSidebar={closeSidebar}
        element={element}
      />
    </div>
  );
};

export default CartPage;
