package ManagedBeans;

import Beans.ProdutoBean;
import DAO.ProdutoDAO;
import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.context.FacesContext;

@ManagedBean(name="Produto")
public class ProdutoManagedBean {
    private int id;
    private String nome;
    private String descricao;
    private int quantidade;
    private double valor;
   
    public void setId(int id) { this.id = id; }
    public void setNome(String nome) { this.nome = nome; }
    public void setDescricao(String descricao) { this.descricao = descricao; }
    public void setQuantidade(int quantidade) { this.quantidade = quantidade; }
    public void setValor(double valor) { this.valor = valor; }
    
    public int getId() { return this.id; }
    public String getNome() { return this.nome; }
    public String getDescricao() { return this.descricao; }
    public int getQuantidade() { return this.quantidade; }
    public double getValor() { return this.valor; }
    
    public String inserirProduto()
    {
        ProdutoDAO produtoDAO = new ProdutoDAO();
        ProdutoBean produto = new ProdutoBean();
        produto.setId(id);
        produto.setNome(nome);
        produto.setDescricao(descricao);
        produto.setQuantidade(quantidade);
        produto.setValor(valor);
        boolean ok = produtoDAO.adicionar(produto);
        produtoDAO.fecharConexao();
        
        if(ok) FacesContext.getCurrentInstance().addMessage(null, new FacesMessage("Produto Inserido!"));
        else FacesContext.getCurrentInstance().addMessage(null, new FacesMessage("Produto nao inserido!"));
        
        return "index";   
    }
    
}
