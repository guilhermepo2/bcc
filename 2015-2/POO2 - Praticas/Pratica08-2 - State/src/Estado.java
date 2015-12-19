public abstract class Estado {
	Automato automato;
	
	Estado(Automato automato)
	{
		this.automato = automato;
	}
	
	public Automato getAutomato()
	{
		return this.automato;
	}
	
	protected abstract void verificarAlteracaoEstado(char ch);
}