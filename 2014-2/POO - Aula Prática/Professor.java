import java.util.Scanner;
import javax.swing.JOptionPane;

public class Professor extends Funcionario implements Pesquisador
{
    private String titulacao;
    private String areaDePesquisa;
    private double salarioBase, valorDedicacaoExclusiva, retribTitulacao;
    
    public String getNome()
    {
        return "teste";
    }
    public String getTipo()
    {
        return "teste";
    }
    
    public void SetSalario(double salario)
    {
        this.salarioBase = salario;
    }
    
    public void SetValorDedicacaoExclusiva(double dedic)
    {
        this.valorDedicacaoExclusiva = dedic;
    }
    
    public void SetRetribTitulacao(double retrib)
    {
        this.retribTitulacao = retrib;
    }
    
    public boolean setTitulacao(String titulacao)
    {
        if(titulacao.length() > 0)
        {
            this.titulacao = titulacao;
            return true;
        }
        else
        {
            System.out.println("Titulacao Invalida");
            return false;
        }
        
    }
    
    public boolean setAreaDePesquisa(String areaDePesquisa)
    {
        if(areaDePesquisa.length() > 0)
        {
            this.areaDePesquisa = areaDePesquisa;
            return true;
        }
        else
        {
            System.out.println("Area de Pesquisa invalida!");
            return false;
        }
    }
    
    public void lerDados()
    {
        super.lerDados();
        Scanner s = new Scanner(System.in);
        System.out.println("Digite a Titulacao do professor: ");
        while (!setTitulacao(s.nextLine()));
        System.out.println("Digite a Area de Pesquisa do Professor: ");
        while (!setAreaDePesquisa(s.nextLine()));
    }
    
    public void mostrarDados()
    {
        super.mostrarDados();
        JOptionPane.showMessageDialog(null,"Titulacao: "+this.titulacao+"\nArea de Pesquisa: "+this.areaDePesquisa,"Resultado",JOptionPane.PLAIN_MESSAGE);
    }
    
    public double CalcSalario()
    {
        return (salarioBase + valorDedicacaoExclusiva + retribTitulacao);
    }
}

