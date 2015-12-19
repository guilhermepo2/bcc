
public class Main {

	public static void main(String[] args) {
		
		Component tabela = new Tabela(new Linhas(new Celulas(1), new Celulas(2), new Celulas(3), new Celulas(91)),
									  new Linhas(new Celulas(3), new Celulas(4), new Celulas(5), new Celulas(91)),
									  new Linhas(new Celulas(6), new Celulas(7), new Celulas(8), new Celulas(91)),
									  new Linhas(new Celulas(9), new Celulas(10), new Celulas(11), new Celulas(91)));
		
		tabela.imprimir();

	}

}
