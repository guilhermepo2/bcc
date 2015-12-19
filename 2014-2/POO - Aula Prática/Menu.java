import java.util.*;

public class Menu
{
    public int ler() throws OpcaoInvalidaException
    {
        int a;
        Scanner s = new Scanner(System.in);
        System.out.println("Digite uma opcao: ");
        while(true)
        {
            try
            {
                a = s.nextInt();
                System.out.println("OK!");
                break;
            }
            catch(InputMismatchException e)
            {
                throw new OpcaoInvalidaException();
            }
        }
        return a;
    }
}