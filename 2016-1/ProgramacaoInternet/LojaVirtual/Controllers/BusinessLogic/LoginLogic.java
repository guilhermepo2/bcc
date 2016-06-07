package BusinessLogic;

import Beans.ClienteBean;
import DAO.ClienteDAO;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet(name = "LoginLogic", urlPatterns = {"/LoginLogic"})
public class LoginLogic extends HttpServlet {
    
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            
            // vai verificar se o usuario existe ou se é admin
            // cria a sessão correspondente com o nome de usuario da pessoa
            // cria também um carrinho e coloca na sessão
            String usuario = request.getParameter("user");
            String senha = request.getParameter("pass");
            
            //pegando a sessao para verificar se ja nao existe uma
            HttpSession sessao = request.getSession();
            String usuarioSessao = (String)sessao.getAttribute("usuario");
            Carrinho carrinho = new Carrinho();
            
            if(usuarioSessao == null)
            {
                // Verificando se entra na opcao de admin
                if(usuario.equals("admin") && senha.equals("admin"))
                {
                    // cria sessao de admin e redireciona
                    sessao.setAttribute("usuario", "admin");
                    response.sendRedirect("admin/");
                }
                else {
                    sessao.setAttribute("usuario", usuario);
                    //Carrinho carrinho = new Carrinho();
                    sessao.setAttribute("carrinho", carrinho);
                    if(carrinho == null)
                    {
                        System.out.println("Login Logic: Carrinho null.");
                    }
                    ClienteDAO clienteDAO = new ClienteDAO();
                    ResultSet usuarioBD = clienteDAO.consultarPorUsuarioESenha(usuario, senha);
                    try {
                        boolean ok = usuarioBD.next();
                        if(ok) {
                            ClienteBean cliente = new ClienteBean();
                            cliente.setCpf(usuarioBD.getString("cpf"));
                            cliente.setNome(usuarioBD.getString("nome"));
                            cliente.setEndereco(usuarioBD.getString("endereco"));
                            cliente.setUsuario(usuarioBD.getString("usuario"));
                            cliente.setSenha(usuarioBD.getString("senha"));
                            
                            sessao.setAttribute("cliente", cliente);
                            response.sendRedirect("cliente/");
                        } else {
                            out.println("Usuario nao existe.");
                        }
                    } catch(SQLException e) {
                        out.println("houve um erro.");
                    }
                }
            }
            else {
                out.println("Voce ja esta logado! Usuario: "+usuarioSessao+"<br/>");
                if(usuarioSessao.equals("admin")) 
                {
                    response.sendRedirect("admin/");
                }
                else {
                    response.sendRedirect("cliente/");
                }
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
