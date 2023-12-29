<%@page import="bdmv.pasteleria.connection.ConnectionDb"%>
<%@page import="bdmv.pasteleria.schemes.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%
User auth = (User) request.getSession().getAttribute("auth");
if (auth != null) {
	request.setAttribute("auth", auth);
}
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
<link
	href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css"
	rel="stylesheet"
	integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN"
	crossorigin="anonymous">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.1/css/all.min.css" crossorigin="anonymous" referrerpolicy="no-referrer" />

<style type="text/css">
.table tbody td{
	vertical-align: middle;
}
.btn-incre, .btn-decre{
	box-shadow: none;
	font-size: 25px;
}

</style>
</head>
<body>
	<%@include file="global/header.jsp"%>

	<div class="container">
		<div class="d-flex py-3">
			<h3>Precio total: $452</h3>
			<a class="mx-3 btn btn-primary" href="#">Pagar</a>
		</div>
		<table class="table table-light">
			<thead>
				<tr>
					<th scope="col">Nombre</th>
					<th scope="col">Precio</th>
					<th scope="col">Tamaño</th>
					<th scope="col">Cantidad de personas</th>
					<th scope="col">Comprar ahora</th>
					<th scope="col">Acciones</th>
				</tr>
			</thead>
			<tbody>
				<tr>
					<td>Pastel de fresa</td>
					<td>$45 MXN</td>
					<td>Grande</td>
					<td>10</td>
					<td>
						<form method="post" action="" class="form-inline">
							<input type="hidden" name="id" value="1" class="form-input" >
							<div class="form-group d-flex justify-content-between">
								<a class="btn btn-sm btn-decre" href=""><i class="fas fa-minus-square"></i></a>
								
								<input type="text" name="quantity" class="form-control" value="1" readonly>
								<a class="btn btn-sm btn-incre" href=""><i class="fas fa-plus-square"></i></a>
							</div>
						</form>
					</td>
					<td><a class="btn btn-sm btn-danger" href="·">Eliminar</a></td>
				</tr>
			</tbody>
		</table>
	</div>


	<script
		src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js"
		integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r"
		crossorigin="anonymous"></script>
	<script
		src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.min.js"
		integrity="sha384-BBtl+eGJRgqQAUMxJ7pMwbEyER4l1g+O15P+16Ep7Q9Q+zqX6gSbd85u4mG4QzX+"
		crossorigin="anonymous"></script>
</body>
</html>