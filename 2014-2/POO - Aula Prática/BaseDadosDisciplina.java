import java.util.*;

public abstract class BaseDadosDisciplina
{
    private static ArrayList<Disciplina> disciplinas = new ArrayList<Disciplina>();
    
    public static void adicionar(Disciplina d)
    {
        disciplinas.add(d);
    }
    
    public static void listar()
    {
        for(Disciplina d: disciplinas)
        {
            d.mostrarDados();
        }
    }
}