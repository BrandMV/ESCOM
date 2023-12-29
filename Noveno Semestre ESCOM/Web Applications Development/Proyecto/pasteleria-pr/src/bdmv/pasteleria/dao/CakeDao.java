package bdmv.pasteleria.dao;
import bdmv.pasteleria.schemes.*;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class CakeDao {
	private Connection con;
	private String query;
	private PreparedStatement pstate;
	private ResultSet rs;
	public CakeDao(Connection con) {
		this.con = con;
	}
	
	public List<Cake> getAllCakes(){
		List<Cake> cakes = new ArrayList<Cake>();
		try {
			query = "SELECT * FROM products";
			pstate = this.con.prepareStatement(query);
			rs = pstate.executeQuery();
			
			while(rs.next()) {
				Cake row = new Cake();
				row.setId(rs.getInt("id"));
				row.setName(rs.getString("name"));
				row.setSize(rs.getString("size"));
				row.setImage(rs.getString("image"));
				row.setPrice(rs.getFloat("price"));
				row.setIngredients(rs.getString("ingredients"));
				row.setPeople_quantity(rs.getInt("people_quantity"));
				row.setDescription(rs.getString("description"));
				
				cakes.add(row);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return cakes;
	}
}
