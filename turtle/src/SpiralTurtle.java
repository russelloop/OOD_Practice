import edu.princeton.cs.algs4.StdDraw;

public class SpiralTurtle extends Turtle{
    public SpiralTurtle(double x0, double y0, double a0){
        super(x0, y0, a0);
    }

    //Overwrite Draw()
    public void Draw(){
        Spiral();
        StdDraw.text(0.5, 0.05, "Spiral");
        show();
    }

    //Create a Spiral
    public void Spiral(){
        int i;
        float turn = 1;
        double step = 0.0001;
        for(i = 0; i < 1000; i++, step += 0.000005){
            goForward(step);
            turnLeft(turn);
        }
    }
}
