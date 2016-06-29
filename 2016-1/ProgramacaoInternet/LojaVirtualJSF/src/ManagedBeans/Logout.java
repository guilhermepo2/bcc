package ManagedBeans;

import javax.faces.bean.ManagedBean;

@ManagedBean(name="Logout")
public class Logout {
    
    public String fazerLogout()
    {
        SessionManager.getInstance().limparSessao();
        return "/index";
    }
}
