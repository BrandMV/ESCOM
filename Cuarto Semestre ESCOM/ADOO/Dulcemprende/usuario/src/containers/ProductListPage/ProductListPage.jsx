import React, { useState } from "react";
import Layout from "../../components/Layout/Layout";
import getParams from "../../utils/getParams";
import ProductStore from "./ProductStore/ProductStore";
import "./style.css";
import Sidebar from "../../components/Sidebar/Sidebar";
import Navbar from "../../components/Navbar/Navbar";

const ProductListPage = (props) => {
  let element = "Tienda";
  const [sidebarOpen, setSidebarOpen] = useState(false);
  const openSidebar = () => {
    setSidebarOpen(true);
  };

  const closeSidebar = () => {
    setSidebarOpen(false);
  };

  const renderProduct = () => {
    console.log(props);
    const params = getParams(props.location.search);
    let content = null;
    switch (params.type) {
      case "store":
        content = <ProductStore {...props} />;
        break;
    }

    return content;
  };

  return (
    <div className="container">
      <Navbar
        sidebarOpen={setSidebarOpen}
        openSidebar={openSidebar}
        element={element}
      />

      <main>
        <Layout>{renderProduct()}</Layout>
      </main>
      <Sidebar
        sidebarOpen={sidebarOpen}
        closeSidebar={closeSidebar}
        element={element}
      />
    </div>
  );
};

export default ProductListPage;
