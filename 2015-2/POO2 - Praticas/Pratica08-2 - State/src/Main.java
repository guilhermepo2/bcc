
public class Main {

	public static void main(String[] args) {
		System.out.print("Automato 1: ");
		Automato t1 = new Automato();
		t1.verificarEstado('a');
		t1.verificarEstado('a');
		t1.verificarEstado('a');
		t1.verificarEstado('c');
		t1.verificarEstado('d');
		t1.verificarEstado('b');
		System.out.print("\nAutomato 2: ");
		
		Automato t2 = new Automato();
		t2.verificarEstado('a');
		t2.verificarEstado('b');
		t2.verificarEstado('a');
		t2.verificarEstado('b');
		t2.verificarEstado('a');
		t2.verificarEstado('c');
		t2.verificarEstado('d');
		t2.verificarEstado('a');
		t2.verificarEstado('a');
		t2.verificarEstado('a');
		t2.verificarEstado('c');
		
		System.out.print("\nAutomato 3: ");
		Automato t3 = new Automato();
		t3.verificarEstado('a');
		t3.verificarEstado('b');
		t3.verificarEstado('c');
		t3.verificarEstado('d');
		t3.verificarEstado('b');
		
		System.out.print("\nAutomato 4: ");
		Automato t4 = new Automato();
		t4.verificarEstado('a');
		t4.verificarEstado('c');
		t4.verificarEstado('d');
		t4.verificarEstado('a');
		
		System.out.print("\nAutomato 5: ");
		Automato t5 = new Automato();
		t5.verificarEstado('a');
		t5.verificarEstado('c');
		t5.verificarEstado('d');
		t5.verificarEstado('b');
		t5.verificarEstado('d');
		t5.verificarEstado('b');

	}

}
