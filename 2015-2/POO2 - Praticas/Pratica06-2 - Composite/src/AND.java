
public class AND extends OperadorBinario {
	
	public AND(ExpressaoLogica op1, ExpressaoLogica op2)
	{
		super(op1, op2);
	}
	
	public boolean operacao() {
		return getOp1().operacao() && getOp2().operacao();
	}

}
