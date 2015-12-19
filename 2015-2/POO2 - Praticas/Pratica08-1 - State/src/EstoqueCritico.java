public class EstoqueCritico extends EstadoState {
	
	public EstoqueCritico(ProdutoContext produto)
	{
		super(produto);
	}
	
	public void fazerCompra(int quantidade)
	{
		if(quantidade > 2)
		{
			System.out.println("O Produto está em Estoque Crítico, não se pode comprar mais de 2 unidades");
			
		} else{
			super.fazerCompra(quantidade);
		}
	}
	
	public void verificarAlteracaoEstado()
	{
		if(this.getProduto().getQuantia() > 10)
		{
			this.getProduto().setEstado(new EstoqueNormal(this.getProduto()));
		} else if(this.getProduto().getQuantia() <= 0)
		{
			this.getProduto().setEstado(new EstoqueEmFalta(this.getProduto()));
		}
	}
}