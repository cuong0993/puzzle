using Godot;

public class QuitButton : Button
{
    public void OnQuitButtonUp()
    {
        GetTree().Quit();
    }
}
