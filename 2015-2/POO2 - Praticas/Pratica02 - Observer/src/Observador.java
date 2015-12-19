public class Observador implements Observer {
	public Observador(Subject s)
	{
		s.adicionarObservador(this);
	}
	
	public void atualizar(Subject s)
	{
		System.out.println("Novas Informacoes!\n"+s.getValor());
	}
}
