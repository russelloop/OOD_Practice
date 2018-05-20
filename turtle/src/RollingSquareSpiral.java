import edu.princeton.cs.algs4.StdDraw;

import java.awt.*;
import java.util.ArrayList;

public class RollingSquareSpiral extends SquareSpiral{
    public RollingSquareSpiral(double x0, double y0, double a0){
        super(x0, y0, a0);
    }

    public void Draw(){
        SquareSpiral(0.01);
        setPenColor(Color.BLACK);
        StdDraw.text(0.5, 0.05, "Rolling SquareSpiral (Colorful)");
        show();
    }

    public void SquareSpiral(double a){
        int p, q;
        int r = 0;
        ArrayList<Color> CList = new ArrayList<Color> ();
        CList.add(Color.RED);
        CList.add(Color.YELLOW);
        CList.add(Color.BLUE);
        CList.add(Color.GREEN);
        for(p = 0; p < 50; p++){
            for(q = 0; q < 6; q++) {
                goForward(a);
                turnLeft(90);
                a += 0.002;
                Color color = CList.get(r);
                setPenColor(color);
                if(r < 3)
                    r++;
                else
                    r = 0;
            }
            turnLeft(362);
        }
    }
}
