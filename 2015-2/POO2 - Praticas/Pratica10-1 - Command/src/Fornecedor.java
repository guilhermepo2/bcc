// RECEIVER
public class Fornecedor {
	private String nome;
	
	Fornecedor(String nome) {
		this.nome = nome;
	}
	
	public String getNome()
	{
		return this.nome;
	}
	
	public void comprar(Compra compra)
	{
		System.out.println("Executando Compra em " + this.nome + " - " + compra.toString());
	}
	
	public void descomprar(Compra compra)
	{
		System.out.println(this.nome + " Esta muito triste que voce nao vai mais comprar: " + compra.toString());     
	}
}
