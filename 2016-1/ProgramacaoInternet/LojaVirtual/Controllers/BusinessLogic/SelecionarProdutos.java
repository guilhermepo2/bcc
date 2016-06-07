package BusinessLogic;

import DAO.ProdutoDAO;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class SelecionarProdutos extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
           
            // verificando se a sessao existe
            HttpSession sessao = request.getSession();
            String usuarioSessao = (String)sessao.getAttribute("usuario");
            
            if(usuarioSessao == null)
            {
                out.println("Usuario Sessao null!<br />");
                //response.sendRedirect("/cliente");
            }
            // pega o carrinho
            Carrinho carrinho = (Carrinho)sessao.getAttribute("carrinho");
            if(carrinho == null)
            {
                out.println("Erro na sessao! <br />");
                sessao.invalidate();
                out.println("<a href='../index.html'><< Voltar</a>");
            }
            else {
                // verificando se existe o item escolhido
                ProdutoDAO produtoDAO = new ProdutoDAO();
                ResultSet produto = produtoDAO.consultarPorId(Integer.parseInt(request.getParameter("produto_id")));

                try {
                    boolean ok = produto.next();
                    if(ok) { // produto existe
                        out.println("ok!");
                         // coloca o item desejado no carrinho
                        carrinho.adicionarItem(Integer.parseInt(request.getParameter("produto_id")));
                        // salva o carrinho novamente na sessao
                        sessao.setAttribute("carrinho", carrinho);
                        // item adicionado, agora deve-se redirecionar para a parte de cliente
                    }
                } catch (SQLException ex) {
                    out.println(ex.toString());
                }
                response.sendRedirect("selecionarProdutos.jsp");
            }
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
