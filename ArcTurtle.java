import edu.princeton.cs.algs4.StdDraw;

public class ArcTurtle extends Turtle{

    public ArcTurtle(double x0, double y0, double a0){
            super(x0, y0, a0);
        }

    //Overwrite Draw()
    public void Draw(){
        Arc(0.25, 300, 140);
    }

    //Create an Arc
    public void Arc(double rad, double angle1, double angle2 ){
        StdDraw.arc(0.5, 0.5, rad, angle1, angle2);
    }

}
