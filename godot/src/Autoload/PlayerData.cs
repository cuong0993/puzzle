using Godot;

public class PlayerData : Node
{
    [Signal]
    public delegate void Died();

    [Signal]
    public delegate void Reset();

    [Signal]
    public delegate void Updated();

    private int deaths;

    private int score;

    private PlayerData()
    {
        Instance = this;
    }

    public static PlayerData Instance { get; private set; }

    public int Score
    {
        get => score;
        set
        {
            EmitSignal(nameof(Updated));
            score = value;
        }
    }

    public int Deaths
    {
        get => deaths;
        set
        {
            EmitSignal(nameof(Died));
            deaths = value;
        }
    }
}
