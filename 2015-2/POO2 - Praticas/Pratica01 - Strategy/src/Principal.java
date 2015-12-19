public class Principal {

	public static void main(String[] args) {
		ContaCorrente cc = new ContaCorrente();
		ContaInvestimento ci = new ContaInvestimento();
		ContaPoupanca cp = new ContaPoupanca();
		ContaSalario cs = new ContaSalario();
		
		System.out.println("Conta Corrente: ");
		cc.mostrarInfo();
		System.out.println("\nConta Investimento: ");
		ci.mostrarInfo();
		System.out.println("\nConta Poupanca: ");
		cp.mostrarInfo();
		System.out.println("\nConta Salario: ");
		cs.mostrarInfo();

	}

}
