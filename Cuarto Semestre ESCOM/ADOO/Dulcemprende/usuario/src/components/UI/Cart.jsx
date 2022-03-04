import React from "react";
import { IoIosCart } from "react-icons/io";

const Cart = (props) => {
  return (
    <div style={{ fontSize: "20px", position: "relative" }}>
      <span
        style={{
          color: "white",
          position: "absolute",
          background: "#3ea175",
          width: "15px",
          height: "15px",
          borderRadius: "5px",
          fontSize: "11px",
          border: "1px solid #fff",
          textAlign: "center",
          alignSelf: "center",
          top: "-12px",
          right: "-6px",
        }}
      >
        {props.count}
      </span>
      <IoIosCart />
    </div>
  );
};

export default Cart;
