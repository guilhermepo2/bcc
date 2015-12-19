//cliente
public class Cliente {

	public static void main(String[] args) {
		//instanciar receivers
		Fornecedor meuFornecedor = new Fornecedor("Mercadinho");
		//criar ordens
		Compra c = new Compra("Poro", 5);
		Compra c2 = new Compra("Poritos", 10);
		//configurar compra
		Command comando = new ComandoCompra(c, meuFornecedor);
		Command comando2 = new ComandoCompra(c2, meuFornecedor);

		//enviar comando
		DepartamentoCompras dc = new DepartamentoCompras("Departamento de Compras");
		dc.enviarComando(comando);
		dc.enviarComando(comando2);
		dc.exibirLog();
		dc.desenviarComando(comando);
		dc.exibirLog();
	}

}
