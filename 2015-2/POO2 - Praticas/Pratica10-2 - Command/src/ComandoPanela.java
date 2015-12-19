public class ComandoPanela implements Command {
	PanelaEletrica panela;
	
	ComandoPanela(PanelaEletrica panela) {
		this.panela = panela;
	}
	
	public void execute()
	{
		panela.ligarPanelaEletrica();
	}
}
