public class Compra {
	private String produto;
	private int quantidade;
	
	Compra(String produto, int quantidade)
	{
		this.produto = produto;
		this.quantidade = quantidade;
	}
	
	public String getProduto()
	{
		return this.produto;
	}
	
	public int getQuantidade()
	{
		return this.quantidade;
	}
	
	public String toString()
	{
		return "Produto:" + this.produto + " Quantidade: " + this.quantidade;
	}
}
