import React, { useState } from 'react'
import './style.css'
import Sidebar from "../../components/Sidebar/Sidebar";
import Navbar from "../../components/Navbar/Navbar";
import About from '../../components/About/About';


const AboutPage = () => {
    let element = "Sobre Dulcemprende";
    const [sidebarOpen, setSidebarOpen] = useState(false);
    const openSidebar = () => {
      setSidebarOpen(true);
    };
  
    const closeSidebar = () => {
      setSidebarOpen(false);
    };
    return (

        <div className="container">
            <Navbar
            sidebarOpen={setSidebarOpen}
            openSidebar={openSidebar}
            element={element}
            />

            <main>
                <About />
            </main>
            <Sidebar
            sidebarOpen={sidebarOpen}
            closeSidebar={closeSidebar}
            element={element}
            />
      </div>
    )
}

export default AboutPage
