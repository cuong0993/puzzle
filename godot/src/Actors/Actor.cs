using Godot;

public abstract class Actor : KinematicBody2D
{
    [Export] private readonly float gravity = 3500.0F;
    protected Vector2 FloorNormal = Vector2.Up;

    [Export] protected Vector2 Speed = new Vector2(400.0F, 500.0F);

    protected Vector2 Velocity = Vector2.Zero;

    public override void _PhysicsProcess(float delta)
    {
        Velocity.y += gravity * delta;
    }
}
