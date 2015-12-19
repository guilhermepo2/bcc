// Memento do Fornecedor

public class Memento {
	private String nome;
	private int comprasRealizadas;
	
	Memento(String nome, int comprasRealizadas)
	{
		this.nome = nome;
		this.comprasRealizadas = comprasRealizadas;
	}
	
	public String getNome(){ return this.nome; }
	public int getComprasRealizadas() { return this.comprasRealizadas; }
}
