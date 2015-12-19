import java.util.*;
import javax.swing.JOptionPane;

public abstract class Funcionario extends Pessoa
{
    private String endereco;
    private String telefone;
    private String ctps;
    private double salario;
    private static double pisoSalarial;
    
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
    
    public boolean setEndereco(String endereco)
    {
        if(endereco.length() > 0)
        {
            this.endereco = endereco;
            return true;
        }
        else
        {
            System.out.print("Endereco Invalido!");
            return false;
        }
    }
    
    public boolean setTelefone(String telefone)
    {
        if(telefone.length() > 0)
        {
            this.telefone = telefone;
            return true;
        }
        else
        {
            System.out.println("Telefone invalido!");
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
    
    public boolean setCtps(String ctps)
    {
        if(ctps.length() > 0)
        {
            this.ctps = ctps;
            return true;
        }
        else
        {
            System.out.println("CTPS Invalido!");
            return false;
        }
    }
    
    public boolean setSalario(double salario)
    {
        if (salario > 0)
        {
            this.salario = salario;
            return true;
        }
        else
        {
            System.out.println("Salario Invalido!");
            return false;
        }
    }
    
    public void lerDados()
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Digite o nome do funcionario: ");
        while (!setNome(s.nextLine()));
        System.out.println("Digite o endereco do funcionario: ");
        while (!setEndereco(s.nextLine()));
        System.out.println("Digite o telefone do funcionario: ");
        while (!setTelefone(s.nextLine()));
        System.out.println("Digite o CPF do funcionario: ");
        while (!setCpf(s.nextLine()));
        System.out.println("Digite o CTPS do funcionario: ");
        while (!setCtps(s.nextLine()));
        System.out.println("Digite o salario do funcionario: ");
        //while (!setSalario(s.nextDouble()));
        while(true)
        {
            try 
            {
                setSalario(s.nextDouble());
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
        System.out.println("Nome: " + this.nome);
        System.out.println("Endereco: " + this.endereco);
        System.out.println("Telefone: " + this.telefone);
        System.out.println("CPF: " + this.cpf);
        System.out.println("CTPS: " + this.ctps);
        System.out.println("Salario: " + this.salario);
    }
    
    public abstract double CalcSalario();
}