package bdmv.pasteleria.servlets;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import bdmv.pasteleria.connection.ConnectionDb;
import bdmv.pasteleria.dao.UserDao;
import bdmv.pasteleria.schemes.User;

/**
 * Servlet implementation class LoginServlet
 */
@WebServlet("/login")
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.sendRedirect("login.jsp");
	}


	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html:charset=UTF-8");
		try(PrintWriter out = response.getWriter()){
			String email = request.getParameter("userEmail");
			String password = request.getParameter("userPassword");
			try {
				UserDao userDao = new UserDao(ConnectionDb.getConnection());
				User user = userDao.Login(email, password);
				
				if(user != null) {
					out.print("user login");
					// Usamos sesiones
					request.getSession().setAttribute("auth", user);
					response.sendRedirect("index.jsp");
				}else {
					out.print("user login failed");
				}
			} catch (ClassNotFoundException | SQLException e) {
				e.printStackTrace();
			}
			
		}
	}

}
