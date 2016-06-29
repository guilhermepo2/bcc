
package ManagedBeans;

import Beans.EnvolveBean;
import Beans.VendaBean;
import DAO.EnvolveDAO;
import DAO.VendaDAO;
import java.sql.Date;
import java.util.Calendar;
import javax.faces.application.FacesMessage;
import javax.faces.bean.ManagedBean;
import javax.faces.context.FacesContext;

@ManagedBean(name="Finalizar")
public class Finalizar {
    
    public String finalizar()
    {
        VendaDAO vendaDAO = new VendaDAO();
        EnvolveDAO envolveDAO = new EnvolveDAO();
        
        VendaBean venda = new VendaBean();
        int venda_id = vendaDAO.proximoSequencia();
        venda.setVendaId(venda_id);
        venda.setClienteCpf(SessionManager.getInstance().getCliente().getCpf());
        Date data = new Date(Calendar.getInstance().getTime().getTime());
        venda.setDataCompra(data);
        venda.setFrete(1.99);
        
        vendaDAO.adicionar(venda);
        
        EnvolveBean envolve = new EnvolveBean();
        for(int i = 0; i < SessionManager.getInstance().getCarrinho().getTamanho(); i++)
        {
            envolve.setProdutoId(SessionManager.getInstance().getCarrinho().getPosicao(i));
            envolve.setVendaId(venda_id);
            envolveDAO.adicionar(envolve);
        }
        
        SessionManager.getInstance().getCarrinho().limparCarrinho();
        vendaDAO.fecharConexao();
        envolveDAO.fecharConexao();
        FacesContext.getCurrentInstance().addMessage(null, new FacesMessage("Venda efetuada!"));
        
        return "index";
    }
}
