
public abstract class OperadorBinario implements ExpressaoLogica {
	private ExpressaoLogica op1;
	private ExpressaoLogica op2;
	
	public OperadorBinario(ExpressaoLogica op1, ExpressaoLogica op2)
	{
		this.op1 = op1;
		this.op2 = op2;
	}
	
	public ExpressaoLogica getOp1()
	{
		return this.op1;
	}
	
	public ExpressaoLogica getOp2()
	{
		return this.op2;
	}
}
