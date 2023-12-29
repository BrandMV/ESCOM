<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>JSP Brandon Meza 3CM11</title>
  </head>
  <body style="background-color: #aaaffa">
    <h1>La fecha y hora actuales son:</h1>
    <h2><%@include file="fecha.jsp" %></h2>
  </body>
</html>
<%@page import="java.util.Date"%> <%@page import="java.text.SimpleDateFormat"%>
<%=(new SimpleDateFormat("E dd/MM/yyyy - hh:mm:ss a zzz").format(new Date())) %>
