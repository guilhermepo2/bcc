public class SanduicheConcreto implements Sanduiche {
	private double preco;
	private String produto;
	
	SanduicheConcreto()
	{
		this.preco = 0.0;
		this.produto = "Sanduiche";
	}
	
	public double getPreco()
	{
		return this.preco;
	}
	public String getDescricao()
	{
		return this.produto;
	}
}
