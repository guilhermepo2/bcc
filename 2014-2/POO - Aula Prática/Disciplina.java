import java.util.*;
import javax.swing.JOptionPane;

public class Disciplina
{
    int codigo;
    String nome;
    int cargaHoraria;
    Curso curso;
    Professor professor;
    
    Disciplina (Curso curso)
    {
        this.curso = curso;
    }
    
    Disciplina (int codigo, String nome, int cargaHoraria, Curso curso, Professor professor)
    {
        this.codigo = codigo;
        this.nome = nome;
        this.cargaHoraria = cargaHoraria;
        this.curso = curso;
        this.professor = professor;
    }
    
    public boolean setCodigo(int codigo)
    {
        if (codigo > 0)
        {
            this.codigo = codigo;
            return true;
        }
        else
        {
            System.out.println("Codigo Invalido!");
            return false;
        }
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
    public boolean setCargaHoraria(int cargaHoraria)
    {
        if(cargaHoraria > 0)
        {
            this.cargaHoraria = cargaHoraria;
            return true;
        }
        else
        {
            System.out.println("Carga Horaria Invalida!");
            return false;
        }
    }
    
    public void lerDados()
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Digite o codigo da disciplina: ");
        //while(!setCodigo(s.nextInt()));
        while(true)
        {
            try
            {
                setCodigo(s.nextInt());
                System.out.println("OK!");
                break;
            }
            catch(InputMismatchException e)
            {
                System.out.println("Erro: " + e.toString());
                System.out.println("Digite novamente.");
                s.next();
            }
        }
        System.out.println("Digite o nome da disciplina: ");
        while(!setNome(s.nextLine()));
        System.out.print("Digite a carga Horaria da Disciplina: ");
        //while(!setCargaHoraria(s.nextInt()));
        while(true)
        {
            try
            {
                setCargaHoraria(s.nextInt());
                System.out.println("OK!");
                break;
            }
            catch(InputMismatchException e)
            {
                System.out.println("Erro: " + e.toString());
                System.out.println("Digite novamente.");
                s.next();
            }
        }
    }
    
    public void mostrarDados()
    {
        JOptionPane.showMessageDialog(null,"Codigo: "+this.codigo+"\nNome: "+this.nome+"\nCarga Horaria: "+this.cargaHoraria,"Resultado",JOptionPane.PLAIN_MESSAGE);
        System.out.println("Codigo: "+this.codigo);
        System.out.println("Nome: "+this.nome);
        System.out.println("Carga Horaria: "+this.cargaHoraria);
    }
}
