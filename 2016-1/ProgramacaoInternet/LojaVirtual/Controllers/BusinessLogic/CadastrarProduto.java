package BusinessLogic;

import Beans.ProdutoBean;
import DAO.ProdutoDAO;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class CadastrarProduto extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            // Processando a Request e Inserindo o Produto no Banco de Dados
            // Criando o Bean
            ProdutoBean produto = new ProdutoBean();
            produto.setId(Integer.parseInt(request.getParameter("id")));
            produto.setNome(request.getParameter("nome"));
            produto.setDescricao(request.getParameter("descricao"));
            produto.setQuantidade(Integer.parseInt(request.getParameter("quantidade")));
            produto.setValor(Double.parseDouble(request.getParameter("valor")));
            //Adicionando no Banco
            ProdutoDAO produtoDAO = new ProdutoDAO();
            boolean ok = produtoDAO.adicionar(produto);
            produtoDAO.fecharConexao();
            
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Cadastrar Produto</title>");   
            out.println("</head>");
            out.println("<body>");
            //out.println("<h1>Servlet CadastrarCliente at " + request.getContextPath() + "</h1>");
            if(ok) {
                out.println("<p>Produto Cadastrado.</p>");
            } else {
                out.println("<p>Produto nao pode ser cadastrado.</p>");
            }
            out.println("<a href='index.jsp'><< Voltar</a>");
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
