import React, { useState } from 'react'
import { AboutCreators } from '../../components/AboutCreators/AboutCreators'
import Sidebar from "../../components/Sidebar/Sidebar";
import Navbar from "../../components/Navbar/Navbar";


const Creators = () => {
    let element = "Sobre los creadores";
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
                <AboutCreators />
            </main>
        <Sidebar
            sidebarOpen={sidebarOpen}
            closeSidebar={closeSidebar}
            element={element}
        />
    </div>
  );
    
}

export default Creators
