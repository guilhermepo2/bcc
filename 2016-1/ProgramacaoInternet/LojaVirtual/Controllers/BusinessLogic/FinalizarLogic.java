package BusinessLogic;

import Beans.ClienteBean;
import Beans.EnvolveBean;
import Beans.VendaBean;
import DAO.EnvolveDAO;
import DAO.VendaDAO;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Date;
import java.util.Calendar;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet(name = "FinalizarLogic", urlPatterns = {"/cliente/FinalizarLogic"})
public class FinalizarLogic extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet FinalizarLogic</title>");            
            out.println("</head>");
            out.println("<body>");
            HttpSession sessao = request.getSession();
            String usuarioSessao = (String)sessao.getAttribute("usuario");
            Carrinho carrinho = (Carrinho)sessao.getAttribute("carrinho");
            ClienteBean cliente = (ClienteBean)sessao.getAttribute("cliente");
            
            if(usuarioSessao == null || carrinho == null || cliente == null)
            {
                out.println("<h1>Erro!</h1>");
                sessao.invalidate();
                out.println("<a href='../index.html'><< Voltar</a>");
            }
            else {
                out.println("<h1>Finalizando a Compra</h1>");
                // agora tem que criar a venda e todos os envolve maluco
                VendaDAO vendaDAO = new VendaDAO();
                EnvolveDAO envolveDAO = new EnvolveDAO();
                
                // criando e inserindo venda no banco
                VendaBean venda = new VendaBean();
                int venda_id = vendaDAO.proximoSequencia();
                venda.setVendaId(venda_id);
                venda.setClienteCpf(cliente.getCpf());
                Date data = new Date(Calendar.getInstance().getTime().getTime());
                venda.setDataCompra(data);
                venda.setFrete(1.99);
                
                vendaDAO.adicionar(venda);
                
                // criando envolve
                EnvolveBean envolve = new EnvolveBean();
                for(int i = 0; i < carrinho.getTamanho(); i++)
                {
                    envolve.setProdutoId(carrinho.getPosicao(i));
                    envolve.setVendaId(venda_id);
                    envolveDAO.adicionar(envolve);
                }
                
                carrinho.limparCarrinho();
                sessao.setAttribute("carrinho", carrinho);
                vendaDAO.fecharConexao();
                envolveDAO.fecharConexao();
                
                out.println("<h2>Venda Finalizada.</h2>");
                out.println("<a href='index.jsp'> << Voltar</a>");
            }
            
            out.println("</body>");
            out.println("</html>");
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
