//receiver
public class Forno {
	@SuppressWarnings("unused")
	private int timer;
	@SuppressWarnings("unused")
	private int temperatura;
	
	public void ligarForno()
	{
		System.out.println("Forno Ligado.");
	}
	
	public void desligarForno()
	{
		System.out.println("Forno Desligado.");
	}
	
	public void setTimer(int timer)
	{
		System.out.println("Timer setado para: " + timer + " graus");
		this.timer = timer;
	}
	
	public void setTemperatura(int temperatura)
	{
		System.out.println("Temperatura setada para " + temperatura + " graus.");
		this.temperatura = temperatura;
	}
}
