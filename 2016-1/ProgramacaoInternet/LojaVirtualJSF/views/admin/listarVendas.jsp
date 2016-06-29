<%@page import="DAO.ProdutoDAO"%>
<%@page import="DAO.EnvolveDAO"%>
<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="DAO.VendaDAO"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
        <title>Listar Vendas</title>
    </head>
    <body>
        <a href="index.xhtml"> << Voltar </a>
        <h1>Listando Vendas</h1>
        <%
            VendaDAO vendaDAO = new VendaDAO();
            EnvolveDAO envolveDAO = new EnvolveDAO();
            ProdutoDAO produtoDAO = new ProdutoDAO();
            ResultSet todasAsVendas = vendaDAO.consultar();
            ResultSet envolveVendaCpf;
            ResultSet produtosComprados;
        %>
        <table class="table table-hover">
            <tr>
                <td>ID Venda</td>
                <td>CPF Cliente</td>
                <td>Data da Compra</td>
                <td>Valor Frete</td>
                <td>Produtos Comprados</td>
            </tr>
        <%
            try {
              while(todasAsVendas.next())
              { 
                %>
              <tr>
                  <td><%= todasAsVendas.getInt("venda_id") %></td>
                  <td><%= todasAsVendas.getString("cliente_cpf") %></td>
                  <td><%= todasAsVendas.getString("data_compra") %></td>
                  <td><%= todasAsVendas.getDouble("frete") %></td>
                  <%
                    envolveVendaCpf = envolveDAO.consultarComprasCliente(todasAsVendas.getInt("venda_id"));
                    while(envolveVendaCpf.next())
                    {
                        produtosComprados = produtoDAO.consultarPorId(envolveVendaCpf.getInt("produto_id"));
                        while(produtosComprados.next())
                        { %>
                        <td><%= produtosComprados.getString("nome") %></td>
                        <% } 
                    }
                  %>
              </tr>
              <% }
            } catch(SQLException e) {
                out.println("Houve um erro na consulta");
            }
            envolveDAO.fecharConexao();
            produtoDAO.fecharConexao();
            vendaDAO.fecharConexao();
        %>
        </table>
    </body>
</html>
