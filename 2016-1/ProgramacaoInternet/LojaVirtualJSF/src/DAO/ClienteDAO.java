package DAO;

import Beans.ClienteBean;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class ClienteDAO extends DataAccessObject {
    /**
     *
     */
    @SuppressWarnings("fallthrough")
    public ClienteDAO()
    {
       super();
    }
    
    /*
        Insere um candidato no banco de Dados
    */
    public boolean adicionar(ClienteBean cliente)
    {
        String query = "insert into cliente values (?,?,?,?,?)";
        try {
            try (PreparedStatement sql = conection.prepareStatement(query)) {
                sql.setString(1,cliente.getCpf());
                sql.setString(2,cliente.getNome());
                sql.setString(3,cliente.getEndereco());
                sql.setString(4,cliente.getUsuario());
                sql.setString(5,cliente.getSenha());
                
                sql.execute();
                return true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.toString());
            return false;
        }
    }
    
    /*
        Remove um cliente do banco de dados
    */
    public boolean remover(ClienteBean cliente)
    {
        String query = "DELETE from cliente WHERE cpf = ?";
        try {
            try (PreparedStatement sql = conection.prepareStatement(query)) {
                sql.setString(1,cliente.getCpf());
                
                sql.execute();
                return true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.toString());
            return false;
        }
    }
    
    public ResultSet consultarPorUsuarioESenha(String usuario, String senha)
    {
        PreparedStatement stmt;
        ResultSet rs = null;
        try { 
         stmt = conection.prepareStatement("select * from cliente WHERE usuario = ? AND senha = ?;"); 
         stmt.setString(1, usuario);
         stmt.setString(2, senha);
         rs = stmt.executeQuery();
        } catch(SQLException e) {
            System.out.println("Houve um erro!");
        }
        return rs;
    }
    
    /*
        Retorna um ResultSet com todos os dados no banco
    */
    public ResultSet consultar()
    {
        PreparedStatement stmt;
        ResultSet rs = null;
        try { 
         stmt = conection.prepareStatement("select * from cliente;"); 
         rs = stmt.executeQuery();
        } catch(SQLException e) {
            System.out.println("Houve um erro!");
        }

        return rs;
    }
    
    
}
