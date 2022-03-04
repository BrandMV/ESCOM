import React, { useState } from "react";
import "./style.css";
import { generatePublicUrl } from "../../../urlConfig";


const CartItem = (props) => {
  const [qty, setQty] = useState(props.cartItem.qty);

  const { _id, name, price, img } = props.cartItem;
  console.log(img);

  const onQuantityIncrement = () => {
    setQty(qty + 1);
    props.onQuantityInc(_id, qty + 1);
  };

  const onQuantityDecrement = () => {
    if (qty == 0) return;
    setQty(qty - 1);
    props.onQuantityDec(_id, qty - 1);
  };

  return (
      <tr>
        <td>
          <div className="cart-info">
            <img src={generatePublicUrl(img)} alt={""} />
            <div>
              <p>{name}</p>
              <small>Precio: {price}MXN</small>
              <br />
              <a onClick={() => props.onRemoveCartItem(_id)}>Eliminar</a>
            </div>
          </div>
        </td>
        <td>
        <div className="quantityControl">
             <button onClick={onQuantityDecrement}>-</button>
             <input value={qty} readOnly />
             <button onClick={onQuantityIncrement}>+</button>
           </div>
        </td>
        <td>{qty*price}</td>
      </tr>
  );
};

export default CartItem;
