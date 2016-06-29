package Beans;

public class ProdutoBean {
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
}
