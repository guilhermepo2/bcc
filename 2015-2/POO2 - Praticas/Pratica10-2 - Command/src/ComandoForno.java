
public class ComandoForno implements Command {
	Forno forno;
	
	ComandoForno(Forno forno) {
		this.forno = forno;
	}
	
	public void execute()
	{
		forno.ligarForno();
		forno.setTemperatura(200);
		forno.setTimer(30);
	}
}
