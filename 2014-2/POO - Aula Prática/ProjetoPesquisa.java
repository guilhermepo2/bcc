import java.util.*;

public class ProjetoPesquisa
{
    private String codigo, titulo;
    Date inicio, fim;
    Professor ProfessorResposavel;
    private ArrayList<Pesquisador> equipe = new ArrayList<Pesquisador>();
    
    public void adicionarProfessor(Professor p)
    {
        equipe.add(p);
    }
    
    public void adicionarAluno(Aluno a)
    {
        equipe.add(a);
    }
}