import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.Mixer;
import javax.sound.sampled.SourceDataLine;
import javax.sound.sampled.TargetDataLine;

public class PlayWavFile
{
public static void main(String[]args)
{
String filename="Audio.wav"; //fill in file name here

int EXTERNAL_BUFFER_SIZE = 524288;

File soundFile = new File(filename);
Mixer mixer=null;

if (!soundFile.exists())
{
 System.err.println("Wave file not found: " + filename);
 return;
}
/*********************************/
 BufferedReader br=null;
  try{
      br = new BufferedReader(new InputStreamReader(System.in));
      //Get and display a list of
      // available mixers.
      Mixer.Info[] mixerInfo = AudioSystem.getMixerInfo();
      System.out.println("Mezcladores disponibles:");
      for(int cnt = 0; cnt < mixerInfo.length;cnt++){
        System.out.println("["+cnt+"]->"+mixerInfo[cnt].getName());
      }//end for loop
      System.out.print("\nElige el mezclador de salida (bocinas) de tu eleccion:");
      int bocina = Integer.parseInt(br.readLine());
      mixer = AudioSystem.getMixer(mixerInfo[bocina]);//3
  }catch(Exception e){e.printStackTrace();
  }//catch
/**********************************/
AudioInputStream audioInputStream = null;
try
{
 audioInputStream = AudioSystem.getAudioInputStream(soundFile);
}
catch(Exception e)
{
 e.printStackTrace();
 return;
}

AudioFormat format = audioInputStream.getFormat();

SourceDataLine auline = null;
try
{
//Describe a desired line
DataLine.Info info = new DataLine.Info(SourceDataLine.class, format);
auline = (SourceDataLine)mixer.getLine(info);

 //auline = (SourceDataLine) AudioSystem.getLine(info);

 //Opens the line with the specified format,
 //causing the line to acquire any required
 //system resources and become operational.
 auline.open(format);
}
catch(Exception e)
{
 e.printStackTrace();
 return;
}

 //Allows a line to engage in data I/O
auline.start();

int nBytesRead = 0;
byte[] abData = new byte[EXTERNAL_BUFFER_SIZE];

try
{
 while (nBytesRead != -1)
 {
  nBytesRead = audioInputStream.read(abData, 0, abData.length);
  if (nBytesRead >= 0)
  {
   //Writes audio data to the mixer via this source data line
   //NOTE : A mixer is an audio device with one or more lines
   auline.write(abData, 0, nBytesRead);
  }
 }
 audioInputStream.close();
}catch(Exception e)
{
 e.printStackTrace();
 return;
}
finally
{
 //Drains queued data from the line
 //by continuing data I/O until the
 //data line's internal buffer has been emptied
 auline.drain();

 //Closes the line, indicating that any system
 //resources in use by the line can be released
 auline.close();
}
}
}