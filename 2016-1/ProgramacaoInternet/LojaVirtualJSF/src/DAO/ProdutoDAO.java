package DAO;

import Beans.ProdutoBean;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class ProdutoDAO extends DataAccessObject {

    public boolean adicionar(ProdutoBean produto) {
        String query = "insert into produto values (?,?,?,?,?)";
        try {
            try (PreparedStatement sql = conection.prepareStatement(query)) {
                sql.setInt(1,produto.getId());
                sql.setString(2,produto.getNome());
                sql.setString(3,produto.getDescricao());
                sql.setInt(4,produto.getQuantidade());
                sql.setDouble(5,produto.getValor());
                sql.execute();
                return true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.toString());
            return false;
        }
    }

    public boolean remover(ProdutoBean produto) {
        String query = "DELETE from produto WHERE id = ?";
        try {
            try (PreparedStatement sql = conection.prepareStatement(query)) {
                sql.setString(1,Integer.toString(produto.getId()));
                sql.execute();
                return true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.toString());
            return false;
        }
    }

    public ResultSet consultarPorId(int id)
    {
        PreparedStatement stmt;
        ResultSet rs = null;
        try {
            stmt = conection.prepareStatement("select * from produto WHERE id = ?");
            stmt.setInt(1, id);
            rs = stmt.executeQuery();
        } catch(SQLException e) {
            System.out.println("Houve um erro.");
        }
        return rs;
    }
    public ResultSet consultar() {
        PreparedStatement stmt;
        ResultSet rs = null;
        try { 
         stmt = conection.prepareStatement("select * from produto;"); 
         rs = stmt.executeQuery();
         //stmt.close();
        } catch(SQLException e) {
            System.out.println("Houve um erro!");
        }

        return rs;
    }
    
}
