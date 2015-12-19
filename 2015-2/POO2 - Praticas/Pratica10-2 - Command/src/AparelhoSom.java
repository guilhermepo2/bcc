//receiver
public class AparelhoSom {
	@SuppressWarnings("unused")
	private int volume;
	
	AparelhoSom()
	{
		volume = 5;
	}
	
	public void ligarSom()
	{
		System.out.println("Som ligado.");
	}
	
	public void desligarSom()
	{
		System.out.println("Som desligado.");
	}
	
	public void setVolume(int volume)
	{
		this.volume = volume;
		System.out.println("Volume setado para " + volume);
	}
}
