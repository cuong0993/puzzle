using Godot;

public class Player : Actor
{
    [Export] private readonly float stompImpulse = 600.0F;

    public void OnStompDetectorAreaEntered(Area2D area)
    {
        Velocity = CalculateStompVelocity(Velocity, stompImpulse);
    }

    public void OnEnemyDetectorBodyEntered(PhysicsBody2D body)
    {
        Die();
    }

    public override void _PhysicsProcess(float delta)
    {
        base._PhysicsProcess(delta);
        var isJumpInterrupted = Input.IsActionJustReleased("jump") && Velocity.y < 0.0F;

        var direction = GetDirection();
        Velocity = CalculateMoveVelocity(Velocity, direction, Speed, isJumpInterrupted);

        var snap = direction.y == 0.0 ? 60 * Vector2.Down : Vector2.Zero;
        Velocity = MoveAndSlide(Velocity, FloorNormal, true);
    }

    private Vector2 GetDirection()
    {
        return new Vector2(
            Input.GetActionStrength("move_right") - Input.GetActionStrength("move_left"),
            IsOnFloor() && Input.IsActionJustPressed("jump") ? -Input.GetActionStrength("jump") : 0.0F);
    }

    private Vector2 CalculateMoveVelocity(Vector2 linearVelocity, Vector2 direction, Vector2 speed,
        bool isJumpInterrupted)
    {
        var velocity = linearVelocity;
        velocity.x = speed.x * direction.x;

        if (direction.y != 0.0) velocity.y = speed.y * direction.y;

        if (isJumpInterrupted) velocity.y = 0.0F;

        return velocity;
    }

    private Vector2 CalculateStompVelocity(Vector2 linearVelocity, float stompImpulse)
    {
        var stompJump = Input.IsActionJustPressed("jump") ? -Speed.y : -stompImpulse;

        return new Vector2(linearVelocity.x, stompJump);
    }

    private void Die()
    {
        PlayerData.Instance.Deaths += 1;
        QueueFree();
    }
}
