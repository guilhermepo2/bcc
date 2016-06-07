package DAO;

import Beans.ClienteBean;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public abstract class DataAccessObject {
    Connection conection;
    
    public DataAccessObject() {
         try {
         Class.forName("org.postgresql.Driver");   
        } catch(Exception e) {
            System.out.println("Erro.");
        }
        
        try{
          conection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/lojavirtual", "postgres", "dbpassword");
          PreparedStatement stmt = conection.prepareStatement("SET search_path to LOJAVIRTUAL;"); 
          stmt.execute();
        } catch(SQLException e) {
            System.out.println(e.toString());
            System.out.println("Não foi possível conectar ao Banco.");
        }
    }
    
    public void fecharConexao()
    {
        try {
            conection.close();
        } catch(SQLException e)
        {
            System.out.println("Conexão não pode ser fechada.");
        }
        
    }
    
    //public abstract boolean adicionar(ClienteBean cliente);
    //public abstract boolean remover(ClienteBean cliente);
    //public abstract ResultSet consultar();
}
