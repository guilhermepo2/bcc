
public class NOT implements ExpressaoLogica {
	private ExpressaoLogica op1;
	
	NOT(ExpressaoLogica op1)
	{
		this.op1 = op1;
	}
	
	public ExpressaoLogica getOp1()
	{
		return this.op1;
	}
	
	public boolean operacao()
	{
		return !(getOp1().operacao());
	}
}
