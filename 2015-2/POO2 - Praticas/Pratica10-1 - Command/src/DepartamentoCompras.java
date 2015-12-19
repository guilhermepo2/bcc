import java.util.ArrayList;

//INVOKER
public class DepartamentoCompras {
	private String nome;
	private ArrayList<Command> log = new ArrayList<Command>();
	
	DepartamentoCompras(String nome)
	{
		this.nome = nome;
	}
	
	public String getNome()
	{
		return this.nome;
	}
	
	public void exibirLog()
	{
		System.out.println("--------------------------");
		System.out.println("Log: ");
		for(int i = 0; i < log.size(); i++)
		{
			System.out.println(log.get(i).toString());
		}
		System.out.println("--------------------------");
	}
	
	public void enviarComando(Command comando) {
		System.out.println("Deparmento: " + this.nome);
		log.add(comando);
		comando.execute();
	}
	
	public void desenviarComando(Command comando) {
		System.out.println(this.nome + " esta furioso que foi feito um pedido errado.");
		log.remove(comando);
		comando.unexecute();
	}
}
