import java.util.ArrayList;

public class Linhas implements Component {
	private ArrayList<Celulas> celulas = new ArrayList<Celulas>();
	
	Linhas(Celulas... celulas)
	{
		for(Celulas c : celulas) 
		{
			this.celulas.add(c);
		}
	}
	
	public void imprimir() 
	{
		for(int i = 0; i < celulas.size(); i++)
		{
			celulas.get(i).imprimir();
			System.out.print("|");
		}
	}
}
