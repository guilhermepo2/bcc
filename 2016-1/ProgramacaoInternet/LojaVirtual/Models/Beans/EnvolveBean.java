package Beans;

public class EnvolveBean {
    private int envolveId;
    private int vendaId;
    private int produtoId;
    
    public void setEnvolveId(int envolveId) { this.envolveId = envolveId; }
    public void setVendaId(int vendaId) { this.vendaId = vendaId; }
    public void setProdutoId(int produtoId) { this.produtoId = produtoId; }
    
    public int getEnvolveId() { return this.envolveId; }
    public int getVendaId() { return this.vendaId; }
    public int getProdutoId() { return this.produtoId; }
}
