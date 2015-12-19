

public class ContaInvestimento extends Conta {
	public ContaInvestimento() {
		setRentabilidade(new RentabilidadeT());
		setMensalidade(new MensalidadeNT());
		setMovimentacao(new MovimentacaoC());
		setLimite(new LimiteNT());
	}
}
