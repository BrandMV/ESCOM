import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.channels.DatagramChannel;
import java.net.InetSocketAddress;
import java.util.Date;
import java.util.List;
import java.util.LinkedList;
import java.util.Iterator;
/**
* Request time service, per RFC 868. RFC 868
* (http://www.ietf.org/rfc/rfc0868.txt)
 * */
public class TimeClient
{
private static final int DEFAULT_TIME_PORT = 37;
private static final long DIFF_1900 = 2208988800L;
protected int port = DEFAULT_TIME_PORT;
protected List remoteHosts;
protected DatagramChannel channel;
@SuppressWarnings("uncheked")
public TimeClient (String [] argv) throws Exception
{
if (argv.length == 0) {
//throw new Exception ("Usage: [ -p port ] host ...");
    String[] opciones = {"37","localhost"};
    parseArgs(opciones);
}else{
parseArgs (argv);
}//else
this.channel = DatagramChannel.open( );
}
protected InetSocketAddress receivePacket (DatagramChannel channel,
ByteBuffer buffer)
throws Exception
{
buffer.clear( );
// Receive an unsigned 32-bit, big-endian value
return ((InetSocketAddress) channel.receive (buffer));
}
// Send time requests to all the supplied hosts
protected void sendRequests( )
throws Exception
{
ByteBuffer buffer = ByteBuffer.allocate (1);
Iterator it = remoteHosts.iterator( );
while (it.hasNext( )) {
InetSocketAddress sa = (InetSocketAddress) it.next( );
System.out.println ("Requesting time from "
+ sa.getHostName() + ":" + sa.getPort( ));
// Make it empty (see RFC868)
buffer.clear().flip( );
// Fire and forget
channel.send (buffer, sa);
}
}
// Receive any replies that arrive
public void getReplies( ) throws Exception
{
// Allocate a buffer to hold a long value
ByteBuffer longBuffer = ByteBuffer.allocate (8);
// Assure big-endian (network) byte order
longBuffer.order (ByteOrder.BIG_ENDIAN);
// Zero the whole buffer to be sure
longBuffer.putLong (0, 0);
// Position to first byte of the low-order 32 bits
longBuffer.position (4);
// Slice the buffer; gives view of the low-order 32 bits
ByteBuffer buffer = longBuffer.slice( );
int expect = remoteHosts.size( );
int replies = 0;
System.out.println ("");
System.out.println ("Waiting for replies...");
while (true) {
InetSocketAddress sa;
sa = receivePacket (channel, buffer);
buffer.flip( );
replies++;
printTime (longBuffer.getLong (0), sa);
if (replies == expect) {
System.out.println ("All packets answered");
break;
}
// Some replies haven't shown up yet
System.out.println ("Received " + replies
+ " of " + expect + " replies");
}
}
// Print info about a received time reply
protected void printTime (long remote1900, InetSocketAddress sa)
{
// local time as seconds since Jan 1, 1970
long local = System.currentTimeMillis( ) / 1000;
// remote time as seconds since Jan 1, 1970
long remote = remote1900 - DIFF_1900;
Date remoteDate = new Date (remote * 1000);
Date localDate = new Date (local * 1000);
long skew = remote - local;
System.out.println ("Reply from "
+ sa.getHostName() + ":" + sa.getPort( ));
System.out.println (" there: " + remoteDate);
System.out.println (" here: " + localDate);
System.out.print (" skew: ");
if (skew == 0) {
System.out.println ("none");
} else if (skew > 0) {
System.out.println (skew + " seconds ahead");
} else {
System.out.println ((-skew) + " seconds behind");
}
}
protected void parseArgs (String [] argv)
{
remoteHosts = new LinkedList( );
for (int i = 0; i < argv.length; i++) {
String arg = argv [i];
// Send client requests to the given port
if (arg.equals ("-p")) {
i++;
this.port = Integer.parseInt (argv [i]);
continue;
}
// Create an address object for the hostname
InetSocketAddress sa = new InetSocketAddress (arg, port);
// Validate that it has an address
if (sa.getAddress( ) == null) {
System.out.println ("Cannot resolve address: "
+ arg);
continue;
}
remoteHosts.add (sa);
}
}
// --------------------------------------------------------------
public static void main (String [] argv)
throws Exception
{
TimeClient client = new TimeClient (argv);
client.sendRequests( );
client.getReplies( );
}
}