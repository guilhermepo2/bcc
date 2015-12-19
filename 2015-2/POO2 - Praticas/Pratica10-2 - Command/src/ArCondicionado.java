//receiver
public class ArCondicionado {
	
	@SuppressWarnings("unused")
	private int temperatura;
	
	ArCondicionado()
	{
		temperatura = 25;
	}
	
	public void ligarArCondicionado()
	{
		System.out.println("Ar Ligado.");
	}
	
	public void desligarArCondicionado()
	{
		System.out.println("Ar Desligado.");
	}
	
	public void setTemperatura(int temperatura)
	{
		System.out.println("Temperatura setada para: " + temperatura + " graus.");
		this.temperatura = temperatura;
	}
}
