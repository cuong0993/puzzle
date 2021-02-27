using Godot;

public class RetryButton : Button
{
    public void OnButtonUp()
    {
        PlayerData.Instance.Score = 0;
        GetTree().Paused = false;
        GetTree().ReloadCurrentScene();
    }
}
