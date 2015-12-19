public class DarPromocaoTipo implements IVisitor {
	String tipo;
	
	public DarPromocaoTipo (String tipo) {
		this.tipo = tipo;
	}
	
	public void visitar(Item item) {
		if(item.p.getTipo() == tipo)
		{
			item.setSubtotal((item.getSubtotal() * 0.9f));
			System.out.println("Desconto em " + item.p.getNome() + " - Novo Valor: R$"
					+ item.getSubtotal());
		}
	}
}
