package Beans;

import java.sql.Date;

public class VendaBean {
    private int vendaId;
    private String clienteCpf;
    private Date dataCompra;
    private double frete;
    
    public void setVendaId(int vendaId) { this.vendaId = vendaId; }
    public void setClienteCpf(String clienteCpf) { this.clienteCpf = clienteCpf; }
    public void setDataCompra(Date dataCompra) { this.dataCompra = dataCompra; }
    public void setFrete(double frete) { this.frete = frete; }
    
    public int getVendaId() { return this.vendaId; }
    public String getClienteCpf() { return this.clienteCpf; }
    public Date getDataCompra() { return this.dataCompra; }
    public double getFrete() { return this.frete; }
}
