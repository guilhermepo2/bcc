
public class Principal {

	@SuppressWarnings("unused")
	public static void main(String[] args) {
		Subject s = new Bolsa();
		
		Observer o1 = new Observador(s);
		Observer o2 = new Observador(s);
		Observer o3 = new Observador(s);
		
		System.out.println("Mudanca 1");
		s.setValor("Petrobras:20.54 \nVale: 30.01 \nOCX: 47.59\n");
		
		System.out.println("Mudanca 2");
		s.setValor("PETR3:10.54 \nPETR4: 9.02\nVALE3: 19.12 \nVALE5: 15.20\n");
		
		System.out.println("Mudanca 3");
		s.setValor("ABEV3: 19.43\n BBAS3: 17.50\nBBDC3:25.05\n");
		
	}

}
