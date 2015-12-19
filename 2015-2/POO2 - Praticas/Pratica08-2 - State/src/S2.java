
public class S2 extends Estado {
	S2(Automato automato)
	{
		super(automato);
		System.out.print("S2 -> ");
	}
	
	public void verificarAlteracaoEstado(char ch)
	{
		if(ch=='b')
		{
			this.getAutomato().setEstado(new S1(this.getAutomato()));
		} else if (ch=='c') {
			this.getAutomato().setEstado(new S4(this.getAutomato()));
		} else{  System.out.print("X -> "); }
	}
}
