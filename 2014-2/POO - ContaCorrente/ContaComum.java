import java.util.*;

public class ContaComum
{
    public double saldo;
    
    public double getSaldo()
    {
        return this.saldo;
    }
    
    public boolean depositar(double quantia) throws NegativeNumberException
    {
        if (quantia < 0)
        throw new NegativeNumberException();
        
        this.saldo += quantia;
        return true;
    }
    
    public boolean sacar(double quantia) throws NegativeNumberException, SaqueMaiorException
    {
        if (quantia < 0)
        throw new NegativeNumberException();
        
        if(quantia > this.saldo)
        {
            throw new SaqueMaiorException();
        }
        else
        {
            double tarifa = quantia * 0.005;
            System.out.println("Tarifa: " + tarifa);
            this.saldo -= (quantia + tarifa);
            return true;
        }
    }
}