package canvas;

import java.awt.*;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;

public class legendItem extends GraphicItem implements Observer{
    private Rectangle2D frame;
    private Point2D start;
    private int d, ynum;
    private double mywidth, myheight;
    private ComponentFactory factory;
    private ArrayList<Rectangle2D> rectangle2DS;
    public legendItem(Point2D startPoint, double width, double height){
        super(startPoint, width, height);
        rectangle2DS = new ArrayList<>();
        factory = new ComponentFactory();

    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D drawer = (Graphics2D)g;
        g.setColor(Color.black);
        for(Rectangle2D r : rectangle2DS){
            drawer.fill(r);
        }
    }

    private void initRect(int count) {
        d = 100;
        ynum = 0;
        frame = super.getRectangle();
        start = (Point2D) factory.makeComponent("point");
        start.setLocation(frame.getX() + 20, frame.getY() + d);
        for (int n = 0; n < count; n++) {
            Rectangle2D rect = (Rectangle2D) factory.makeComponent("rect");
            rect.setFrame(start.getX(), start.getY(), 10, 10);
            rectangle2DS.add(rect);
            d += 20;
            start.setLocation(frame.getX() + 20, frame.getY() + d);
        }
    }

    @Override
    public void update(GraphicItem item, int size) {
        rectangle2DS.clear();
        initRect(size/2);
        repaint();
    }
}

