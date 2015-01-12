import java.util.*;

public class ContaEspecial extends ContaComum
{
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
            double tarifa = quantia * 0.001;
            System.out.println("Tarifa: " + tarifa);
            this.saldo -= (quantia + tarifa);
            return true;
        }
    }
}