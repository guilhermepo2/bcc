import java.util.ArrayList;

//INVOKER
public class DepartamentoCompras extends Thread {
	private static DepartamentoCompras instance = new DepartamentoCompras("Departamento Compras");
	private String nome;
	private int maxSize = 10;
	private ArrayList<Command> queue = new ArrayList<Command>();
	private ArrayList<Command> log = new ArrayList<Command>();
	
	public static DepartamentoCompras getInstance()
	{
		return instance;
	}
	
	private DepartamentoCompras(String nome)
	{
		this.nome = nome;
	}
	
	public String getNome()
	{
		return this.nome;
	}
	
	public void run()
	{
		for (int i=0; i<100;i++){
            try{
               sleep(2000); //Coloca a thread para dormir pelo tempo em milisegundos
            }
            catch(InterruptedException e){
            }    
            
            this.aprovarComando();
        }
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
	
	public synchronized void enviarComando(Command comando) {
		while(queue.size() == maxSize)
		{
			try{
				System.out.println(">>>>> Funcionário Dormiu. Pedidos Cheios <<<<<");
				wait();
			}
			catch(InterruptedException e) {
				System.out.println(e.getMessage());
			}
		}
		//System.out.println("Deparmento: " + this.nome);
		queue.add(comando);
		notifyAll();
		//comando.execute();
	}
	
	public synchronized void aprovarComando()
	{
		while(queue.size() == 0)
		{
			try{
				System.out.println(">>>>> Departamento Dormiu, nenhum pedido a ser aprovado <<<<<");
				wait();
			} catch(InterruptedException e) {
				System.out.println(e.getMessage());
			}
		}
		queue.get(0).execute();
		log.add(queue.get(0));
		queue.remove(0);
	}
	
	public void desfazer() {
		System.out.println(this.nome + " esta furioso que foi feito um pedido errado.");
		log.get(log.size()-1).unexecute();
		log.remove(log.size()-1);
	}
}
