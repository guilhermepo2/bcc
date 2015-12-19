public class ExibirTipo implements IVisitor {
	String tipo;
	public ExibirTipo (String tipo) {
		this.tipo = tipo;
	}
	
	public void visitar(Item item) {
		if(item.p.getTipo() == tipo)
		{
			System.out.print(
					"Nome: " + item.p.getNome() + " Tipo: " + item.p.getTipo()
					+ " Preco: " + item.p.getPreco() + " Quantidade Vendida: " + item.getQuantidade()
					+ " Subtotal: R$" + item.getSubtotal() +"\n"
					);
		}
	}
}
