package bdmv.pasteleria.connection;
import java.sql.*;
public class ConnectionDb {
	private static Connection connection = null;
	
	public static Connection getConnection() throws SQLException, ClassNotFoundException {
		if(connection == null) {
			Class.forName("com.mysql.cj.jdbc.Driver");
			connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/pasteleria","root","1324");
			System.out.print("Connected");
		}
		return connection;
	}
}
