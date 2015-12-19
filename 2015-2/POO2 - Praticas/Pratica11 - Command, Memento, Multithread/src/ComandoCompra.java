// CONCRETE COMMAND
public class ComandoCompra implements Command {
	Fornecedor fornecedor;
	Compra compra;
	private Memento m;
	
	ComandoCompra(Compra compra, Fornecedor fornecedor) {
		this.compra = compra;
		this.fornecedor = fornecedor;
		m = fornecedor.criarMemento();
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
		this.fornecedor.recuperarMemento(m);
	}
}
