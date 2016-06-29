package ManagedBeans;

import Beans.ClienteBean;
import DAO.ClienteDAO;
import java.util.ArrayList;
import java.util.List;
import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.context.FacesContext;

@ManagedBean(name="Cliente")
public class ClienteManagedBean {

    private String cpf;
    private String nome;
    private String endereco;
    private String usuario;
    private String senha;
    public List<ClienteBean> clientesCadastrados = new ArrayList<>();
    

    public void setCpf(String cpf) { this.cpf = cpf; }
    public void setNome(String nome) { this.nome = nome; }
    public void setEndereco(String endereco) { this.endereco = endereco; }  
    public void setUsuario(String usuario) { this.usuario = usuario; }
    public void setSenha(String senha) { this.senha = senha; }
    public String getCpf() { return this.cpf; }
    public String getNome() { return this.nome; }
    public String getEndereco() { return this.endereco; }
    public String getUsuario() { return this.usuario; }
    public String getSenha() { return this.senha; }
    
    public String inserirCliente()
    {
        ClienteDAO clienteDAO = new ClienteDAO();
        ClienteBean cliente = new ClienteBean();
        cliente.setCpf(cpf);
        cliente.setEndereco(endereco);
        cliente.setNome(nome);
        cliente.setUsuario(usuario);
        cliente.setSenha(senha);
        boolean ok = clienteDAO.adicionar(cliente);
        clienteDAO.fecharConexao();
        
        if(ok) FacesContext.getCurrentInstance().addMessage(null, new FacesMessage("Usuario Inserido!"));
        else FacesContext.getCurrentInstance().addMessage(null, new FacesMessage("Usuario nao inserido!"));
        
        return "index";   
    }

}
