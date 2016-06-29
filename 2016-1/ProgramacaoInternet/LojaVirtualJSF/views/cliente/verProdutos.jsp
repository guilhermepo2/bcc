<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="DAO.ProdutoDAO"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
        <title>Cadastrar Produtos</title>
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
        <a href="selecionar_produtos.xhtml"> << Voltar </a>
        <h1>Consultar Produtos</h1>
        <%
            ProdutoDAO produtoDAO = new ProdutoDAO();
            ResultSet rs = produtoDAO.consultar();
        %>
        
        <table class="table table-hover">
            <tr>
                <td>ID</td>
                <td>Nome</td>
                <td>Descricao</td>
                <td>Quantidade</td>
                <td>Preco</td>
            </tr>
        <%
            try {
                while(rs.next())
                { %>
                <tr>
                    <td><%= rs.getInt("id") %></td>
                    <td><%= rs.getString("nome") %></td>
                    <td><%= rs.getString("descricao") %></td>
                    <td><%= rs.getInt("quantidade") %></td>
                    <td><%= rs.getDouble("valor") %></td>
                </tr>
                <%
                }   
            } catch(SQLException e)
            {
                out.println("Não existem produtos cadastrados.");
            }
            produtoDAO.fecharConexao();
        %>
        </table>
    </body>
</html>
