public class Operando implements ExpressaoLogica {
	private boolean conteudo;
	
	public Operando(boolean conteudo)
	{
		this.conteudo = conteudo;
	}
	
	public boolean operacao()
	{
		return this.conteudo;
	}
}
