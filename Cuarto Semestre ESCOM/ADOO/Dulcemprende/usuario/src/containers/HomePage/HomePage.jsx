import React, {useState} from 'react'
import Main from '../../components/Main/Main'
import Navbar from '../../components/Navbar/Navbar'
import Sidebar from '../../components/Sidebar/Sidebar'


const HomePage = (props) => {
  let element = "Inicio"
  const [sidebarOpen, setSidebarOpen] = useState(false)
  const openSidebar = () => {
    setSidebarOpen(true)
  }

  const closeSidebar = () => {
    setSidebarOpen(false)
  }



  return(
    <div className="container">
      <Navbar sidebarOpen={setSidebarOpen} openSidebar={openSidebar} element={element}/>
      <Main />
      <Sidebar sidebarOpen={sidebarOpen} closeSidebar={closeSidebar} element={element} />
    </div>

   )

 }

export default HomePage