import constants.Constants;

import javax.swing.*;
import javax.swing.plaf.FontUIResource;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

public class App extends JFrame {
    private JPanel panel;
    private JTextField searchFile;
    private JButton searchBtn;
    private JButton downloadBtn;
    private JProgressBar downloadProgress;
    private JFrame window;
    private JLabel fileName;
    private JLabel filePath;
    private JLabel fileMD5;
    private JLabel fileServer;
    private JLabel fileNameText;
    private JLabel appTitle;
    private JLabel fileNameT; 
    private JLabel filePathText;
    private JLabel fileMD5Text;
    private JLabel fileServerText;


    Files db = new Files();
    UnicastClient uClient = new UnicastClient(db, this);
    MulticastClient mClient = new MulticastClient(db);
    MulticastServersWatcher msw = new MulticastServersWatcher(db);
    RMIClient rmiClient = new RMIClient(db, this);

    public App(){
        Toolkit myScreen = Toolkit.getDefaultToolkit();
        Dimension screenSize = myScreen.getScreenSize();

        window = new JFrame();

        window.setSize((screenSize.width / 4),screenSize.height / 2);
        window.setLocation(screenSize.width / 4, screenSize.height / 4);
        System.out.println(screenSize.width / 2 + "altuura: " +  screenSize.height / 2);
        window.setResizable(false);
        window.setTitle(String.format(Constants.WINDOW_TITLE));
        window.setLocationRelativeTo(null);
        window.setDefaultCloseOperation(EXIT_ON_CLOSE);
        initComponents();

        reset();
        window.setVisible(true);
        clientsStart();
    }

    public void clientsStart(){
        mClient.start();
        msw.start();
        rmiClient.start();
        uClient.start();
    }

    public void initComponents(){
        panel = new JPanel();
        panel.setLayout(null);
        window.getContentPane().add(panel);
        panel.setBackground(new Color(255,246,234));

        fileNameText = new JLabel(Constants.FILE_NAME_TEXT);
        fileNameText.setBounds(10, 80, 150, 40);
        panel.add(fileNameText);

        appTitle = new JLabel(Constants.WINDOW_TITLE);
        appTitle.setBounds(150, 10, 200, 40);
        appTitle.setFont(new FontUIResource("Roboto", Font.BOLD, 30));
        panel.add(appTitle);

        searchFile = new JTextField();
        searchFile.setBounds(130, 85, 200, 30);
        panel.add(searchFile);

        searchBtn = new JButton("Buscar");
        searchBtn.setBackground(Color.WHITE);
        searchBtn.setBounds(333, 85, 125, 30);
        searchBtn.setFont(new FontUIResource("Roboto", Font.BOLD, 15));
        panel.add(searchBtn);
        
        /*
         private JLabel fileNameT; 
    private JLabel filePathText;
    private JLabel fileMD5Text;
    private JLabel fileServerText
        */

        fileServer = new JLabel(Constants.FILE_SERVER_TEXT);
        fileServer.setBounds(10, 150, 150, 40);
        fileServer.setFont(new FontUIResource("Roboto", Font.BOLD, 12));
        panel.add(fileServer);
        fileServerText = new JLabel("");
        fileServerText.setBounds(160, 150, 200, 40);
        fileServerText.setFont(new FontUIResource("Roboto", Font.BOLD, 12));
        panel.add(fileServerText);

        fileName = new JLabel(Constants.FILE_NAME_TEXT);
        fileName.setBounds(10, 200, 150, 40);
        fileName.setFont(new FontUIResource("Roboto", Font.BOLD, 12));
        panel.add(fileName);
        fileNameT = new JLabel("");
        fileNameT.setBounds(160, 200, 300, 40);
        fileNameT.setFont(new FontUIResource("Roboto", Font.BOLD, 12));
        panel.add(fileNameT);

        filePath = new JLabel(Constants.FILE_PATH_TEXT);
        filePath.setBounds(10, 250, 150, 40);
        filePath.setFont(new FontUIResource("Roboto", Font.BOLD, 12));
        panel.add(filePath);
        filePathText = new JLabel("");
        filePathText.setBounds(160, 250, 300, 40);
        filePathText.setFont(new FontUIResource("Roboto", Font.BOLD, 12));
        panel.add(filePathText);

        fileMD5 = new JLabel(Constants.FILE_MD5_TEXT);
        fileMD5.setBounds(10, 300, 150, 40);
        fileMD5.setFont(new FontUIResource("Roboto", Font.BOLD, 12));
        panel.add(fileMD5);
        fileMD5Text = new JLabel("");
        fileMD5Text.setBounds(160, 300, 300, 40);
        fileMD5Text.setFont(new FontUIResource("Roboto", Font.BOLD, 12));
        panel.add(fileMD5Text);

        downloadBtn = new JButton(Constants.DOWNLOAD_BTN_TEXT);
        downloadBtn.setBackground(Color.WHITE);
        downloadBtn.setBounds(10, 400, 200, 40);
        downloadBtn.setFont(new FontUIResource("Roboto", Font.BOLD, 15));
        panel.add(downloadBtn);

        downloadProgress = new JProgressBar();
        downloadProgress.setBounds(220, 410, 220,20);
        panel.add(downloadProgress);

        /**Btns event listeners*/
        searchBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                searchBtnEvent();
            }
        });

        downloadBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                downloadBtnEvent();
            }
        });

    }

    public void searchBtnEvent(){
        //System.out.println("preseed btn");
        
        List<DataFromServer> servers = db.getServers();
        if(!servers.isEmpty())
            rmiClient.searchForFile(searchFile.getText());
        else
            JOptionPane.showMessageDialog(null, Constants.EMPTY_SERVERS_MESSAGE, "Busqueda", JOptionPane.WARNING_MESSAGE);
    }

    public void downloadBtnEvent(){
        //System.out.println("preseed btn");
        uClient.serverConnection();
        uClient.receiveFile();
    }
    public void fileFound(String md5, String path, String filename, String server, boolean isVisible){
        fileName.setVisible(isVisible);
        fileNameT.setText(filename);

        fileMD5.setVisible(isVisible);
        fileMD5Text.setText(md5);

        filePath.setVisible(isVisible);
        filePathText.setText(path);

        fileServer.setVisible(isVisible);
        fileServerText.setText(server);
    }
    
    public void reset(){
        fileName.setVisible(false);
        filePath.setVisible(false);
        fileMD5.setVisible(false);
        fileServer.setVisible(false);
        downloadBtn.setEnabled(false);
        fileNameT.setText("");
        fileMD5Text.setText("");
        filePathText.setText("");
        fileServerText.setText("");
    }

    public void setProgressBar(int percentage){
        downloadProgress.setValue(percentage);
        downloadProgress.setStringPainted(true);
    }

    public void setDownloadVisibility(boolean isVisible){
        downloadBtn.setEnabled(isVisible);
    }

    public static void main(String[] args) {

        new App().setVisible(true);
    }

}
