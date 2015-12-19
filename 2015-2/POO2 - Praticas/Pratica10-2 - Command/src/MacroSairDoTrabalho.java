import java.util.ArrayList;

public class MacroSairDoTrabalho implements Command {
	ArrayList<Command> commands = new ArrayList<Command>();
	
	public MacroSairDoTrabalho() {}
	
	public void addCommand(Command c)
	{
		this.commands.add(c);
	}
	
	public void execute()
	{
		for(Command c: commands) {
			c.execute();
		}
	}
}
