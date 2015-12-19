public class ProdutoContext {
	private int quantidade;
	private EstadoState estado;
	
	ProdutoContext()
	{
		this.quantidade = 0;
		estado = new EstoqueEmFalta(this);
	}
	
	public void reestocar(int quantidade)
	{
		System.out.println("Reestocando em quantidade: " + quantidade);
		estado.reestocar(quantidade);
	}
	
	public void fazerCompra(int quantidade)
	{
		System.out.println("Fazendo Compra de " + quantidade);
		estado.fazerCompra(quantidade);
	}
	
	public void setEstado(EstadoState estado)
	{
		this.estado = estado;
	}
	
	public int getQuantia()
	{
		return this.quantidade;
	}
	
	public void setQuantia(int quantidade)
	{
		this.quantidade = quantidade;
	}
}
