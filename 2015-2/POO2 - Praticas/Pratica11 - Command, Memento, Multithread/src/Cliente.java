//cliente
public class Cliente {

	public static void main(String[] args) {
		DepartamentoCompras dc = DepartamentoCompras.getInstance();
		Funcionario f = new Funcionario();
		Funcionario f2 = new Funcionario();
		
		dc.start();
		f.start();
		f2.start();
	}

}
