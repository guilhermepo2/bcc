public class Acao {
	private String codigo;
	private int quantidade;
	private float preco;

	private Acao sucessor;
	public Acao(String codigo, int quantidade, float preco) 
	{
		this.codigo = codigo;
		this.quantidade = quantidade;
		this.preco = preco;
	}
	
	public void setSucessor(Acao sucessor) {
		this.sucessor = sucessor;
	}
	
	public Acao getSucessor() {
		return this.sucessor;
	}
	
	public String getCodigo(){
		return this.codigo;
	}
	
	public int getQuantidade(){
		return this.quantidade;
	}
	
	public float getPreco(){
		return this.preco;
	}
	
	public void exibirInformacoes() {
		System.out.println(this.codigo + " - Quantidade: " + this.quantidade + " a R$" + this.preco);
		if(this.getSucessor() != null)
			this.getSucessor().exibirInformacoes();
	}
	
	public void processarCompra(Compra compra)
	{
		if (compra.getCodigo() == this.codigo)
		{
			if(this.quantidade > 0 && 
					this.preco <= compra.getPreco()) 
			{
				if(this.quantidade <= compra.getQuantidade()){
					compra.compraEfetuada(this.quantidade);
					System.out.println(this.codigo + " Comprada em " + this.quantidade
							+ " unidades a R$" + this.preco);
				}
				else if(this.quantidade > compra.getQuantidade()) {
					System.out.println(this.codigo + " Comprada em " + compra.getQuantidade()
					+ " unidades a R$" + this.preco);
					this.quantidade -= compra.getQuantidade();
					compra.compraEfetuada(compra.getQuantidade());
				}
			}
		}
		if (this.getSucessor() != null && compra.getQuantidade() > 0) {
			this.getSucessor().processarCompra(compra);
		}
	}
	
}