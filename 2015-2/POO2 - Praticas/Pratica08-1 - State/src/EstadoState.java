public abstract class EstadoState {
	private ProdutoContext produto;
	
	public EstadoState(ProdutoContext produto)
	{
		this.produto = produto;
	}
	
	public void reestocar(int quantidade)
	{
		produto.setQuantia(produto.getQuantia() + quantidade);
		this.verificarAlteracaoEstado();
	}
	
	public void fazerCompra(int quantidade)
	{
		produto.setQuantia(produto.getQuantia() - quantidade);
		this.verificarAlteracaoEstado();
	}
	
	public ProdutoContext getProduto()
	{
		return produto;
	}
	
	protected abstract void verificarAlteracaoEstado();
}