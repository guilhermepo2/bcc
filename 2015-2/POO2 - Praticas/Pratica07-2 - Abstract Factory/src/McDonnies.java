//concrete factory
public class McDonnies extends FabricaDeLanchesTop {
	public Pao criarPaoTop()
	{
		return new PaoDeMcDonnies();
	}
	public Carne criarCarneTop()
	{
		return new CarneDeMcDonnies();
	}
	public Queijo criarQueijoTop()
	{
		return new QueijoDeMcDonnies();
	}
	
}
