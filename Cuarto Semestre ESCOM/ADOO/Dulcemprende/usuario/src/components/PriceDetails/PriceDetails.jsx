import React from "react";
import "./style.css"

const PriceDetails = (props) => {
  return (

    <div className="total-price">
            <table>
              <tr>
                <td>Subtotal</td>
                <td>{props.totalPrice}</td>
              </tr>
              <tr>
                <td>Envio</td>
                <td>{props.totalPrice > 800 ? "Envio gratis" : "99MXN"}</td>
              </tr>
              <tr>
                <td>Total</td>
                <td>{props.totalPrice > 800 ? props.totalPrice : props.totalPrice+99}</td>
              </tr>
            </table>

          </div>
  );
};

export default PriceDetails;
