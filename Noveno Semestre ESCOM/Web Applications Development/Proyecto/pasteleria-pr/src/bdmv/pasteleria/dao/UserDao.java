package bdmv.pasteleria.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import bdmv.pasteleria.schemes.User;

public class UserDao {
	private Connection con;
	private String query;
	private PreparedStatement pstate;
	private ResultSet rs;
	public UserDao(Connection con) {
		this.con = con;
	}

	public User Login(String email, String password) {
		User user = null;
		try {
			query = "SELECT * FROM user WHERE email=? and password=?";
			pstate = this.con.prepareStatement(query);
			pstate.setString(1, email);
			pstate.setString(2, password);
			rs = pstate.executeQuery();
			
			if(rs.next()) {
				user = new User();
				user.setUserId(rs.getInt("user_id"));
				user.setName(rs.getString("name"));
				user.setEmail(rs.getString("email"));
			}
		} catch (Exception e) {
			e.printStackTrace();
			System.out.println(e.getMessage());
		}
		
		return user;
	}
}
