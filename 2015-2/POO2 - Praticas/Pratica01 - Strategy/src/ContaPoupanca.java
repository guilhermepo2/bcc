

public class ContaPoupanca extends Conta {
	public ContaPoupanca()
	{
		setRentabilidade(new RentabilidadeT());
		setMensalidade(new MensalidadeNT());
		setMovimentacao(new MovimentacaoS());
		setLimite(new LimiteNT());
	}
}
