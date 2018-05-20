public class TritangleTurtle extends Turtle{
    public double edge_a;
    public double edge_b;
    public double edge_c;
    public double angle_a;
    public double angle_b;
    public double angle_c;
    public TritangleTurtle(double e_c, double a_a, double a_b, double x0, double y0, double a0){
        super(x0, y0, a0);
        edge_c = e_c;
        angle_a = a_a;
        angle_b = a_b;
    }

    //Overwrite Draw()
    public void Draw(){
        Triangle();
        show();
    }

    //Draw a triangle in required border lengths
    public void Triangle(){
          angle_c = 180 - angle_a - angle_b;
          edge_a = edge_c*Math.sin(angle_a*Math.PI/180)/Math.sin(angle_c*Math.PI/180);
          edge_b = edge_c*Math.sin(angle_b*Math.PI/180)/Math.sin(angle_c*Math.PI/180);
          goForward(edge_c);
          turnLeft(180  - angle_b);
          goForward(edge_a);
          turnLeft(180 - angle_c);
          goForward(edge_b);
          turnLeft(180 - angle_a);
//        double angleA, angleB, angleC = 0;
//        angleA = Math.acos((b*b + c*c - a*a)/(2*b*c))*180/Math.PI;//angle = radian*180/PI
//        angleB = Math.acos((a*a + c*c - b*b)/(2*a*c))*180/Math.PI;
//        angleC = Math.acos((a*a + b*b - c*c)/(2*a*b))*180/Math.PI;
//        goForward(a);
//        turnLeft(180 - angleB);
//        goForward(c);
//        turnLeft(180 - angleA);
//        goForward(b);
//        turnLeft(180 - angleC);
//        show();
    }
}
