public class BancoDeDados {
	private static BancoDeDados instancia = new BancoDeDados();
	
	private BancoDeDados() 
	{
		System.out.println("Banco de Dados Criado");
	}
	
	public static BancoDeDados getInstancia() {
		return instancia;
	}
	
	public void acessarBD()
	{
		System.out.println("Banco Acessado");
	}
}
