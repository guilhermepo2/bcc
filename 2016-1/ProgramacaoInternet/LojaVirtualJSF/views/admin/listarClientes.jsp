<%-- 
    Document   : listarClientes
    Created on : Jun 28, 2016, 11:26:33 PM
    Author     : oliveira
--%>

<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="DAO.ClienteDAO"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
        <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous" />
        <title>Consultar Clientes</title>
        <style>
            input {
                margin-top: 10px;
            }
            
            .cadastro {
                margin-left: 1em;
            }
        </style>
    <body>
        <a href="cadastrar_clientes.xhtml"> << Voltar </a>
        <h2>Clientes Cadastrados</h2>
        <table class="table table-hover">
            <tr>
                <td>CPF</td>
                <td>Nome</td>
                <td>Endereco</td>
                <td>usuario</td>
                <td>senha</td>
            </tr>
        <%
            ClienteDAO clienteDAO = new ClienteDAO();
            ResultSet rs = clienteDAO.consultar();
            
            try {
                while(rs.next())
                { %>
                <tr>
                    <td><%= rs.getString("cpf") %></td>
                    <td><%= rs.getString("nome") %></td>
                    <td><%= rs.getString("endereco") %></td>
                    <td><%= rs.getString("usuario") %></td>
                    <td><%= rs.getString("senha") %></td>
                </tr>
                <%
                }   
            } catch(SQLException e)
            {
                out.println("Não existem clientes cadastrados.");
            }
            clienteDAO.fecharConexao();
        %>
        </table>
    </body>
</html>
