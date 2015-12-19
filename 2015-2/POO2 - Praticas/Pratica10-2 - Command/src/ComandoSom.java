
public class ComandoSom implements Command {
	AparelhoSom som;
	
	ComandoSom(AparelhoSom som)
	{
		this.som = som;
	}
	
	public void execute() {
		som.ligarSom();
		som.setVolume(20);
	}
}
