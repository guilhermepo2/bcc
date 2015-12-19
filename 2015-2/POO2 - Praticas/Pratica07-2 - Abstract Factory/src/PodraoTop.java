//concrete factory
public class PodraoTop extends FabricaDeLanchesTop {
	public Pao criarPaoTop()
	{
		return new PaoDePodrao();
	}
	public Carne criarCarneTop()
	{
		return new CarneDePodrao();
	}
	public Queijo criarQueijoTop()
	{
		return new QueijoDePodrao();
	}
	
}
