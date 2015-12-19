public class SaqueMaiorException extends Exception
{
    public String toString()
    {
        return "Nao se pode sacar valores maiores que o saldo!";
    }
}