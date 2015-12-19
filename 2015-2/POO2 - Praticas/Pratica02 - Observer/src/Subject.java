public interface Subject {
	public void adicionarObservador(Observer o);
	public void removerObservador(Observer o);
	public void notificarObservadores();
	
	public String getValor();
	public void setValor(String s);
}