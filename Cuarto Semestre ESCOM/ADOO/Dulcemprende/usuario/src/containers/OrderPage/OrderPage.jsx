import React, { useEffect, useState } from "react";
import { useDispatch, useSelector } from "react-redux";
import { Link } from "react-router-dom";
import { getOrders } from "../../actions";
import Layout from "../../components/Layout/Layout";
import { generatePublicUrl } from "../../urlConfig";
import Sidebar from "../../components/Sidebar/Sidebar";
import Navbar from "../../components/Navbar/Navbar";
import "./style.css";
let tot = 0;
const OrderPage = (props) => {
  let element = "Tienda";
  const [sidebarOpen, setSidebarOpen] = useState(false);
  const openSidebar = () => {
    setSidebarOpen(true);
  };

  const closeSidebar = () => {
    setSidebarOpen(false);
  };
  const dispatch = useDispatch();
  const user = useSelector((state) => state.user);
  const [total, setTotal] = useState();
  useEffect(() => {
    dispatch(getOrders());
  }, []);

  console.log(user);
  const handleTotal = () => {
    {
      user.orders.map((order) => {
        order.items.map((item, key) => {
          tot = tot + item.payablePrice * item.purchasedQty;
        });
      });
    }
    setTotal(tot);
    tot = 0;
    console.log(total);
  };
  console.log(user);

  return (
    <div className="container">
      <Navbar
        sidebarOpen={setSidebarOpen}
        openSidebar={openSidebar}
        element={element}
      />

      <main>
        <Layout>
          <div className="small-container">
          <h1>Ordenes</h1>

          </div>
          <div className="fle">
            {user.orders.map((order) => {
              return order.items.map((item, key) => (
                <div className="small-container" key={key}>
                  <div className="row">
                  <Link
                    to={`/order_details/${order._id}`}
                    className="col-4"
                  >
                      <img
                        src={generatePublicUrl(
                          item.productId.productPictures[0].img
                        )}
                      />
                      <h4>{item.productId.name}</h4>
                      <p>
                        {item.payablePrice * item.purchasedQty} MXN
                      </p>
                      <p>
                        Orden ID: {order._id}
                      </p>
                  </Link>
                  </div>

                </div>
              ));
            })}
         
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

export default OrderPage;
