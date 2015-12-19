
public class Cliente {

	public static void main(String[] args) {
		//receiver
		MacroSairDoTrabalho meuMacro = new MacroSairDoTrabalho();
		meuMacro.addCommand(new ComandoAr(new ArCondicionado()));
		meuMacro.addCommand(new ComandoForno(new Forno()));
		meuMacro.addCommand(new ComandoPanela(new PanelaEletrica()));
		meuMacro.addCommand(new ComandoSom(new AparelhoSom()));
		
		//invoker
		CasaInteligente minhaCasa = new CasaInteligente();
		minhaCasa.setMacro(meuMacro);
		
		minhaCasa.sairDoTrabalho();
		

	}

}
