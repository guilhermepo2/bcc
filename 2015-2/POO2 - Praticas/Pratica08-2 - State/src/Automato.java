
public class Automato {
	private Estado estado;
	//private String sequencia;
	//private int contador;
	
	//Automato(String sequencia)
	Automato()
	{
		//this.sequencia = sequencia;
		//this.contador = 0;
		this.estado = new S1(this);
	}

	public void verificarEstado(char ch)
	{
		estado.verificarAlteracaoEstado(ch);
	}
	
	public void setEstado(Estado estado){
		this.estado = estado;
	}
}
