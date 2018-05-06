public class TritangleTurtle extends Turtle{
    public TritangleTurtle(double x0, double y0, double a0){
        super(x0, y0, a0);
    }

    //Overwrite Draw()
    public void Draw(){
        Triangle(0.3, 0.4, 0.5);
    }

    //Draw a triangle in required border lengths
    public void Triangle(double a, double b, double c){
        double angleA, angleB, angleC = 0;
        angleA = Math.acos((b*b + c*c - a*a)/(2*b*c))*180/Math.PI;//angle = radian*180/PI
        angleB = Math.acos((a*a + c*c - b*b)/(2*a*c))*180/Math.PI;
        angleC = Math.acos((a*a + b*b - c*c)/(2*a*b))*180/Math.PI;
        goForward(a);
        turnLeft(180 - angleB);
        goForward(c);
        turnLeft(180 - angleA);
        goForward(b);
        turnLeft(180 - angleC);
    }
}
