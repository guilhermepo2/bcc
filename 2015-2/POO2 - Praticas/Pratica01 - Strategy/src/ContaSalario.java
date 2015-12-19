

public class ContaSalario extends Conta {
	public ContaSalario()
	{
		setRentabilidade(new RentabilidadeNT());
		setMensalidade(new MensalidadeNT());
		setMovimentacao(new MovimentacaoS());
		setLimite(new LimiteNT());
	}
}
