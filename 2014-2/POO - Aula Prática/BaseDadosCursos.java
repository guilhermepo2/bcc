import java.util.*;

public abstract class BaseDadosCursos 
{
    private static ArrayList<Curso> cursos = new ArrayList<Curso>();
    
    public static Curso buscarCurso(int codcurso)
    {
        for(Curso c: cursos)
        {
            if(c.getCodigo() == codcurso)
            {
                return c;
            }
        }
        return null;
    }
}