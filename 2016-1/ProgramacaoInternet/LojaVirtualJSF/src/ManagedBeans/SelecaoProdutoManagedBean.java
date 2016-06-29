package ManagedBeans;

import DAO.ProdutoDAO;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.context.FacesContext;

@ManagedBean(name="SelecionarProduto")
public class SelecaoProdutoManagedBean {
    private int id;
    
    public SelecaoProdutoManagedBean()
    {
        super();
    }
    
    public void setId(int id) { this.id = id; }
    public int getId() { return this.id; }
    
    public void selecionarProduto()
    {
        // buscar o item pelo id
        ProdutoDAO produtoDAO = new ProdutoDAO();
        ResultSet meuProduto = produtoDAO.consultarPorId(id);
        
        
        try {
             boolean ok = meuProduto.next();
             if(ok) { // produto existe
                      //inserir no carrinho
                      SessionManager.getInstance().getCarrinho().adicionarItem(meuProduto.getInt("id"), meuProduto.getFloat("valor"), meuProduto.getString("nome"));
                      FacesContext.getCurrentInstance().addMessage(null, new FacesMessage("Produto Inserido no Carrinho"));
                    }
        } catch (SQLException ex) {
            FacesContext.getCurrentInstance().addMessage(null, new FacesMessage("Deu errado o acesso ao banco!!"));
        }
        
    }
}
