import edu.princeton.cs.algs4.StdDraw;

public class RectangleTurtle extends Turtle {
    public RectangleTurtle(double x0, double y0, double a0){
        super(x0, y0, a0);
    }

    //Overwrite Draw()
    public void Draw(){
        Rectangle(0.4, 0.2);
        StdDraw.text(0.5, 0.05, "Rectangle");
        show();
    }

    //Create a rectangle in required border lengths
    public void Rectangle(double a, double b){
//        goForward(a);
//        turnLeft(90);
//        goForward(b);
//        turnLeft(90);
//        goForward(a);
//        turnLeft(90);
//        goForward(b);
//        turnLeft(90);
        StdDraw.rectangle(0.5, 0.5, a, b);
    }
}
