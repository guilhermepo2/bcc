
public class CasaInteligente {
	Command meuMacro;
	
	public void setMacro(Command c)
	{
		meuMacro = c;
	}
	
	public void sairDoTrabalho()
	{
		meuMacro.execute();
	}
}
