public class Produto {
	private String nome;
	private String tipo;
	private int quantidade;
	private float preco;
	private float imposto;
	
	public Produto(String nome, String tipo, int quantidade,
					float preco, float imposto)
	{
		this.nome = nome;
		this.tipo = tipo;
		this.quantidade = quantidade;
		this.preco = preco;
		this.imposto = imposto;
	}
	
	public String getNome(){
		return this.nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getTipo() {
		return this.tipo;
	}
	
	public void setTipo(String tipo) {
		this.tipo = tipo;
	}
	
	public int getQuantidade() {
		return this.quantidade;
	}
	
	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}
	
	public float getPreco() {
		return this.preco;
	}
	
	public void setPreco(float preco) {
		this.preco = preco;
	}
	
	public float getImposto() {
		return this.imposto;
	}
	
	public void setImposto(float imposto) {
		this.imposto = imposto;
	}
}
