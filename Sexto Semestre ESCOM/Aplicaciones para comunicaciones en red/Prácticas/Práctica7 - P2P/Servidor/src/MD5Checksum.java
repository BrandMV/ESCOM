
import constants.Constants;

import java.io.FileInputStream;
import java.io.InputStream;
import java.security.MessageDigest;

public class MD5Checksum {
    public static byte[] createChecksum(String filename) throws Exception{
        InputStream fis = new FileInputStream(filename);

        byte[] buffer = new byte[Constants.BUFFER_SIZE];
        MessageDigest complete = MessageDigest.getInstance("MD5");
        int numRead;

        do{
            numRead = fis.read(buffer);
            if(numRead  > 0)
                complete.update(buffer, 0, numRead);

        } while(numRead != -1);

        fis.close();

        return complete.digest();
    }

    public static String getMD5Checksum(String filename) throws Exception{
        byte[] b = createChecksum(filename);
        String result = "";
        int i = 0;
        for(i = 0; i < b.length; i++)
            result += Integer.toString((b[i] & 0xff) + 0x100, 16).substring(1);

        return result;
    }

    public static void main(String[] args) {
        try {
            System.out.println(getMD5Checksum("MD5Checksum.java"));
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
