<%@page import="java.util.List"%>
<%@page import="bdmv.pasteleria.connection.ConnectionDb"%>
<%@page import="bdmv.pasteleria.schemes.*"%>
<%@page import="bdmv.pasteleria.dao.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%
	User auth = (User) request.getSession().getAttribute("auth");
if(auth != null){
	request.setAttribute("auth", auth);
}

CakeDao cakeDao = new CakeDao(ConnectionDb.getConnection());
List<Cake> cakes = cakeDao.getAllCakes();
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Pasteleria</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
</head>
<body>
	<%@include file="global/header.jsp" %>	
	<div class="container">
		<div class="card-header my-3">
			Pasteles disponibles
		</div>
		<div class="row">
		<%
			if(!cakes.isEmpty()){
				for(Cake c:cakes){%>
					<div class="col-md-3 my-3">
					<div class="card w-100" style="width: 18rem;">
					  <img class="card-img-top" src="images/<%= c.getImage() %>" alt="Card image cap" width="500" height="250">
					  <div class="card-body">
					    <h5 class="card-title"><%= c.getName() %></h5>
					    <h5>Tamaño: <%= c.getSize() %></h5>
					    <h5>Precio: $<%= c.getPrice() %> MXN</h5>
					    <h6>Ingredientes: <%= c.getIngredients() %></h6>
					    <h6>Para <%= c.getPeople_quantity() %> personas</h6>
					    <p class="card-text"><%= c.getDescription() %></p>
					    <div class="mt-3 d-flex justify-content-between">
					    	<a href="#" class="btn btn-primary">Agregar al carrito</a>
					    	<a href="#" class="btn btn-success">Comprar ahora</a>
					    </div>
					    
					  </div>
					</div>
				</div>
				<%}
			}
		%>
			
		</div>
	</div>
	
	  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
	  <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js" integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.min.js" integrity="sha384-BBtl+eGJRgqQAUMxJ7pMwbEyER4l1g+O15P+16Ep7Q9Q+zqX6gSbd85u4mG4QzX+" crossorigin="anonymous"></script>
</body>
</html>