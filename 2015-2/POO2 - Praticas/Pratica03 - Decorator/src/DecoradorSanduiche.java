public abstract class DecoradorSanduiche implements Sanduiche {
	protected Sanduiche sanduicheDecorado;
	protected double preco;
	protected String produto;
	
	public DecoradorSanduiche(Sanduiche sanduiche)
	{
		this.sanduicheDecorado = sanduiche;
	}
	
	public double getPreco()
	{
		return sanduicheDecorado.getPreco() + this.preco;
	}
	
	public String getDescricao()
	{
		return sanduicheDecorado.getDescricao() + ", " + this.produto;
	}
}