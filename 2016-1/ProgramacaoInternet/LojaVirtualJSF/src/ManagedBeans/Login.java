/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ManagedBeans;

import Beans.ClienteBean;
import DAO.ClienteDAO;
import Models.Carrinho;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.context.FacesContext;

/**
 *
 * @author oliveira
 */
@ManagedBean(name="Login")
public class Login {
    private String usuario;
    private String senha;
    
    public void setUsuario(String usuario) { this.usuario = usuario; }
    public String getUsuario() { return this.usuario; }
    public void setSenha(String senha) { this.senha = senha; }
    public String getSenha() { return this.senha; }
    
    public String efetuarLogin()
    {
        // verificar login
        if(usuario.equals("admin") && senha.equals("admin"))
        {
            SessionManager.getInstance().setUsuario("admin");
            return "admin/index";
        }
        else {
            ClienteDAO clienteDAO = new ClienteDAO();
            ResultSet usuarioBD = clienteDAO.consultarPorUsuarioESenha(usuario, senha);
            try {
                boolean ok = usuarioBD.next();
                if(ok) {
                        ClienteBean cliente = new ClienteBean();
                        cliente.setCpf(usuarioBD.getString("cpf"));
                        cliente.setNome(usuarioBD.getString("nome"));
                        cliente.setEndereco(usuarioBD.getString("endereco"));
                        cliente.setUsuario(usuarioBD.getString("usuario"));
                        cliente.setSenha(usuarioBD.getString("senha"));
                        
                        SessionManager.getInstance().setCarrinho(new Carrinho());
                        SessionManager.getInstance().setCliente(cliente);
                        SessionManager.getInstance().setUsuario(usuario);
                        
                        return "cliente/index";
                } else {
                    // erro de usuario nao existente
                    FacesMessage message = new FacesMessage("O Usuario nao existe!");
                    FacesContext context = FacesContext.getCurrentInstance();
                    context.addMessage(null, message);
                    return "index";
                }
            } catch(SQLException e) {
                FacesContext.getCurrentInstance().addMessage(null, new FacesMessage("Deu errado o acesso ao banco!!"));
                return "index";
            }
        }
    }
}
