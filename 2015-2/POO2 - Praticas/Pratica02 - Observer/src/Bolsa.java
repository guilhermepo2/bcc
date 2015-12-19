import java.util.ArrayList;

public class Bolsa implements Subject {
	private String valor = "Petrobras: 20.54\nVale: 30.01\nOCX: 47.59.";
	private ArrayList<Observer> observadores = new ArrayList<Observer>();
	
	public void adicionarObservador(Observer o)
	{
		observadores.add(o);
	}
	
	public void removerObservador(Observer o)
	{
		observadores.remove(o);
	}
	public void notificarObservadores()
	{
		for(Observer o: observadores)
		{
			o.atualizar(this);
		}
	}
	
	public String getValor()
	{
		return valor;
	}
	public void setValor(String s)
	{
		this.valor = s;
		notificarObservadores();
	}
}