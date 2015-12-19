
public class EstoqueEmFalta extends EstadoState {
	
	public EstoqueEmFalta(ProdutoContext produto){
		super(produto);
	}
	
	public void fazerCompra(int quantidade)
	{
		System.out.println("O Produto está em Falta.");
	}
	
	public void verificarAlteracaoEstado()
	{
		if(this.getProduto().getQuantia() > 10)
		{
			this.getProduto().setEstado(new EstoqueNormal(this.getProduto()));
		} else if(this.getProduto().getQuantia() > 0)
		{
			this.getProduto().setEstado(new EstoqueCritico(this.getProduto()));
		}
	}
}
