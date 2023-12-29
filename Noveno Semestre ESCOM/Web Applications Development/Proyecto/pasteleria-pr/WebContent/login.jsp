<%@page import="bdmv.pasteleria.schemes.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%
	User auth = (User) request.getSession().getAttribute("auth");
if(auth != null){
	response.sendRedirect("index.jsp");
}
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
</head>
<body>
	<%@include file="global/header.jsp" %>	
<div class="container d-flex justify-content-center align-items-center flex-column">
	<form action="login" method="POST" class="d-flex justify-content-center align-items-center flex-column">
	  <div class="form-group">
	    <label for="exampleInputEmail1" class="form-label">Correo Electrónico</label>
	    <input type="email" class="form-control" id="userEmail" name="userEmail" aria-describedby="emailHelp">
	  </div>
	  <div class="form-group mb-3">
	    <label for="exampleInputPassword1" class="form-label">Contraseña</label>
	    <input type="password" class="form-control" id="userPassword" name="userPassword">
	  </div>

	  <button type="submit" class="btn btn-primary">Iniciar sesión</button>
	</form>
</div>

<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js" integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.min.js" integrity="sha384-BBtl+eGJRgqQAUMxJ7pMwbEyER4l1g+O15P+16Ep7Q9Q+zqX6gSbd85u4mG4QzX+" crossorigin="anonymous"></script>
</body>
</html>