import java.awt.Color;      //Enable Color
import edu.princeton.cs.algs4.StdDraw;
import java.util.ArrayList; //Enable ArrayList

public class SpiralCircle extends Turtle{
    public SpiralCircle(double x0,double y0,double a0){
        super(x0, y0, a0);
    }

    public void Draw(){
        SpiCir(0.5, 0.5, 0.005);
        setPenColor(Color.BLACK);
        StdDraw.text(0.5, 0.05, "4 CircleSpiral (Colorful)");
        show();
    }

    public void SpiCir(double x, double y, double rad){
        int p, q;
        ArrayList<Color>  ColorList = new ArrayList<Color> ();
        ColorList.add(Color.RED);
        ColorList.add(Color.YELLOW);
        ColorList.add(Color.BLUE);
        ColorList.add(Color.GREEN);
        for(q = 0; q < 4; q++) {
            Color color = ColorList.get(q);
            setPenColor(color);
            for (p = 0; p < 30; p++) {
                int i = 0;
                int sides_num = 360;
                int exterior_angles = 360;
                while (i < sides_num) {
                    goForward(rad * 2 * Math.PI / exterior_angles);
                    turnLeft(2);
                    i++;
                }
                turnLeft(3);
                rad += 0.013;
            }
            rad = 0.005;
        }
    }
}
