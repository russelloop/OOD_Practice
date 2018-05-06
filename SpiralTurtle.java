public class SpiralTurtle extends Turtle{
    public SpiralTurtle(double x0, double y0, double a0){
        super(x0, y0, a0);
    }

    //Overwrite Draw()
    public void Draw(){
        Spiral();
    }

    //Create a Spiral
    public void Spiral(){
        int i = 0;
        float turn = 1;
        double step = 0.0001;
        for(; i < 1000; i++, step += 0.000005){
            goForward(step);
            turnLeft(turn);
        }
    }
}
