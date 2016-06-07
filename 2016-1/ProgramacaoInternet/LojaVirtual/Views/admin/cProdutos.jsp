<%-- 
    Document   : cProdutos
    Created on : May 24, 2016, 4:05:14 PM
    Author     : oliveira
--%>

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
        <a href="index.jsp"> << Voltar </a>
        <h1>Cadastrar Produtos</h1>
        <table class="cadastro">
        <form action="CadastrarProduto" method="PÒST">
            <tr>
                <td>id: </td>
                <td><input type="text" name="id"></td>
            </tr>
            <tr>
                <td>nome: </td>
                <td><input type="text" name="nome"></td>
            </tr>
            <tr>
                <td>descricao: </td>
                <td><input type="text" name="descricao"></td>
            </tr>
            <tr>
                <td>quantidade: </td>
                <td><input type="text" name="quantidade"></td>
            </tr>
            <tr>
                <td>valor: </td>
                <td><input type="text" name="valor"></td>
            </tr>
            <tr>
                <td><input type="submit" value="Enviar" /></td>
                <td><input type="reset" value="Limpar" /></td>
            </tr>
        </form>
        </table>
        
        <h2>Produtos Cadastrados</h2>
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
