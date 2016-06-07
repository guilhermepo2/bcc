<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="DAO.ClienteDAO"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
        <title>Cadastrar Clientes</title>
        <style>
            input {
                margin-top: 10px;
            }
            
            .cadastro {
                margin-left: 1em;
            }
        </style>
    </head>
    <body>
        <a href="index.jsp"> << Voltar </a>
        <h1>Cadastro de Cliente</h1>
        <table class="cadastro">
        <form action="CadastrarCliente" method="PÒST">
            <tr>
                <td>CPF: </td>
                <td><input type="text" name="cpf"></td>
            </tr>
            <tr>
                <td>Nome: </td>
                <td><input type="text" name="nome"></td>
            </tr>
            <tr>
                <td>Endereço: </td>
                <td><input type="text" name="endereco"></td>
            </tr>
            <tr>
                <td>usuário: </td>
                <td><input type="text" name="usuario"></td>
            </tr>
            <tr>
                <td>senha: </td>
                <td><input type="password" name="senha"></td>
            </tr>
            <tr>
                <td><input type="submit" value="Enviar" /></td>
                <td><input type="reset" value="Limpar" /></td>
            </tr>
        </form>
        </table>
        
        
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
