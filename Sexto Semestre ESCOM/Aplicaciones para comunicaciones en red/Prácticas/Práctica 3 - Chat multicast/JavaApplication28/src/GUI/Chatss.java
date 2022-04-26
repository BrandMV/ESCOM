package GUI;


import Audio.JavaSoundRecorder;
import Audio.PlayWavFile;
import constants.Constants;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Mixer;
import javax.swing.*;
import javax.swing.plaf.FontUIResource;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author BrandMV
 */
public class Chatss extends JFrame{
    private JTabbedPane tabs;
    private JPanel panel;
    private JTextArea msg;
    private JButton btn;
    private ArrayList<String> chatsInTabs;
    private ArrayList<String> currentUsersString;
    private ArrayList<JButton> currentUsers;
    private ArrayList<JTextArea> privateChats;
    private JTextField chat;
    private static String userName;
    private JFrame window;
    private JScrollPane scroll;
    private int operation;
    private boolean connected;
    private int currentTab;
    private String currentMessage;
    private JScrollPane onlineUsers;
    private JPanel emojisPanel;
    private String sender;
    private String reciever;
    private String path;
    public Chatss(int op){
        operation = op;
        //* Asking username
        userName = JOptionPane.showInputDialog(null, Constants.USERNAME);
        //* Centring window
        Toolkit myScreen = Toolkit.getDefaultToolkit();
        Dimension screenSize = myScreen.getScreenSize();
        connected = true;

        window = new JFrame();
        window.setSize((screenSize.width / 2)+100,screenSize.height / 2);
        window.setLocation(screenSize.width / 4, screenSize.height / 4);
        System.out.println(screenSize.width / 2 + "altuura: " +  screenSize.height / 2);
        window.setResizable(true);
        window.setTitle(String.format(Constants.WINDOW_TITLE, userName));
        window.setLocationRelativeTo(null);
        window.setDefaultCloseOperation(EXIT_ON_CLOSE);
        userLeft();

        tabs = new JTabbedPane();
        emojisPanel = new JPanel(new GridLayout(5,4));
        currentUsers = new ArrayList();
        currentUsersString = new ArrayList();
        privateChats = new ArrayList();
        chatsInTabs = new ArrayList();
        initComponents();
        initEmojis();
        window.setVisible(true);
    }

    /**
     * Method that initialize the client GUI components
     */
    public void initComponents(){
        tabs.setBounds(5,10,750,450);
        JLabel usersSection = new JLabel(Constants.CURRENT_USERS);
        onlineUsers = new JScrollPane();
//        onlineUsers.setLayout(null);
        onlineUsers.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        onlineUsers.setBorder(BorderFactory.createEmptyBorder());
        panel = new JPanel();
        panel.setLayout(null);
        window.getContentPane().add(panel);
        panel.setBackground(new Color(255,246,234));
        usersSection.setBounds(830,10,200,10);
        panel.add(usersSection);
        onlineUsers.setBackground(new Color(255,246,234));
        onlineUsers.setBounds(780,35,240,300);
        addChat("Sala general");
        panel.add(tabs);
        btn = new JButton("Enviar");
        
        btn.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent ae){
                if(ae.getSource() == btn){
                    operation = 1;
//                    System.out.println("Opeacion pulsado  " + operation);
                }
            }
        });
        
        btn.setBounds(475,465,120,40);
        btn.setBackground(Color.WHITE);
        btn.setFont(new FontUIResource("Roboto", Font.BOLD, 20));
        panel.add(btn);
        chat = new JTextField();
        chat.setBounds(5,465,450,40);
        panel.add(chat);
        panel.add(onlineUsers);
        setAudio();
        setPlayAudio();
        setCurrentUsers();
    }

    /**
     * Method that set the Audio components
     */

    public void setAudio(){
        JButton audio = new JButton("Enviar audio");
        audio.setBounds(610,465,120,40);
        audio.setBackground(Color.WHITE);
        audio.setFont(new FontUIResource("Roboto", Font.BOLD, 15));
        
        audio.addActionListener(new ActionListener(){

            /**
             * The send audio button action listener will send the audio
             * @param ae the action event
             */
            @Override
            public void actionPerformed(ActionEvent ae){
                if(ae.getSource() == audio){
                    chat.setText("");
                    chat.setText("Audio enviado");
                    operation = 1;
                    DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd-MM-yyyy-HH-mm-ss");
                    LocalDateTime now = LocalDateTime.now();
                    String audioName = String.format(Constants.AUDIO_NAME, dtf.format(now),userName);
                    final JavaSoundRecorder recorder;
                    int tab = tabs.getSelectedIndex();
                    if(tab == 0){
                        recorder = new JavaSoundRecorder("Audios/General", audioName, true);
                    }else{
                        if(userName.equals(reciever)){
                            path = String.format(Constants.PATH_AUDIO_FORMAT, userName, chatsInTabs.get(tab));
                        }else{
                            path = String.format(Constants.PATH_AUDIO_FORMAT, chatsInTabs.get(tab), userName );
                        }
                           recorder = new JavaSoundRecorder(path,audioName, false);

                    }
                         try{
                          BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                            //Get and display a list of
                            // available mixers.
                          Mixer.Info[] mixerInfo = AudioSystem.getMixerInfo();
                          int micro = 5;
                        // creates a new thread that waits for a specified
                        // of time before stopping
                        Thread stopper = new Thread(new Runnable() {
                                public void run() {
                                        try {
                                                Thread.sleep(Constants.RECORD_TIME);
                                        } catch (InterruptedException ex) {
                                                ex.printStackTrace();
                                        }
                                        recorder.finish();
                                }
                        });
                        stopper.start();
                        // start recording
                        recorder.start(micro);
                        br.close();
                  }catch(Exception e){
                      e.printStackTrace();
                  }//catch
                }
            }
        });
        panel.add(audio);
    }

    /**
     * Method that set the play audio button and its components
     */
    public void setPlayAudio(){
        JButton playAudio = new JButton("Reproducir audio");
        playAudio.setBounds(750,465,180,40);
        playAudio.setBackground(Color.WHITE);
        playAudio.setFont(new FontUIResource("Roboto", Font.BOLD, 14));
        playAudio.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent ae){
                if(ae.getSource() == playAudio){
                    int tab = tabs.getSelectedIndex();
                    if(tab == 0){
                        showAvailableAudios("Audios/General");
                    }else{
                        showAvailableAudios(String.format(path));
                    }
                }
            }  
        });
        panel.add(playAudio);
    }

    /**
     * Show the available audios which the client can select to reproduce
     * @param path The directory path where the audios are saved
     * @return none
     */
    
    public void showAvailableAudios(String path){
        PlayWavFile pa;
        File[] audios;
        audios = (new File(path)).listFiles();
        if(audios.length == 0)JOptionPane.showMessageDialog(null, "No hay audios para reproducir", "Sin audios" , JOptionPane.ERROR_MESSAGE);
        else{
            File audioSelected = (File) JOptionPane.showInputDialog(null, "Reproducir un audio", "Seleccione el audio a reproducir", 
                    JOptionPane.QUESTION_MESSAGE, UIManager.getIcon("OptionPane.questionIcon"),audios,audios[0]);
            pa = new PlayWavFile(audioSelected.getAbsolutePath());
            pa.play();
        }
    }

    /**
     * Method that sets the emojis components
     */
    public void initEmojis(){
        emojisPanel.setBounds(780,360,240,70);
        Constants.EMOJIS_LIST.forEach((k,e) -> {
        JButton emojiBtn = new JButton(k);
            System.out.println(k);
        emojisPanel.add(emojiBtn);
        emojiBtn.setBackground(Color.WHITE);
        emojiBtn.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent ae){
                if(ae.getSource() == emojiBtn){
                    chat.setText(chat.getText() + e);
                }
            }
        });
    });
        JLabel emojisText = new JLabel("EMOJIS");
        emojisText.setBounds(780,310,240,70);
        panel.add(emojisPanel);
        panel.add(emojisText);
    }

    /**
     * Method that indicates when a user leaves the chat
     */
    public void userLeft(){
       window.addWindowListener(new WindowAdapter(){
           @Override
           public void windowClosing(WindowEvent e){
               
               connected = false;
               operation = 1;
//               currentUsersString.remove(userName);
//               setCurrentUsers();
//               System.out.println("Saliendo");
               try {
                   Thread.sleep(1000);
               } catch (InterruptedException ie) {
                   System.err.println(ie.getMessage());
               }
           }
       });
    }

    /**
     * Method that set the current Users in the chat
     */
    public void setCurrentUsers(){
        int i = 0;
        onlineUsers.removeAll();
//        System.err.println("Dentro setCurrentUsers");
        for(String user: currentUsersString){
            if(!user.equals(userName)){
                JButton userBtn = new JButton(user);
                currentUsers.add(userBtn);

                userBtn.setBounds(0,0+i,240,25);
                i += 35;
                userBtn.setName(user);
                userBtn.setBackground(new Color(255,238,238));
                userBtn.setFont(new FontUIResource("Roboto", Font.BOLD, 15));
                userBtn.addActionListener(new ActionListener(){
                @Override
                public void actionPerformed(ActionEvent ae){
                    if(ae.getSource() == userBtn){
//                        System.out.println("Chat privado con " + user);
                        if(chatsInTabs.contains(user)) tabs.setSelectedIndex(chatsInTabs.indexOf(user));
                        else{
                            addChat(user);
                            tabs.setSelectedIndex(chatsInTabs.indexOf(user));
                        }
                    }
                }
                });
                onlineUsers.add(userBtn);
                
                System.err.println("boton " + user);
               
            }
        }
         window.repaint();
    }

    /**
     * Method that add a new chat to the tabbed pane
     * @param title The tab name
     */
    
    public void addChat(String title){
        JPanel chat = new JPanel();
        chat.setLayout(null);
        tabs.addTab(title, chat);
        JEditorPane ep = new JEditorPane();
        JTextArea chatArea = new JTextArea();
        chatArea.setForeground(Color.BLACK);
        chatArea.setEditable(false);
        privateChats.add(chatArea);
        //* Adding chat o a scroll pane
        scroll = new JScrollPane(privateChats.get(privateChats.size() - 1));
        scroll.setBounds(5,5,745,445);
        chatsInTabs.add(title);
        chat.add(scroll);
    }
    
    public String getUserName(){
        return userName;
    }
    public int getOp(){
        return operation;
    }
    public void setOp(int operation){
        this.operation = operation;
    }
    public boolean getConnected(){
        return connected;
    }
    public int getTab(){
        currentTab = tabs.getSelectedIndex();
        return currentTab;
    }
    public String getCurrentMsg(){
        currentMessage = chat.getText();
        chat.setText("");
        return currentMessage;
    }

    /**
     * Method that will set the new message depending if it a private or general message
     * @param m The message recieved
     */
    public void newMessage(String m){
//        System.out.println("Mensaje recibido: " + m);
        if(m.contains("<usuarios>")){
           m = m.substring(10);
           String [] contacts = m.split(",");
           currentUsersString.clear();
           currentUsers.clear();
           
           //Arrays.stream(contacts).forEach(System.out::println);
           Arrays.stream(contacts).forEach(c -> currentUsersString.add(c.replaceAll("[^a-zA-Z]", "")));
           System.out.println(Constants.CURRENT_USERS);
           for(String c :currentUsersString ){
               System.out.println(c);
           }
//           System.err.println("Setting current users");
           setCurrentUsers();
            
        }else if(m.startsWith("s<msg>")){
            m = m.substring(6);
            m = m.replace(":)", "\uD83D\uDE00");
            m = m.replace(":D", "\uD83D\uDE04");
            m = m.replace(":'D", "\uD83D\uDE02");
            m = m.replace("0:>", "\uD83D\uDE07");
            m = m.replace("<3)", "\uD83D\uDE0D");
            m = m.replace(":p", "\uD83D\uDE1B");
            m = m.replace("8)", "\uD83D\uDE0E");
            m = m.replace(":/", "\uD83D\uDE15");
            m = m.replace(":(", "\uD83D\uDE41");
            m = m.replace(":o", "\uD83D\uDE2E");
            m = m.replace(":'(", "\uD83D\uDE22");
            m = m.replace(">:", "\uD83D\uDE21");
            m = m.replace("X:", "\uD83D\\uDC80");
            m = m.replace("^0^", "\uD83D\uDC7D");
            m = m.replace(":kiss", "\uD83D\uDC8B");
            m = m.replace("<*3", "\uD83D\uDC96");
            m = m.replace("**", "\uD83D\uDCA5");
            m = m.replace("^|^", "\uD83E\uDD18");
            m = m.replace("->", "\uD83D\uDC49");
            m = m.replace("(Y)", "\uD83D\uDC4D");
            if(m.contains("<privado>")){
                sender = "";
                reciever = "";
                m = m.substring(10);
                int i = 0;
                for(i = 0; Character.isLetter(m.charAt(i));i++) sender = sender + m.charAt(i);

                m = m.substring(i+2);
                i = 0;
                for(i = 0; Character.isLetter(m.charAt(i));i++) reciever = reciever + m.charAt(i);
                m = m.substring(i+1);
//                System.out.println("<" + sender + ">"+"<" + reciever + ">"+m);
                if(userName.equals(reciever)){
                    if(chatsInTabs.contains(sender)){
                        int tab = chatsInTabs.indexOf(sender);
                        privateChats.get(tab).setText(String.format(Constants.TEXT_AREA_MESSAGE, privateChats.get(tab).getText(), sender, m));
                    }else{
                        addChat(sender);
                        tabs.setSelectedIndex(chatsInTabs.indexOf(sender));
                        int tab = tabs.getSelectedIndex();
                        
                        privateChats.get(tab).setText(String.format(Constants.TEXT_AREA_MESSAGE, privateChats.get(tab).getText(), sender, m));
                    }
                }else if(userName.equals(sender)){
                    int tab = tabs.getSelectedIndex();
                    privateChats.get(tab).setText(String.format(Constants.TEXT_AREA_MESSAGE, privateChats.get(tab).getText(), sender, m));
                } 
            }else{
                privateChats.get(0).setText(privateChats.get(0).getText() + "\n" + m);
            }
        }else if(m.contains("<inicio>") || m.contains("<fin>")){
                privateChats.get(0).setText(privateChats.get(0).getText() + "\n" + m);
            }
    }

    public String getReciever(int tab){
        return chatsInTabs.get(tab);
    }
}
