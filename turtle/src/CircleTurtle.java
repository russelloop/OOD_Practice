import edu.princeton.cs.algs4.StdDraw;

public class CircleTurtle extends Turtle{
    public CircleTurtle(double x0, double y0, double a0){
        super(x0, y0, a0);
    }

    //Overwrite Draw()
    public void Draw(){
        CircleTurtle(0.25);
        StdDraw.text(0.5, 0.05, "Circle");
        show();
        }

    //Create a Circle in required radius
    public void CircleTurtle(double rad){
//        int i = 0;
//        int sides_num = 360;
//        int exterior_angles = 360;
//        while(i < sides_num) {
//            goForward(rad*2*Math.PI/exterior_angles);
//            turnLeft(1);
//            i++;
//      }
        StdDraw.circle(0.5, 0.5, rad);
    }

}
