import java.util.ArrayList;

public class Venda {
	private ArrayList<Item> itens = new ArrayList<Item>();
	
	public void adicionar(Item item) {
		itens.add(item);
	}
	
	public void remover(Item item) {
		itens.remove(item);
	}
	
	public void aceitar(IVisitor visitor) {
		for(int i = 0; i < itens.size(); i++) {
			(itens.get(i)).aceitar(visitor);
		}
	}
}
