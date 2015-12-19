public class Comercio {

	public static void main(String[] args) {
		Venda v = new Venda();
		v.adicionar(new Item(new Produto("Batata", "Legume", 10, 0.99f, 0.1f), 5));
		v.adicionar(new Item(new Produto("Cenoura", "Legume", 15, 0.69f, 0.08f), 7));
		v.adicionar(new Item(new Produto("Cheetos", "Salgadinho", 10, 1.99f, 0.2f), 2));
		
		
		v.aceitar(new ExibirVenda()); //1
		v.aceitar(new ExibirImposto()); //2
		v.aceitar(new DarPromocaoTipo("Legume")); //3
		v.aceitar(new ExibirTipo("Legume")); //4

	}

}
