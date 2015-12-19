public class ExibirVenda implements IVisitor {
	public void visitar(Item item) {
		System.out.print(
				"Nome: " + item.p.getNome() + " Tipo: " + item.p.getTipo()
				+ " Preco: " + item.p.getPreco() + " Quantidade Vendida: " + item.getQuantidade()
				+ " Subtotal: R$" + item.getSubtotal() +"\n"
				);
	}
}
