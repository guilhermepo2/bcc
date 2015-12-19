

public class ContaCorrente extends Conta {
	public ContaCorrente()
	{
		setRentabilidade(new RentabilidadeNT());
		setMensalidade(new MensalidadeT());
		setMovimentacao(new MovimentacaoC());
		setLimite(new LimiteT());
	}
}
