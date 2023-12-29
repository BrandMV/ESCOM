package bdmv.pasteleria.schemes;

public class User {
	private int UserId;
	private String name;
	private String email;
	private String password;
	public User() {
		super();
	}
	public User(int userId, String name, String email, String password) {
		super();
		UserId = userId;
		this.name = name;
		this.email = email;
		this.password = password;
	}

	

	public int getUserId() {
		return UserId;
	}

	@Override
	public String toString() {
		return "User [UserId=" + UserId + ", name=" + name + ", email=" + email + ", password=" + password + "]";
	}

	public void setUserId(int userId) {
		UserId = userId;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}
	
}
