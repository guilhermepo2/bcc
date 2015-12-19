public class EstoqueNormal extends EstadoState {
	public EstoqueNormal(ProdutoContext produto) {
		super(produto);
	}
	
	public void verificarAlteracaoEstado()
	{
		if(this.getProduto().getQuantia() < 0)
		{
			this.getProduto().setEstado(new EstoqueEmFalta(this.getProduto()));
		} else if(this.getProduto().getQuantia() <= 10)
		{
			this.getProduto().setEstado(new EstoqueCritico(this.getProduto()));
		}
	}
}
