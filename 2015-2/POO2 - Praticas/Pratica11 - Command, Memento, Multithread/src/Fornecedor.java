// RECEIVER
public class Fornecedor {
	private static Fornecedor instance = new Fornecedor("Mercadinho");
	private String nome;
	private int comprasRealizadas;
	
	public static Fornecedor getInstance()
	{
		return instance;
	}
	
	private Fornecedor(String nome) {
		this.nome = nome;
		comprasRealizadas = 0;
	}
	
	public String getNome()
	{
		return this.nome;
	}
	
	public void comprar(Compra compra)
	{
		System.out.println("Executando Compra em " + this.nome + " - " + compra.toString());
		this.comprasRealizadas += 1;
		//ystem.out.println("Compras Realizadas no Mercadinho: "+ this.comprasRealizadas);
	}
	
	public Memento criarMemento() { return new Memento(this.nome, this.comprasRealizadas); }
	
	public void recuperarMemento(Memento memento)
	{
			System.out.println("Memento sendo resgatado. "+this.nome+" está bem triste.");
			this.nome = memento.getNome();
			this.comprasRealizadas = memento.getComprasRealizadas();
	}
}
