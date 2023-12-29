<nav class="navbar navbar-expand-lg bg-body-tertiary">
	  <div class="container-fluid">
	    <a class="navbar-brand" href="#">Pastelería Online</a>
	    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
	      <span class="navbar-toggler-icon"></span>
	    </button>
	    <div class="collapse navbar-collapse" id="navbarSupportedContent">
	      <ul class="navbar-nav me-auto mb-2 mb-lg-0">
	        <li class="nav-item">
	          <a class="nav-link active" aria-current="page" href="index.jsp">Inicio</a>
	        </li>
	        <li class="nav-item">
	          <a class="nav-link" href="catalogo.jsp">Catálogo</a>
	        </li>
	        <li class="nav-item">
	          <a class="nav-link" href="carrito.jsp">Carrito</a>
	        </li>
	        <%
		        if(auth != null){ %>
		        	 <li class="nav-item">
			          <a class="nav-link" href="compras.jsp">Ordenes</a>
			        </li>
			       
			          <li class="nav-item">
			          <a class="nav-link" href="logout">Cerrar Sesión</a>
			        </li>
		        <%}else{ %>
		        	<li class="nav-item">
			          <a class="nav-link" href="login.jsp">Login</a>
			        </li>
		         <%}
	        %>
	        
	       
	         
	      </ul>
	
	    </div>
	  </div>
</nav>