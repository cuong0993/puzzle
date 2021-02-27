using Godot;

public class SceneChangeButton : Button
{
    public void OnSceneChangeButtonUp()
    {
        GetTree().ChangeScene("res://src/Levels/Level01.tscn");
    }
}
