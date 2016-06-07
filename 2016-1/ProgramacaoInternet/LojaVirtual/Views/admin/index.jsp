<%-- 
    Document   : index
    Created on : May 24, 2016, 5:27:35 PM
    Author     : oliveira
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <title>Administrador</title>
        <meta charset="UTF-8">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <style>
            .centralizar {
                margin: 10% 40%;
                align-self: center;
            }
            input {
                margin-top: 10px;
            }
        </style>
    </head>
    <body>
        <div class="centralizar">
        <table>
            <th>Seja Bem Vindo, Administrador</th>
            <tr><td><a href="cProdutos.jsp"><input type="button" value="Cadastrar Produtos" /></a></td></tr>
            <tr><td><a href="cClientes.jsp"><input type="button" value="Cadastrar Clientes" /></a></td></tr>
            <tr><td><a href="lVendas.jsp"><input type="button" value="Listar Vendas" /></a></td></tr>
            <tr><td><a href="../FazerLogout"><input type="button" value="Fazer Logout" /></a></td></tr>
        </table>
        </div>
    </body>
</html>


