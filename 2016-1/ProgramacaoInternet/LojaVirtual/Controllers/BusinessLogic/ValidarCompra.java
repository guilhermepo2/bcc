/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package BusinessLogic;

import Beans.ClienteBean;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 *
 * @author oliveira
 */
@WebServlet(name = "ValidarCompra", urlPatterns = {"/cliente/ValidarCompra"})
public class ValidarCompra extends HttpServlet {

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
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Validar Compra</title>");            
            out.println("</head>");
            out.println("<body>");
            HttpSession sessao = request.getSession();
            String usuarioSessao = (String)sessao.getAttribute("usuario");
            ClienteBean cliente = (ClienteBean)sessao.getAttribute("cliente");
            if(usuarioSessao == null || cliente == null)
            {
                out.println("<h1>Erro</h1>");
                sessao.invalidate();
                out.println("<a href='../index.html'><< Voltar</a>");
            }
            else
            {
                out.println("<h1>Finalizar Compra</h1>");
                out.println("<p>Entre com seus dados:</p>");
                out.println("<form action='FinalizarLogic' method='POST'>");
                out.println("<table>");
                out.println("<tr>");
                out.println("<td>cpf: </td><td><input type='text' value='"+cliente.getCpf()+"'></td>");
                out.println("</tr>");
                out.println("<tr>");
                out.println("<td>nome: </td><td><input type='text' value='"+cliente.getNome()+"'></td>");
                out.println("</tr>");
                out.println("<tr>");
                out.println("<td>endereco: </td><td><input type='text' value='"+cliente.getEndereco()+"'></td>");
                out.println("</tr>");
                out.println("<tr>");
                out.println("<td>usuario: </td><td><input type='text' value='"+cliente.getUsuario()+"'></td>");
                out.println("</tr>");
                out.println("<tr>");
                out.println("<td>senha: </td><td><input type='password' value='"+cliente.getSenha()+"'></td>");
                out.println("</tr>");
                out.println("</table>");
                out.println("<input type='submit' value='Enviar'> <input type='reset' value='limpar'>");
                out.println("</form>");
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
