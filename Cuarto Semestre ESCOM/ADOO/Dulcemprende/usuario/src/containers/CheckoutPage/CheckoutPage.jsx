import React, { useEffect, useState, useRef } from "react";
import { useDispatch, useSelector } from "react-redux";
import { addOrder, getAddress, getCartItems } from "../../actions";
import Layout from "../../components/Layout/Layout";
import { Anchor, MaterialButton } from "../../components/MaterialUI/MaterialUI";
import PriceDetails from "../../components/PriceDetails/PriceDetails";
import Card from "../../components/UI/Card/Card";
import CartPage from "../CartPage/CartPage";
import AddressForm from "./AddressForm";
import PayPal from "../../components/Paypal/PayPal";
import Sidebar from "../../components/Sidebar/Sidebar";
import Navbar from "../../components/Navbar/Navbar";
import "./style.css";

let total;

const CheckoutStep = (props) => {
  return (
    <div className="checkoutStep">
      <div
        onClick={props.onClick}
        className={`checkoutHeader ${props.active && "active"}`}
      >
        <div>
          <span className="stepNumber">{props.stepNumber}</span>
          <span className="stepTitle">{props.title}</span>
        </div>
      </div>
      {props.body && props.body}
    </div>
  );
};

const Address = ({
  adr,
  selectAddress,
  enableAddressEditForm,
  confirmDeliveryAddress,
  onAddressSubmit,
}) => {
  return (
    <div className="addressContainer">
      <div>
        <input name="address" onClick={() => selectAddress(adr)} type="radio" />
      </div>
      <div className="flexRow sb addressinfo">
        {!adr.edit ? (
          <div style={{ width: "100%" }}>
            <div className="addressDetail">
              <div>
                <span className="addressName">{adr.name}</span>
                <span className="addressType">{adr.addressType}</span>
                <span className="addressMobileNumber">{adr.mobileNumber}</span>
              </div>
              {adr.selected && (
                <Anchor
                  name="Editar"
                  onClick={() => enableAddressEditForm(adr)}
                  style={{
                    fontWeight: "500",
                    color: "#2874f0",
                  }}
                />
              )}
            </div>
            <div className="fullAddress">
              {adr.address} <br /> {`${adr.state} - ${adr.pinCode}`}
            </div>
            {adr.selected && (
              <MaterialButton
                title="Enviar a esta dirección"
                onClick={() => confirmDeliveryAddress(adr)}
                style={{
                  width: "200px",
                  margin: "10px 0",
                }}
              />
            )}
          </div>
        ) : (
          <AddressForm
            withoutLayout={true}
            onSubmitForm={onAddressSubmit}
            initialData={adr}
            onCancel={() => {}}
          />
        )}
      </div>
    </div>
  );
};

const CheckoutPage = (props) => {
  let element = "Tienda";
  const [sidebarOpen, setSidebarOpen] = useState(false);
  const openSidebar = () => {
    setSidebarOpen(true);
  };

  const closeSidebar = () => {
    setSidebarOpen(false);
  };
  const user = useSelector((state) => state.user);
  const auth = useSelector((state) => state.auth);
  const [newAddress, setNewAddress] = useState(false);
  const [address, setAddress] = useState([]);
  const [confirmAddress, setConfirmAddress] = useState(false);
  const [selectedAddress, setSelectedAddress] = useState(null);
  const [orderSummary, setOrderSummary] = useState(false);
  const [orderConfirmation, setOrderConfirmation] = useState(false);
  const [paymentOption, setPaymentOption] = useState(false);
  const [confirmOrder, setConfirmOrder] = useState(false);
  const [paypalButtons, setPaypalButtons] = useState(false);
  const cart = useSelector((state) => state.cart);
  const dispatch = useDispatch();

  const onAddressSubmit = (addr) => {
    setSelectedAddress(addr);
    setConfirmAddress(true);
    setOrderSummary(true);
  };

  const selectAddress = (addr) => {
    //console.log(addr);
    const updatedAddress = address.map((adr) =>
      adr._id === addr._id
        ? { ...adr, selected: true }
        : { ...adr, selected: false }
    );
    setAddress(updatedAddress);
  };

  const confirmDeliveryAddress = (addr) => {
    setSelectedAddress(addr);
    setConfirmAddress(true);
    setOrderSummary(true);
  };

  const enableAddressEditForm = (addr) => {
    const updatedAddress = address.map((adr) =>
      adr._id === addr._id ? { ...adr, edit: true } : { ...adr, edit: false }
    );
    setAddress(updatedAddress);
  };

  const userOrderConfirmation = () => {
    setOrderConfirmation(true);
    setOrderSummary(false);
    setPaymentOption(true);
  };

  const onConfirmOrder = () => {
    const totalAmount = Object.keys(cart.cartItems).reduce(
      (totalPrice, key) => {
        const { price, qty } = cart.cartItems[key];
        return totalPrice + price * qty;
      },
      0
    );
    const items = Object.keys(cart.cartItems).map((key) => ({
      productId: key,
      payablePrice: cart.cartItems[key].price,
      purchasedQty: cart.cartItems[key].qty,
    }));
    const payload = {
      addressId: selectedAddress._id,
      totalAmount,
      items,
      paymentStatus: "pending",
      paymentType: "paypal",
    };

    console.log(payload);
    dispatch(addOrder(payload));
    setConfirmOrder(true);
  };

  useEffect(() => {
    auth.authenticate && dispatch(getAddress());
    auth.authenticate && dispatch(getCartItems());
  }, [auth.authenticate]);

  useEffect(() => {
    const address = user.address.map((adr) => ({
      ...adr,
      selected: false,
      edit: false,
    }));
    setAddress(address);
    //user.address.length === 0 && setNewAddress(true);
  }, [user.address]);

  useEffect(() => {
    if (confirmOrder && user.placedOrderId) {
      props.history.push(`/order_details/${user.placedOrderId}`);
    }
  }, [user.placedOrderId]);

  return (
    <div className="container">
      <Navbar
        sidebarOpen={setSidebarOpen}
        openSidebar={openSidebar}
        element={element}
      />

      <main>
        <Layout>
          <div className="cartContainer" style={{alignItems: "center" }}>
            <div className="checkoutContainer">
              {/* check if user logged in or not */}
              <CheckoutStep
                stepNumber={"1"}
                title={"Inicia sesión"}
                active={!auth.authenticate}
                body={
                  auth.authenticate ? (
                    <div className="loggedInId">
                      <span style={{ fontWeight: 500 }}>
                        {auth.user.fullName}
                      </span>
                      <span style={{ margin: "0 5px" }}>{auth.user.email}</span>
                    </div>
                  ) : (
                    <div>
                      <p>Debes iniciar sesión</p>
                    </div>
                  )
                }
              />
              <CheckoutStep
                stepNumber={"2"}
                title={"Dirección de envio"}
                active={!confirmAddress && auth.authenticate}
                body={
                  <>
                    {confirmAddress ? (
                      <div className="stepCompleted">{`${selectedAddress.name} ${selectedAddress.address} - ${selectedAddress.pinCode}`}</div>
                    ) : (
                      address.map((adr) => (
                        <Address
                          selectAddress={selectAddress}
                          enableAddressEditForm={enableAddressEditForm}
                          confirmDeliveryAddress={confirmDeliveryAddress}
                          onAddressSubmit={onAddressSubmit}
                          adr={adr}
                        />
                      ))
                    )}
                  </>
                }
              />

              {/* AddressForm */}
              {confirmAddress ? null : newAddress ? (
                <AddressForm
                  onSubmitForm={onAddressSubmit}
                  onCancel={() => {}}
                />
              ) : auth.authenticate ? (
                <CheckoutStep
                  stepNumber={"+"}
                  title={"Añadir dirección"}
                  active={false}
                  onClick={() => setNewAddress(true)}
                />
              ) : null}

              <CheckoutStep
                stepNumber={"3"}
                title={"Resumen de orden"}
                active={orderSummary}
                body={
                  orderSummary ? (
                    <CartPage onlyCartItems={true} />
                  ) : orderConfirmation ? (
                    <div className="stepCompleted">
                      {Object.keys(cart.cartItems).length} items
                    </div>
                  ) : null
                }
              />

              {orderSummary && (
                <Card
                  style={{
                    margin: "10px 0",
                  }}
                >
                  <div
                    className="flexRow sb"
                    style={{
                      padding: "20px",
                      alignItems: "center",
                    }}
                  >
                    <p style={{ fontSize: "12px" }}>
                      La confirmación será enviada a{" "}
                      <strong>{auth.user.email}</strong>
                    </p>
                    <MaterialButton
                      title="Continuar"
                      onClick={userOrderConfirmation}
                      style={{
                        width: "200px",
                      }}
                    />
                  </div>
                </Card>
              )}

              <CheckoutStep
                stepNumber={"4"}
                title={"Opciones de pago"}
                active={paymentOption}
                body={
                  paymentOption && (
                    <div>
                      <div
                        className="flexRow"
                        style={{
                          alignItems: "center",
                          padding: "20px",
                        }}
                      >
                        <input
                          type="radio"
                          name="paymentOption"
                          value="paypal"
                          onClick={() => setPaypalButtons(true)}
                        />
                        <div>Paypal</div>
                        {paypalButtons ? (
                          <PayPal onConfirmOrder={onConfirmOrder} />
                        ) : (
                          ""
                        )}
                      </div>
                      <MaterialButton
                        title="Confirmar orden"
                        onClick={onConfirmOrder}
                        style={{
                          width: "200px",
                          margin: "0 0 20px 20px",
                        }}
                      />
                    </div>
                  )
                }
              />
            </div>

            {/* Price Component */}
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
          </div>
          <br />
          <br />
          <br />
          <br />
          <br />
          <br />
          <br />
          <br />
          <br />
          <br />
          <br />
          <br />
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

export default CheckoutPage;
