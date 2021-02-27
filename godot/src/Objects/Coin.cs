using Godot;

public class Coin : RigidBody2D
{
    [Export] private readonly int score = 100;

    public void OnBodyEntered(PhysicsBody2D body)
    {
        Picked();
    }

    private void Picked()
    {
        PlayerData.Instance.Score += score;
        GetNode<AnimationPlayer>("AnimationPlayer").Play("picked");
    }
}
