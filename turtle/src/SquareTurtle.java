import edu.princeton.cs.algs4.StdDraw;

public class SquareTurtle extends Turtle{

    public SquareTurtle(double x0, double y0, double a0){
        super(x0, y0, a0);
    }

    //Overwrite Draw()
    public void Draw(){
        Square(0.25);
        StdDraw.text(0.5, 0.05, "Square");
        show();
    }

    //Create a square in required border lengths
    public void Square(double a){
        StdDraw.square(0.5, 0.5, a);
    }
}
