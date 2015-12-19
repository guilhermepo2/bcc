import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream; 

public abstract class Persist
{
    public static boolean gravar(Object a, String arquivo)
    {
        try
        {
            FileOutputStream arquivoGrav = new FileOutputStream(arquivo);
            ObjectOutputStream objGravar = new ObjectOutputStream(arquivoGrav);
            
            objGravar.writeObject(a);
            objGravar.flush();
            objGravar.close();
            arquivoGrav.flush();
            arquivoGrav.close();
            return true;
        }
        catch(Exception e)
        {
            return false;
        }
    }
    
    public static Object recuperar(String arquivo)
    {
        Object obj = null;
        FileInputStream arquivoLeitura = null;
        ObjectInputStream objLeitura = null;
        try
        {
            arquivoLeitura = new FileInputStream(arquivo);
            objLeitura = new ObjectInputStream(arquivoLeitura);
            
            obj = objLeitura.readObject();
            objLeitura.close();
            arquivoLeitura.close();
        }
        catch(Exception e)
        {
            return null;
        }
        return obj;
    }
}