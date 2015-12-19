public class Cliente {

	public static void main(String[] args) {
		//Criando ações e colocando sucessores
		Acao a1 = new Acao("A1",5,2.99f);
		Acao a2 = new Acao("A2",10, 3.54f );
		Acao a3 = new Acao("A3", 12, 2.41f);
		
		a1.setSucessor(a2);
		a2.setSucessor(a3);
		
		//Exibindo informação das ações
		a1.exibirInformacoes();
		
		//criando e efetuando a compra
		Compra c = new Compra("A2", 2, 3.71f);
		a1.processarCompra(c);
		
		//exibindo as informações novamente para verificar a mudança
		a1.exibirInformacoes();
	}

}
