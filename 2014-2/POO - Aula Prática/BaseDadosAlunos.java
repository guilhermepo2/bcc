import java.util.*;

public abstract class BaseDadosAlunos
{
    private static ArrayList<Aluno> alunos;
    
    static {
                alunos = (ArrayList<Aluno>)Persist.recuperar("alunos.dat");
                if (alunos == null)
                    alunos = new ArrayList<Aluno>();
            }
    
    
    public static void adicionar(Aluno a)
    {
        alunos.add(a);
        boolean r = Persist.gravar(alunos, "alunos.dat");
    }
    
    public static void listar()
    {
        for(int i = 0; i < alunos.size(); i++)
        {
            Aluno ma = (Aluno)alunos.get(i);
            ma.mostrarDados();
        }
        //for(Aluno a: alunos)
        //{
        //    a.mostrarDados();
        //}
    }
    
    public static Aluno buscar(String matricula)
    {
        for(Aluno a: alunos)
        {
            if (a.getMatricula().equals(matricula))
            {
                return a;
            }
        }
        return null;
    }
    
    public static boolean excluir(String matricula)
    {
        for(Aluno a: alunos)
        {
            if(a.getMatricula().equals(matricula))
            {
                alunos.remove(a);
                return true;
            }
        }
        return false;
    }

    
}