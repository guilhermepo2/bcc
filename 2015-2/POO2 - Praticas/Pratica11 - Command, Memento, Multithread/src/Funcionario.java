
public class Funcionario extends Thread {
	//pega a instancia do Departamento Singleton
	DepartamentoCompras departamento = DepartamentoCompras.getInstance();
	//pega a instancia do fornecedor singleton
	Fornecedor fornecedor = Fornecedor.getInstance();
	
	private Command c;
	private String[] Produtos ={"Poros", "Poritos", "Doritos", "Mouse"};
	
	public void run()
	{
		System.out.println("Funcionário trabalhando!");
		for(int i = 0; i < 100; i++)
		{
			try{
				sleep(2000);
			} catch (InterruptedException e) {
				System.out.println(e.getMessage());
			}
		
			//gerar nova compra
			c = new ComandoCompra(new Compra(Produtos[(int)(Math.random()*100)%4],(int)(Math.random() * 100)),fornecedor);
			departamento.enviarComando(c);
		}
	}
}
