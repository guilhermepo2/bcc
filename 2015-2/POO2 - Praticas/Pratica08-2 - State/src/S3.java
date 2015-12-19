
public class S3 extends Estado {
	S3(Automato automato)
	{
		super(automato);
		System.out.print("S3 -> ");
	}
	
	public void verificarAlteracaoEstado(char ch)
	{
		if(ch=='a')
		{
			this.getAutomato().setEstado(new S1(this.getAutomato()));
		} else if(ch=='b')
		{
			this.getAutomato().setEstado(new S4(this.getAutomato()));
		} else{  System.out.print("X -> "); }
	}
}
