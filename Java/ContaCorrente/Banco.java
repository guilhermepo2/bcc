import java.util.*;

public class Banco 
{
    public static void main(String args[])
    {
        ContaComum cc = new ContaComum();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Saldo Inicial: "+ cc.getSaldo());
        System.out.println("Faca um deposito: ");
        try {
        cc.depositar(scanner.nextDouble());
    }   
        catch(NegativeNumberException e)
        {
            System.out.println("Nao entre com numeros negativos!");
        }
        System.out.println("Saldo: " + cc.getSaldo());
        System.out.println("Faca um saque: ");
        try {
        cc.sacar(scanner.nextDouble());
    }
        catch(NegativeNumberException e)
        {
            System.out.println(e);
        }
        catch(SaqueMaiorException e)
        {
            System.out.println(e);
        }
        System.out.println("Saldo: " + cc.getSaldo());
        
        ContaEspecial ce = new ContaEspecial();
        System.out.println("Saldo Inicial: " + ce.getSaldo());
        System.out.println("Faca um deposito: ");
        try 
        {
        ce.depositar(scanner.nextDouble());
    }
        catch(NegativeNumberException e)
        {
            System.out.println(e);
        }
        System.out.println("Saldo: " + ce.getSaldo());
        System.out.println("Faca um saque: ");
        try {
        ce.sacar(scanner.nextDouble());
    }
        catch(NegativeNumberException e)
        {
            System.out.println(e);
        }
        catch(SaqueMaiorException e)
        {
            System.out.println(e);
        }
        System.out.println("Saldo: " + ce.getSaldo());
    }
}