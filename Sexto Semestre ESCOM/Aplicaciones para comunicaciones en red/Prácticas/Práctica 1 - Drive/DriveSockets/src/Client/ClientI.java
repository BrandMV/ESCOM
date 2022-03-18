/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Client;

import Server.Server;
import static Server.Server.ANSI_BLUE;
import static Server.Server.ANSI_RESET;
import java.awt.Font;
import java.io.DataInputStream;
import java.io.File;
import java.io.IOException;
import java.net.ServerSocket;
import java.nio.file.Files;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;
import javax.swing.JLabel;
import static javax.swing.SwingConstants.CENTER;

/**
 *
 * @author PC
 */
public class ClientI extends javax.swing.JFrame {

    /**
     * Creates new form NewJFrame
     */
    String files_path;
    String clientPath = "C:\\Users\\PC\\Desktop\\6to Semestre ESCOM\\Aplicaciones para comunicaciones en red\\Prácticas\\Práctica 1 - Drive\\DriveSockets\\ClientFiles";
    String serverPath = "C:\\Users\\PC\\Desktop\\6to Semestre ESCOM\\Aplicaciones para comunicaciones en red\\Prácticas\\Práctica 1 - Drive\\DriveSockets\\ServerFiles";
    public ClientI() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        downloadFiles = new javax.swing.JButton();
        sendFiles = new javax.swing.JButton();
        deleteLocalFiles = new javax.swing.JButton();
        deleteServerFiles = new javax.swing.JButton();
        listFiles = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(26, 28, 30));
        setForeground(new java.awt.Color(26, 28, 30));
        setResizable(false);

        jPanel1.setBackground(new java.awt.Color(26, 28, 30));
        jPanel1.setPreferredSize(new java.awt.Dimension(700, 500));

        jLabel1.setBackground(new java.awt.Color(253, 253, 253));
        jLabel1.setFont(new java.awt.Font("Montserrat", 0, 36)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(253, 253, 253));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("BIENVENIDO");

        downloadFiles.setBackground(new java.awt.Color(39, 42, 48));
        downloadFiles.setFont(new java.awt.Font("Montserrat", 0, 24)); // NOI18N
        downloadFiles.setForeground(new java.awt.Color(253, 253, 253));
        downloadFiles.setText("Descargar archivos");
        downloadFiles.setBorderPainted(false);
        downloadFiles.setContentAreaFilled(false);
        downloadFiles.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        downloadFiles.setOpaque(true);
        downloadFiles.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                downloadFilesActionPerformed(evt);
            }
        });

        sendFiles.setBackground(new java.awt.Color(39, 42, 48));
        sendFiles.setFont(new java.awt.Font("Montserrat", 0, 24)); // NOI18N
        sendFiles.setForeground(new java.awt.Color(253, 253, 253));
        sendFiles.setText("Enviar archivos");
        sendFiles.setContentAreaFilled(false);
        sendFiles.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        sendFiles.setOpaque(true);
        sendFiles.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                sendFilesMouseClicked(evt);
            }
        });
        sendFiles.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sendFilesActionPerformed(evt);
            }
        });

        deleteLocalFiles.setBackground(new java.awt.Color(39, 42, 48));
        deleteLocalFiles.setFont(new java.awt.Font("Montserrat", 0, 24)); // NOI18N
        deleteLocalFiles.setForeground(new java.awt.Color(253, 253, 253));
        deleteLocalFiles.setText("Eliminar archivos local");
        deleteLocalFiles.setBorderPainted(false);
        deleteLocalFiles.setContentAreaFilled(false);
        deleteLocalFiles.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        deleteLocalFiles.setOpaque(true);
        deleteLocalFiles.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                deleteLocalFilesActionPerformed(evt);
            }
        });

        deleteServerFiles.setBackground(new java.awt.Color(39, 42, 48));
        deleteServerFiles.setFont(new java.awt.Font("Montserrat", 0, 24)); // NOI18N
        deleteServerFiles.setForeground(new java.awt.Color(253, 253, 253));
        deleteServerFiles.setText("Eliminar archivos servidor");
        deleteServerFiles.setBorderPainted(false);
        deleteServerFiles.setContentAreaFilled(false);
        deleteServerFiles.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        deleteServerFiles.setOpaque(true);
        deleteServerFiles.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                deleteServerFilesActionPerformed(evt);
            }
        });

        listFiles.setBackground(new java.awt.Color(39, 42, 48));
        listFiles.setFont(new java.awt.Font("Montserrat", 0, 24)); // NOI18N
        listFiles.setForeground(new java.awt.Color(253, 253, 253));
        listFiles.setText("Listar archivos");
        listFiles.setBorderPainted(false);
        listFiles.setContentAreaFilled(false);
        listFiles.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        listFiles.setOpaque(true);
        listFiles.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                listFilesActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(0, 170, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(downloadFiles, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(sendFiles, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(deleteServerFiles, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(deleteLocalFiles, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(listFiles, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(179, 179, 179))
            .addComponent(jLabel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addComponent(jLabel1)
                .addGap(34, 34, 34)
                .addComponent(sendFiles, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(downloadFiles, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(deleteServerFiles, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(deleteLocalFiles, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(listFiles, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(106, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, 480, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void downloadFilesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_downloadFilesActionPerformed
        // TODO add your handling code here:
        Client cl = new Client(8000, "127.0.0.1");
        try {
            
            cl.chooser(false);
        } catch (IOException ex) {
            Logger.getLogger(ClientI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_downloadFilesActionPerformed

    private void sendFilesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sendFilesActionPerformed
        // TODO add your handling code here:
 
        Client cl = new Client(8000, "127.0.0.1");
        try {
            cl.chooser(true);
        } catch (IOException ex) {
            Logger.getLogger(ClientI.class.getName()).log(Level.SEVERE, null, ex);
        }
                
    }//GEN-LAST:event_sendFilesActionPerformed

    private void deleteLocalFilesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_deleteLocalFilesActionPerformed
        // TODO add your handling code here:
        JFileChooser jf = new JFileChooser();
        jf.setCurrentDirectory(new File(clientPath));
        jf.setMultiSelectionEnabled(true);
        jf.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);

        int r = jf.showOpenDialog(null);
        jf.setRequestFocusEnabled(true);
        if(r == JFileChooser.APPROVE_OPTION){
            File[] files = jf.getSelectedFiles();
            for(File file : files){
                if(file.isDirectory())
                    deleteDirectory(file);
                else file.delete();
            }
            
        }
        
    }//GEN-LAST:event_deleteLocalFilesActionPerformed
    public void deleteDirectory(File file){
        File[] content = file.listFiles();
        if(content != null)
            for(File f : content)
                if(!Files.isSymbolicLink(f.toPath()))
                    deleteDirectory(f);
        
        file.delete();
    }
    private void deleteServerFilesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_deleteServerFilesActionPerformed
        // TODO add your handling code here:
        JFileChooser jf = new JFileChooser();
        jf.setCurrentDirectory(new File(serverPath));
        jf.setMultiSelectionEnabled(true);
        jf.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);

        int r = jf.showOpenDialog(null);
        jf.setRequestFocusEnabled(true);
        if(r == JFileChooser.APPROVE_OPTION){
            File[] files = jf.getSelectedFiles();
            for(File file : files){
                if(file.isDirectory())
                    deleteDirectory(file);
                else file.delete();
            }
            
        }
        
    }//GEN-LAST:event_deleteServerFilesActionPerformed

    private void listFilesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_listFilesActionPerformed
        // TODO add your handling code here:
        filesList fl = new filesList();
        
        File directory = new File("C:\\Users\\PC\\Desktop\\6to Semestre ESCOM\\Aplicaciones para comunicaciones en red\\Prácticas\\Práctica 1 - Drive\\DriveSockets\\ServerFiles");
        File[] files = directory.listFiles();
        Integer i = 0;
        for(File file : files){
            String name = file.getName();
            String type;
            if(file.isDirectory()){
                type = "Carpeta";
            } else type = "Archivo";
            
            JLabel fileLabel = new JLabel(name + " ----- " + type);
            
            fileLabel.setFont(new Font("Montserrat", 0, 16)); 
            
            
            fileLabel.setLocation(20, 20+i);
            fileLabel.setSize(fl.serverPane.getWidth(), 30);
            fileLabel.setHorizontalAlignment(CENTER);
            System.out.println(name + " --------- " + type);
            
            
           
            fl.serverPane.add(fileLabel);
//            fl.serverPane.setLayout(null); 
            i+=30;
//            fl.serverPane.revalidate();
//            fl.serverPane.repaint();


    
           
            
        }
        
        directory = new File("C:\\Users\\PC\\Desktop\\6to Semestre ESCOM\\Aplicaciones para comunicaciones en red\\Prácticas\\Práctica 1 - Drive\\DriveSockets\\ClientFiles");
        files = directory.listFiles();
        i = 0;
        for(File file : files){
            String name = file.getName();
            String type;
            if(file.isDirectory()){
                type = "Carpeta";
            } else type = "Archivo";
            
            JLabel fileLabel = new JLabel(name + " ----- " + type);
            
            fileLabel.setFont(new Font("Montserrat", 0, 14)); 
            
            
            fileLabel.setLocation(20, 20+i);
            fileLabel.setSize(fl.clientPane.getWidth(), 30);
            fileLabel.setHorizontalAlignment(CENTER);
            System.out.println(name + " --------- " + type);
            
            
           
            fl.clientPane.add(fileLabel);
//            fl.serverPane.setLayout(null); 
            i+=30;

        }
        
         this.setVisible(false);
            fl.setVisible(true);
    }//GEN-LAST:event_listFilesActionPerformed

    private void sendFilesMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_sendFilesMouseClicked

    }//GEN-LAST:event_sendFilesMouseClicked

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(ClientI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ClientI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ClientI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ClientI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                
                ClientI cI = new ClientI();
                cI.setVisible(true);
                cI.connect();
            }
        });
    }
    public void connect(){
            File f = new File("");
            String path = f.getAbsolutePath();
            String folder = "ClientFiles";
            String files_path = path + "\\" + folder + "\\";
            System.out.println("Client folder path: " + files_path);
            File f2 = new File(files_path);
            f2.mkdirs();
            f2.setWritable(true);
            
            clientPath = files_path;
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton deleteLocalFiles;
    private javax.swing.JButton deleteServerFiles;
    private javax.swing.JButton downloadFiles;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JButton listFiles;
    private javax.swing.JButton sendFiles;
    // End of variables declaration//GEN-END:variables
}
