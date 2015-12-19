public class Tecnicos extends Funcionario
{
    private double salarioBase, auxTransporte, auxAlimentacao;
    private static double valorHoraExtra;
    
    public static void setValorHoraExtra(double valor)
    {
        valorHoraExtra = valor;
    }
    
    public static double getValorHoraExtra()
    {
        return valorHoraExtra;
    }
    
    public double CalcSalario(double quantHoras, double valorHora)
    {
        return (CalcSalario() + (quantHoras * valorHora));
    }
    
    public double CalcSalario()
    {
        return (salarioBase + auxTransporte + auxAlimentacao);
    }
}