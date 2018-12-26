package canvas;

import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class ProItem extends GraphicItem implements Observable {
    private ArrayList<Observer> observers = new ArrayList<>();
    private ArrayList<Point2D> pS;
    private Rectangle2D rectangle;
    private Line2D line;
    private ComponentFactory factory;
    private int size;

    public ProItem(Point2D startPoint, double width, double height){
        super(startPoint, width, height);
        rectangle = super.getRectangle();
        factory = new ComponentFactory();
        pS = new ArrayList<>();
        addMouseMotionListener(new MouseMotionHandler());
    }

    @Override
    protected void paintComponent(Graphics grap) {
        Update();
        super.paintComponent(grap);
        Graphics2D drawer = (Graphics2D)grap;
        line =(Line2D) factory.makeComponent("line");
        line.setLine(new Point2D.Double(rectangle.getX(), rectangle.getY() + rectangle.getHeight() ),
                new Point2D.Double(rectangle.getX() + rectangle.getWidth() / 2, rectangle.getY()));
        drawer.setColor(Color.blue);
        drawer.draw(line);
        size = pS.size();
        for (Point2D p : pS){
            Ellipse2D e = (Ellipse2D)factory.makeComponent("elli");
            e.setFrame(p.getX() - 5, p.getY() - 5, 10, 10);
            drawer.fill(e);
        }
    }

    @Override
    public void addObserver(Observer observer) {
        observers.add(observer);
    }

    @Override
    public void deleteObserver(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObserver(GraphicItem item, int size) {
        for(Observer o : observers){
            o.update(item, size);
        }
    }

    private void addPoints(Point2D p){
        pS.add(p);
    }

    private void Update(){

        ResultSet rs = null;
        DBConnector connector = new DBConnector();
        String sql = "SELECT * FROM depthTable;";
        connector.Con();
        rs = connector.Execute(sql);

        double x, y;
        try{
            while (rs.next()){
                double x_move;
                double k;
                Point2D p = (Point2D) factory.makeComponent("point");
                y = rectangle.getY() + rectangle.getHeight() - rs.getDouble("depth")/8;
                k = (rectangle.getHeight() * 2)/ rectangle.getWidth();
                x_move = rectangle.getWidth()/2-((y-rectangle.getY())/k);
                x = rectangle.getX() + x_move;
                if (y >= rectangle.getY()){
                    p.setLocation(x, y);
                    addPoints(p);
                }
            }
            connector.Close();
        }catch (SQLException e){
            System.out.println(e.getMessage());
        }
    }

    private class MouseMotionHandler implements MouseMotionListener {
        @Override
        public void mouseDragged(MouseEvent e) {
            pS.clear();
            repaint();
            notifyObserver(ProItem.this, size);
        }

        @Override
        public void mouseMoved(MouseEvent e) {

        }
    }
}
