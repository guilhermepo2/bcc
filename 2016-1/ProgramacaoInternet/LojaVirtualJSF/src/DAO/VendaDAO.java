package DAO;

import Beans.VendaBean;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class VendaDAO extends DataAccessObject {
    
    public VendaDAO()
    {
        super();
    }
    
    public boolean adicionar(VendaBean venda)
    {
        String query = "insert into venda values (?, ?, ?, ?)";
        try {
            try(PreparedStatement sql = conection.prepareStatement(query)) {
               sql.setInt(1,venda.getVendaId());
               sql.setString(2,venda.getClienteCpf());       
               //DateFormat df = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
               //String reportDate = df.format(venda.getDataCompra());
               sql.setDate(3, venda.getDataCompra());
               sql.setDouble(4, venda.getFrete());
               
               sql.execute();
               return true;
            }
        } catch(SQLException ex) {
            System.out.println(ex.toString());
            return false;
        }
    }
    
    public boolean remover(VendaBean venda)
    {
        String query = "DELETE from venda WHERE venda_id = ?";
        try {
            try (PreparedStatement sql = conection.prepareStatement(query)) {
                sql.setString(1,Integer.toString(venda.getVendaId()));
                sql.execute();
                return true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.toString());
            return false;
        }
    }
    
    public int proximoSequencia()
    {
        PreparedStatement stmt;
        ResultSet rs;
        int prox = 0;
        try { 
         stmt = conection.prepareStatement("select MAX(venda_id) from venda;"); 
         rs = stmt.executeQuery();
         rs.next();
         prox = rs.getInt("max");
         prox += 1;
        } catch(SQLException e) {
            System.out.println("Erro: " + e.toString());
            System.out.println("Houve um erro!");
        }
        return prox;
    }
    public ResultSet consultar()
    {
        PreparedStatement stmt;
        ResultSet rs = null;
        try { 
         stmt = conection.prepareStatement("select * from venda;"); 
         rs = stmt.executeQuery();
        } catch(SQLException e) {
            System.out.println("Houve um erro!");
        }

        return rs;
    }
}
