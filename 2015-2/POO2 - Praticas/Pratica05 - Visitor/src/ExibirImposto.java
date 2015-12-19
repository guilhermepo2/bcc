public class ExibirImposto implements IVisitor {
	public void visitar(Item item) {
		System.out.print(
				"Imposto Pago em " + item.p.getNome() + ": R$" + item.quantidade * item.p.getPreco() * item.p.getImposto()
				 + "\n");
	}
}
