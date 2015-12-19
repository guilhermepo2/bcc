
public class Main {

	public static void main(String[] args) {
		ExpressaoLogica e = new AND(new AND(new Operando(true),
											new XOR(new Operando(false),
													new Operando(true))),
									new NOT(new Operando(false)));
		
		System.out.print(e.operacao());

	}

}
