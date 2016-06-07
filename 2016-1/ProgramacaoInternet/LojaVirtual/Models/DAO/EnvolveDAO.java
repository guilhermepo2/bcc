package DAO;

import Beans.EnvolveBean;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class EnvolveDAO extends DataAccessObject {
    public EnvolveDAO() {
        super();
    }
    
    public boolean adicionar(EnvolveBean envolve)
    {
        String query = "insert into envolve(venda_id, produto_id) values (?, ?)";
        try {
            try(PreparedStatement sql = conection.prepareStatement(query)) {
               //sql.setString(1,Integer.toString(envolve.getEnvolveId()));
               sql.setInt(1,envolve.getVendaId());       
               sql.setInt(2,envolve.getProdutoId());
               
               sql.execute();
               return true;
            }
        } catch(SQLException ex) {
            System.out.println(ex.toString());
            return false;
        }
    }
    
    public boolean remover(EnvolveBean envolve)
    {
        String query = "DELETE from envolve WHERE envolve_id = ?";
        try {
            try (PreparedStatement sql = conection.prepareStatement(query)) {
                sql.setString(1,Integer.toString(envolve.getEnvolveId()));
                
                sql.execute();
                return true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.toString());
            return false;
        }
    }
    
    public ResultSet consultarComprasCliente(int venda_id)
    {
        PreparedStatement stmt;
        ResultSet rs = null;
        try {
            stmt = conection.prepareStatement("select * from envolve WHERE venda_id = ?");
            stmt.setInt(1, venda_id);
            rs = stmt.executeQuery();
            
        } catch(SQLException e) {
            System.out.println("Houve um erro!");
        }
        
        return rs;
    }
    
    public ResultSet consultar()
    {
        PreparedStatement stmt;
        ResultSet rs = null;
        try { 
         stmt = conection.prepareStatement("select * from envolve;"); 
         rs = stmt.executeQuery();
        } catch(SQLException e) {
            System.out.println("Houve um erro!");
        }

        return rs;
    }
}
