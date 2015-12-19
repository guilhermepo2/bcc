import java.util.Scanner;
import javax.swing.JOptionPane;
import java.io.Serializable;

public class Aluno extends Pessoa implements Pesquisador, Serializable
{
    private String matricula;
    private Curso curso;
    
    
    public String getMatricula()
    {
        return this.matricula;
    }
    
    Aluno()
    {
    }
    
    public String getNome()
    {
        return "teste";
    }
    public String getTipo()
    {
        return "teste";
    }
    
    Aluno(Curso cursando)
    {
        this.curso = cursando;
    }
    
    Aluno(String matricula, Curso cursando)
    {
        this.matricula = matricula;
        this.curso = cursando;
    }
    
    public boolean setNome(String nome)
    {
        if(nome.length() > 0)
        {
            this.nome = nome;
            return true;
        }
        else
        {
            System.out.println("Nome Invalido!");
            return false;
        }
    }
    public boolean setMatricula(String matricula)
    {
        if(matricula.length() > 0)
        {
            this.matricula = matricula;
            return true;
        }
        else
        {
            System.out.println("Matricula Invalida!");
            return false;
        }
    }
    public boolean setCpf(String cpf)
    {
        if(cpf.length() > 0)
        {
            this.cpf = cpf;
            return true;
        }
        else
        {
            System.out.println("CPF Invalido!");
            return false;
        }
    }
    
    public void lerDados()
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Digite o nome do Aluno");
        while (!setNome(s.nextLine()));
        System.out.println("Digite a matricula do Aluno");
        while (!setMatricula(s.nextLine()));
        System.out.println("Digite o CPF do Aluno: ");
        while (!setCpf(s.nextLine()));
    }
    
    public void mostrarDados()
    {
        System.out.println(this.nome);
        System.out.println(this.matricula);
        System.out.println(this.cpf);
        //JOptionPane.showMessageDialog(null,"Nome: " + this.nome + "\nMatricula: "+this.matricula +"\nCPF:"+this.cpf, "Resultado", JOptionPane.PLAIN_MESSAGE);
    }
}