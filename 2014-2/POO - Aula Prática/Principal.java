import java.util.*;

class Principal
{
    public static void main(String args[])
    {
       ArrayList<Aluno> alunos = new ArrayList<Aluno>();
       Aluno a = new Aluno();
       a.setNome("Jose");
       a.setMatricula("123");
       a.setCpf("118113");
       
       Aluno b = new Aluno();
       b.setNome("Nome");
       b.setMatricula("1234");
       b.setCpf("1193");
       
       alunos.add(a);
       alunos.add(b);
       Persist.gravar(alunos,"alunos.dat");
       for(int i = 0; i < 2; i++)
       {
          Aluno xz = (Aluno)alunos.get(i);
          xz.mostrarDados();
       }
       
       ArrayList<Aluno> alunos2 = new ArrayList<Aluno>();
       alunos2 = (ArrayList<Aluno>)Persist.recuperar("alunos.dat");
       for(int i = 0; i < 2; i++)
       {
           Aluno xx = (Aluno)alunos2.get(i);
           xx.mostrarDados();
       }
    }
}