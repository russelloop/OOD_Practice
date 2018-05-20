import edu.princeton.cs.algs4.StdDraw;

public class SquareSpiral extends Turtle{
    public SquareSpiral(double x0, double y0, double a0){
        super(x0, y0, a0);
    }

    public void Draw(){
        SquareSpiral(0.01);
        StdDraw.text(0.5, 0.05, "SquareSpiral");
        show();
    }

    public void SquareSpiral(double a){
        int i = 0;
        while(i < 45) {
            goForward(a);
            turnLeft(90);
            a += 0.01;
            i++;
        }
    }
}
