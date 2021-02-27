using Godot;

public class Enemy : RigidBody2D
{
    [Export] private readonly int score = 100;

    public override void _Ready()
    {
        SetPhysicsProcess(false);

        //Velocity.x = -Speed.x;
    }

    public override void _PhysicsProcess(float delta)
    {
        base._PhysicsProcess(delta);
        //Velocity.x *= IsOnWall() ? -1 : 1;
        //Velocity.y = MoveAndSlide(Velocity, FloorNormal).y;
    }

    public void OnStompArea2DAreaEntered(Area2D area)
    {
        var stompArea = GetNode<Area2D>("StompArea2D");

        if (area.GlobalPosition.y > stompArea.GlobalPosition.y) return;

        Die();
    }

    private void Die()
    {
        PlayerData.Instance.Score += score;
        QueueFree();
    }
}
