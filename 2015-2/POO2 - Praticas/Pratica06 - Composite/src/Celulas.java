public class Celulas implements Component {
	private int valor;
	
	Celulas(int valor)
	{
		this.valor = valor;
	}
	
	public void imprimir()
	{
		System.out.print(valor);
	}
}
