
public class Cliente {

	public static void main(String[] args) {
		FabricaDeLanchesTop lanchonete = new McDonnies();
		Pao paozao = lanchonete.criarPaoTop();
		Carne carne = lanchonete.criarCarneTop();
		Queijo queijo = lanchonete.criarQueijoTop();
		
		paozao.comerPao();
		carne.comerCarne();
		queijo.comerQueijo();

	}

}
