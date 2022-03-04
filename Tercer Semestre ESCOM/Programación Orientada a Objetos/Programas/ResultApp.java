import java.sql.*;
import java.util.*;

public static void main(String[] args) {
    String url="jdbc:mysql://localhost:3306/", dbName="Perros";
    //String url = "jdbc:mysql:Driver={Microsof Access Driver (*.mdb)};DBQ=f\\jdbc\\verduleros.MDB";
    try {
        Class.forName("com.mysql-jdbc.Driver");
        Connection conex=DriverManager.getConnection(url+dbName, "root", "root");
        Statement statement = conex.createStatement();
        ResultSet result=statement.executeQuery("SELECT * FROM perroBean"); //Result set representa las tablas
        displayResults(result);
        conex.close();
    } catch (Exception Exception) {
        System.out.println(ex); System.exit(0);
    }
}

static void displayResults(ResultSet r) throws SQLException{
    ResultSetMetaData rmete = r.getMetaData();//me da los metadatos y se guarda en una variable de tipo ResultSetMetaData(metadatos de una tabla)
    int numColumns=rmeta.getColumnCount(); //numero de columnas o campos
    for(int i =1;i<=numColumns;i++)
        System.out.print(rmeta.getColumnName( i )+" "); //este for imprime el nombre de las columnas, es decir, los metadatos
    while(r.next()) //el while sirve para obtener el siguiente registro regresando un boleano si hay disponible un registro
        for(int i= 1; i<=numColumns; i++)
            System.out.print(r.getString( i )+" "); //recorre los campos del registro y los imprime, es decir, los datos
}//displayResults

