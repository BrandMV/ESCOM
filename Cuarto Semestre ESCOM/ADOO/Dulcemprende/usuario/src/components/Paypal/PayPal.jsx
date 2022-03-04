import React, {useRef, useEffect} from 'react'
import { useSelector } from 'react-redux'

const PayPal = ({ onConfirmOrder }) => {
    const cart = useSelector((state) => state.cart);
    let total
    const paypal = useRef()

    useEffect(() => {
      {total = Object.keys(cart.cartItems).reduce((totalPrice, key) => {
        const { price, qty } = cart.cartItems[key];
        return totalPrice + price * qty
      }, 0)}
      window.paypal.Buttons({
        createOrder: (data, actions, err) => {
          return actions.order.create({
            intent: "CAPTURE",
            purchase_units:[
              {
                description: "Compra de dulces",
                amount: {
                  currency_code: "MXN",
                  value: total
                }
              }
            ]
          })
        },
        onApprove: async (data, actions) => {
          const order = await actions.order.capture()
          onConfirmOrder()
        },
        onError: (err) => {
          console.log(err);
        }
      })
      .render(paypal.current)
    }, [])


    return (
        <div>
            <div ref={paypal}></div>
        </div>
    )
}

export default PayPal
