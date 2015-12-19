
public class Main {

	public static void main(String[] args) {
		
		//cliente 1
		BancoDeDados db = BancoDeDados.getInstancia();
		db.acessarBD();
		//cliente 2
		BancoDeDados db2 = BancoDeDados.getInstancia();
		db2.acessarBD();
		//cliente 3
		BancoDeDados db3 = BancoDeDados.getInstancia();
		db3.acessarBD();
		
		/*
		 * Saída:
		 	Banco de Dados Criado
			Banco Acessado
			Banco Acessado
			Banco Acessado 
		 * Como é possível ver, o Banco é criado apenas uma vez.
		 */
	}

}
