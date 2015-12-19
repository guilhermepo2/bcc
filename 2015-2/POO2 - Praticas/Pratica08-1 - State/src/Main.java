
public class Main {

	public static void main(String[] args) {
		ProdutoContext manga = new ProdutoContext();
		System.out.println("Quantia: " + manga.getQuantia());
		manga.fazerCompra(5);
		manga.reestocar(5);
		manga.fazerCompra(5);
		manga.reestocar(15);
		System.out.println("Quantia: " + manga.getQuantia());
		manga.fazerCompra(5);
		System.out.println("Quantia: " + manga.getQuantia());
	}

}
