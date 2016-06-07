<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
        <title>Cliente</title>
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
        <p>Seja Bem Vindo!</p>
        <table>
            <tr><td><a href="selecionarProdutos.jsp"><input type="button" value="Selecionar Produtos" /></a></td></tr>
            <tr><td><a href="FinalizarCompra"><input type="button" value="Finalizar Compra" /></a></td></tr>
            <tr><td><a href="../FazerLogout"><input type="button" value="Fazer Logout" /></a></td></tr>
        </table>
        </div>
    </body>
</html>
