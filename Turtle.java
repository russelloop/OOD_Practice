import edu.princeton.cs.algs4.StdDraw;  //Enable StdDraw
import java.awt.Color;      //Enable Color
import java.util.ArrayList; //Enable ArrayList
import java.util.Iterator;  //Enable Iterator
public class Turtle {
    private double x, y;     // turtle is at (x, y)
    private double angle;    // facing this many degrees counterclockwise from the x-axis

    // start at (x0, y0), facing a0 degrees counterclockwise from the x-axis
    public Turtle(double x0, double y0, double a0) {
        x = x0;
        y = y0;
        angle = a0;
    }

    // rotate orientation delta degrees counterclockwise
    public void turnLeft(double delta) {
        angle += delta;
    }

    // move forward the given amount, with the pen down
    public void goForward(double step) {
        double oldx = x;
        double oldy = y;
        x += step * Math.cos(Math.toRadians(angle));
        y += step * Math.sin(Math.toRadians(angle));
        StdDraw.line(oldx, oldy, x, y);
    }

    public void Draw(){ }

    // copy to onscreen
    public void show() {
        StdDraw.show();
    }

    // pause t milliseconds
    public void pause(int t) {
        StdDraw.pause(t);
    }

    public void setPenColor(Color color) {
        StdDraw.setPenColor(color);
    }

    public void setPenRadius(double radius) {
        StdDraw.setPenRadius(radius);
    }

    public void setCanvasSize(int width, int height) {
        StdDraw.setCanvasSize(width, height);
    }

    public void setXscale(double min, double max) {
        StdDraw.setXscale(min, max);
    }

    public void setYscale(double min, double max) {
        StdDraw.setYscale(min, max);
    }

    // sample client for testing
    public static void main(String[] args) {
        StdDraw.enableDoubleBuffering();
        StdDraw.setCanvasSize(500, 500); //set size of canvas
        ArrayList<Turtle> List = new ArrayList<Turtle>();
        ArrayList NameList = new ArrayList();
        RectangleTurtle RecTurtle = new RectangleTurtle(0, 0, 0);
        SquareTurtle SquTurtle = new SquareTurtle(0, 0, 0);
        CircleTurtle CirTurtle = new CircleTurtle(0, 0, 0);
        ArcTurtle ArcTurtle = new ArcTurtle(0, 0, 0);
        SpiralTurtle SpiTurtle = new SpiralTurtle(0.5, 0.5, 0);
        //join list
        List.add(RecTurtle);
        NameList.add("Rectangle");
        List.add(SquTurtle);
        NameList.add("Square");
        List.add(CirTurtle);
        NameList.add("Circle");
        List.add(ArcTurtle);
        NameList.add("ArcTurtle");
        List.add(SpiTurtle);
        NameList.add("Spiral");
        //Circulatory output
        for(int i = 0; i < List.size(); i++){
            Turtle turtle = List.get(i);
            turtle.Draw();
            //mark name
            StdDraw.text(0.5, 0.2, (String) NameList.get(i));
            turtle.show();
            StdDraw.pause(1000);
            StdDraw.clear();
        }
    }
}