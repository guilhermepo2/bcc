public class Item {
	Produto p;
	int quantidade;
	float subtotal;
	
	public Item(Produto p, int quantidade) 
	{
		this.p = p;
		this.quantidade = quantidade;
		subtotal = p.getPreco() * quantidade;
	}
	
	public void aceitar(IVisitor visitor){
		visitor.visitar(this);
	}
	
	public void setSubtotal(){
		this.subtotal = this.p.getPreco() * this.quantidade;
	}
	
	public void setSubtotal(float subtotal){
		this.subtotal = subtotal;
	}
	
	public float getSubtotal() {
		return this.subtotal;
	}
	
	public void setProduto(Produto p) {
		this.p = p;
	}
	
	public Produto getProduto(){
		return this.p;
	}
	
	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}
	
	public int getQuantidade() {
		return this.quantidade;
	}
}
