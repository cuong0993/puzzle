using Godot;

public class Portal2D : Area2D
{
#pragma warning disable 0649
    [Export] private PackedScene nextScene;
#pragma warning restore 0649
    public void OnBodyEntered(PhysicsBody2D body)
    {
        Teleport();
    }

    public override string _GetConfigurationWarning()
    {
        return nextScene == null ? "The property Next Level can't be empty" : "";
    }

    private async void Teleport()
    {
        GetTree().Paused = true;
        var animPlayer = GetNode<AnimationPlayer>("AnimationPlayer");
        animPlayer.Play("fade_out");
        await ToSignal(animPlayer, "animation_finished");
        GetTree().Paused = false;
        GetTree().ChangeSceneTo(nextScene);
    }
}
