
public class S1 extends Estado {
	S1(Automato automato)
	{
		super(automato);
		System.out.print("S1 -> ");
	}
	
	public void verificarAlteracaoEstado(char ch)
	{
		if(ch=='a')
		{
			this.getAutomato().setEstado(new S2(this.getAutomato()));
		} else{  System.out.print("X -> "); }
	}
}
