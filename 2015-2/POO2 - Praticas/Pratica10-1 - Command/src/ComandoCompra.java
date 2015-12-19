// CONCRETE COMMAND
public class ComandoCompra implements Command {
	Fornecedor fornecedor;
	Compra compra;
	
	ComandoCompra(Compra compra, Fornecedor fornecedor) {
		this.compra = compra;
		this.fornecedor = fornecedor;
	}
	
	public String toString()
	{
		return "Compra de " + compra.getProduto() + " no " + fornecedor.getNome();
	}
	
	public void execute()
	{
		this.fornecedor.comprar(compra);
	}
	public void unexecute()
	{
		this.fornecedor.descomprar(compra);
	}
}
