public class Compra {
	private String codigo;
	private int quantidade;
	private float preco;
	
	public Compra(String codigo, int quantidade, float preco) {
		this.codigo = codigo;
		this.quantidade = quantidade;
		this.preco = preco;
	}
	
	public void compraEfetuada(int quant) {
		this.quantidade -= quant;
	}
	
	public String getCodigo() {
		return this.codigo;
	}
	
	public int getQuantidade() {
		return this.quantidade;
	}
	
	public float getPreco() {
		return this.preco;
	}
}
