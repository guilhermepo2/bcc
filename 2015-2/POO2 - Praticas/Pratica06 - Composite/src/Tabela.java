import java.util.ArrayList;

public class Tabela implements Component {
	private ArrayList<Linhas> linhas = new ArrayList<Linhas>();
	
	Tabela(Linhas... linhas)
	{
		for(Linhas l : linhas)
		{
			this.linhas.add(l);
		}
	}
	public void imprimir()
	{
		for(int i = 0; i < linhas.size(); i++)
		{
			linhas.get(i).imprimir();
			System.out.print("\n");
		}
	}
}
