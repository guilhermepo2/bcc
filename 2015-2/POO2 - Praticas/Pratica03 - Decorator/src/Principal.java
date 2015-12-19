public class Principal {

	public static void main(String[] args) {
		Sanduiche sanduicha1;
		//criando meu sanduba
		sanduicha1 = new SanduicheConcreto();
		
		//escolhendo o pao Italiano ou 3 Queijos
		sanduicha1 = new PaoItaliano(sanduicha1);
		//escolhendo recheio de Frango ou Almondega
		sanduicha1 = new RecheioFrango(sanduicha1);
		//escolhendo quejo cheddar prato ou suico
		sanduicha1 = new QueijoCheddar(sanduicha1);
		//escolhendo molho Barbecue Parmesao Mostarda Mel ou Mostarda e Mel
		sanduicha1 = new MolhoMostarda(sanduicha1);
		sanduicha1 = new MolhoMel(sanduicha1);
		sanduicha1 = new MolhoMostardaMel(sanduicha1);
		//escolhendo a salada
		//nao
		
		//System.out.println(sanduicha1.getPreco());
		//System.out.println(sanduicha1.getDescricao());
		//System.out.println("NIce Taste my friend :^)");
		
		//sanduiche2
		Sanduiche s;
		s = new SanduicheConcreto();
		s = new Pao3Queijos(s);
		s = new RecheioAlmondega(s);
		s = new QueijoSuico(s);
		s = new MolhoBarbecue(s);
		s = new MolhoParmesao(s);
		
		//System.out.println(s.getPreco());
		//System.out.println(s.getDescricao());
		//System.out.println("NIce Taste my friend :^)");
		
		Sanduiche bissoSandwich;
		bissoSandwich = new SanduicheConcreto();
		bissoSandwich = new RecheioAlmondega(bissoSandwich);
		bissoSandwich = new QueijoCheddar(bissoSandwich);
		bissoSandwich = new QueijoCheddar(bissoSandwich);
		bissoSandwich = new QueijoCheddar(bissoSandwich);
		bissoSandwich = new MolhoBarbecue(bissoSandwich);
		
		System.out.println(bissoSandwich.getPreco());
		System.out.println(bissoSandwich.getDescricao());
		System.out.println("NIce Taste my friend :^)");
		
		

	}

}
