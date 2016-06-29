package Beans;

public class ClienteBean {
    private String cpf;
    private String nome;
    private String endereco;
    private String usuario;
    private String senha;
    
    public void setCpf(String cpf) { this.cpf = cpf; }
    public void setNome(String nome) { this.nome = nome; }
    public void setEndereco(String endereco) { this.endereco = endereco; }
    public void setUsuario(String usuario) { this.usuario = usuario; }
    public void setSenha(String senha) { this.senha = senha; }
    
    public String getCpf() { return this.cpf; }
    public String getNome() { return this.nome; }
    public String getEndereco() { return this.endereco; }
    public String getUsuario() { return this.usuario; }
    public String getSenha() { return this.senha; }
}
