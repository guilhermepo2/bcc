

public abstract class Conta {
	private Rentabilidade r;
	private Mensalidade m;
	private Movimentacao mov;
	private Limite l;
	
	public void setRentabilidade(Rentabilidade r) 
	{
		this.r = r;
	}
	
	public void setMensalidade(Mensalidade m) 
	{
		this.m = m;
	}
	
	public void setMovimentacao(Movimentacao mov) 
	{
		this.mov = mov;
	}
	
	public void setLimite(Limite l) 
	{
		this.l = l;
	}
	
	public void mostrarRentabilidade()
	{
		this.r.info();
	}
	
	public void mostrarMensalidade()
	{
		this.m.info();
	}
	
	public void mostrarMovimentacao()
	{
		this.mov.info();
	}
	
	public void mostrarLimite()
	{
		this.l.info();
	}
	
	public void mostrarInfo()
	{
		this.r.info();
		this.m.info();
		this.mov.info();
		this.l.info();
	}
	
}