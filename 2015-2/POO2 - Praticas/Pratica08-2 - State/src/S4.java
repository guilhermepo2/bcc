
public class S4 extends Estado {
	S4(Automato automato)
	{
		super(automato);
		System.out.print("S4 -> ");
	}
	
	public void verificarAlteracaoEstado(char ch)
	{
		if(ch=='d')
		{
			this.getAutomato().setEstado(new S3(this.getAutomato()));
		} else{  System.out.print("X -> "); }
	}
}
