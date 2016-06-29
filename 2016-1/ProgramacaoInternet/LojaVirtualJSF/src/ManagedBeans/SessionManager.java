package ManagedBeans;

import Beans.ClienteBean;
import Models.Carrinho;
import javax.faces.bean.ManagedBean;

@ManagedBean(name="SessionManager")
public class SessionManager {
    
    public static SessionManager instance = new SessionManager();
    private Carrinho carrinho;
    private ClienteBean cliente;
    private String usuario;
    
    
    public static SessionManager getInstance()
    {
        return instance;
    }
    
    public Carrinho getCarrinho() { return this.carrinho; }
    public void setCarrinho(Carrinho carrinho) { this.carrinho = carrinho; }
    public ClienteBean getCliente() { return this.cliente; }
    public void setCliente(ClienteBean cliente) { this.cliente = cliente; }
    public String getUsuario() { return this.usuario; }
    public void setUsuario(String usuario) { this.usuario = usuario; }
    
    public void printSessionManager()
    {
        System.out.println(usuario);
        System.out.println(cliente.getNome());
        System.out.println(carrinho);
    }

    public void limparSessao() {
        this.carrinho = null;
        this.usuario = null;
        this.cliente = null;
    }
    
}
