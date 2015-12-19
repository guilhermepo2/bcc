
public class ComandoAr implements Command {
	ArCondicionado ar;
	
	public ComandoAr(ArCondicionado ar) {
		this.ar = ar;
	}
	
	public void execute()
	{
		ar.ligarArCondicionado();
		ar.setTemperatura(22);
	}
}
