import React, {useState, useRef} from 'react'
import { useSelector } from "react-redux";
import firebase from 'firebase/app'
import 'firebase/firestore'
import {useCollectionData} from 'react-firebase-hooks/firestore'
import man from '../../images/hombre.svg'
import Sidebar from '../../components/Sidebar/Sidebar'
import Navbar from '../../components/Navbar/Navbar'
import './style.css'

firebase.initializeApp({
    apiKey: "AIzaSyBhl1ZuhkejVMIF1K86vLDMvet9MerueDQ",
    authDomain: "dulcemprendechat.firebaseapp.com",
    projectId: "dulcemprendechat",
    storageBucket: "dulcemprendechat.appspot.com",
    messagingSenderId: "635514364221",
    appId: "1:635514364221:web:28ee7e691f3c8502a82554",
    measurementId: "G-00CF81F09M"
})

const firestore = firebase.firestore()

const Chat = () => {
    let element = "Chat"
    const [sidebarOpen, setSidebarOpen] = useState(false)
    const openSidebar = () => {
      setSidebarOpen(true)
    }
  
    const closeSidebar = () => {
      setSidebarOpen(false)
    }
  



  const auth = useSelector((state) => state.auth);

    return (
    <>
    <div className="container">
      <Navbar sidebarOpen={setSidebarOpen} openSidebar={openSidebar} element={element}/>

    <main>
    <div className="App">

            <article>
                {auth.authenticate ? <ChatComponent /> : <h1>Debes de tener una cuenta para comenzar a chatear!</h1> }
            </article>
        </div>
    </main>
    <Sidebar sidebarOpen={sidebarOpen} closeSidebar={closeSidebar} element={element} />

    </div>
   
   
    </>
    )
}

const ChatComponent = () =>{

    const uRef = useRef()
    const auth = useSelector((state) => state.auth);
    const messagesRef = firestore.collection('messages')
    const query = messagesRef.orderBy('createdAt').limit(25);
    const [messages] = useCollectionData(query, {idField: 'id'})
    console.log(messages);
    const [formValue, setformValue] = useState()
    const sendMessage = async(e) => {
        e.preventDefault()

        const { _id } = auth.user
        
        await messagesRef.add({
            text: formValue,
            createdAt: firebase.firestore.FieldValue.serverTimestamp(),
            _id
        })

        setformValue('')
        uRef.current.scrollIntoView({ behavior: 'smooth' })
    }    
    return (
        <>
            <main className="chatMain">
                <h1>Iniciaste sesión como {auth.user.fullName}</h1>
                <div className="divisor"></div>
                {messages && messages.map(msg => <ChatMessage key={msg.id} message={msg} />)}
                <div ref={uRef}></div>
                <span ref={uRef}></span>
            </main>
            <form onSubmit={sendMessage} className="chatForm">
                <input value={formValue} onChange={(e) => setformValue(e.target.value)} className="chatInput"/>
                <button type="submit" className="chatButton">🍬</button>
            </form>
        </>
    )
}

const ChatMessage= (props) => {
  const auth = useSelector((state) => state.auth);

    const { text, uid } = props.message 
    console.log(auth);
    const messageClass = uid === auth.user._id ? 'sent' : 'received'
    return(
       <div className={`message ${messageClass}`}>
           <img src={man} />
           <p className="para">{text}</p>

       </div>
    )

}
export default Chat
