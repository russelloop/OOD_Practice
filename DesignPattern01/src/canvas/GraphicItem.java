package canvas;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;

public class GraphicItem extends JComponent{

    private Rectangle2D rectangle;
    private Point2D startPoint, leftUpPoint, leftDownPoint, rightUpPoint, rightDownPoint;
    private Ellipse2D leftUpVertex, leftDownVertex, rightUpVertex, rightDownVertex;
    private double width, height;
    private ComponentFactory factory;
    private int stage = 0;
    private int click = 0;
    public ArrayList<Ellipse2D> cS;

    public GraphicItem(){}

    public GraphicItem(Point2D startPoint, double width, double height){
        cS = new ArrayList<>();
        factory = new ComponentFactory();
        this.startPoint = startPoint;
        this.width = width;
        this.height = height;
        rectangle = (Rectangle2D) factory.makeComponent("rect");    //Factory Pattern
        rectangle.setFrame(startPoint.getX(), startPoint.getY(), width, height);
        addMouseListener(new MouseHandler());
        addMouseMotionListener(new MouseMotionHandler());
    }


    public void setMySize(double width, double height ) {
        this.width = width;
        this.height = height;
    }

    public double getMyHeight() {
        return height;
    }

    public double getMyWidth() {
        return width;
    }

    public Point2D getLeftUpPoint(){
        return leftUpPoint;
    }

    public Rectangle2D getRectangle(){
        return rectangle;
    }

    @Override
    protected void paintComponent(Graphics grap) {
        Graphics2D drawer = (Graphics2D) grap;
        initUi();
        drawer.draw(rectangle);
        if(click == 1){
            for(Ellipse2D e : cS){
                drawer.fill(e);
            }
        }
    }

    private void initUi(){

        // create a point
        leftUpPoint = (Point2D) factory.makeComponent("point");
        leftUpPoint.setLocation(rectangle.getX(), rectangle.getY());
        // use the point to create corner
        leftUpVertex = createVertexs(leftUpPoint);
        cS.add(leftUpVertex);
        // repeat
        leftDownPoint = (Point2D) factory.makeComponent("point");
        leftDownPoint.setLocation(leftUpPoint.getX(), leftUpPoint.getY() + rectangle.getHeight());
        //
        leftDownVertex = createVertexs(leftDownPoint);
        cS.add(leftDownVertex);
        //
        rightUpPoint = (Point2D) factory.makeComponent("point");
        rightUpPoint.setLocation(leftUpPoint.getX() + rectangle.getWidth(), leftUpPoint.getY());
        rightUpVertex = createVertexs(rightUpPoint);
        cS.add(rightUpVertex);
        //
        rightDownPoint = (Point2D)factory.makeComponent("point");
        rightDownPoint.setLocation(leftUpPoint.getX() + rectangle.getWidth(), leftUpPoint.getY() + rectangle.getHeight());
        rightDownVertex = createVertexs(rightDownPoint);
        cS.add(rightDownVertex);
    }

    private Ellipse2D createVertexs(Point2D p){
        Ellipse2D e = (Ellipse2D)factory.makeComponent("elli");
        e.setFrame(p.getX() - 5, p.getY() - 5, 10 ,10);
        return e;
    }

    private Ellipse2D findPoints(Point2D p){
        for(Ellipse2D r : cS){
            if(r.contains(p)){
                return r;
            }
        }
        return null;
    }

    private class MouseHandler implements MouseListener {

        @Override
        public void mouseClicked(MouseEvent e) {
            if(rectangle.contains(e.getPoint())){
                if(e.getClickCount() == 1){
                    click = 1;
                    repaint();
                }
            }
            else{
                click = 0;
                repaint();
            }
        }

        @Override
        public void mousePressed(MouseEvent e) {

        }

        @Override
        public void mouseEntered(MouseEvent e) {

        }

        @Override
        public void mouseExited(MouseEvent e) {

        }

        @Override
        public void mouseReleased(MouseEvent e) {

        }
    }


    private class MouseMotionHandler implements MouseMotionListener {

        @Override
        public void mouseMoved(MouseEvent e) {
            if (rectangle.contains(e.getPoint())) {
                stage = 1;
                setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
            } else if (findPoints(e.getPoint()) != null) {
                setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
                if (leftUpVertex.contains(e.getPoint()))
                    stage = 2;
                if (leftDownVertex.contains(e.getPoint()))
                    stage = 4;
                if (rightUpVertex.contains(e.getPoint()))
                    stage = 6;
                if (rightDownVertex.contains(e.getPoint()))
                    stage = 8;
            } else {
                stage = 0;
                setCursor(Cursor.getDefaultCursor());
            }
        }

        @Override
        public void mouseDragged(MouseEvent e) {
            cS.clear();
            switch (stage) {
                case 1: {
                    rectangle.setFrame(e.getX() - width / 2, e.getY() - height / 2, width, height);
                    break;
                }
                case 2: {
                    rectangle.setFrameFromDiagonal(e.getPoint(), rightDownPoint);
                    setMySize(rectangle.getWidth(), rectangle.getHeight());
                    break;
                }
                case 4: {
                    rectangle.setFrameFromDiagonal(e.getPoint(), rightUpPoint);
                    setMySize(rectangle.getWidth(), rectangle.getHeight());
                    break;
                }
                case 6: {
                    rectangle.setFrameFromDiagonal(e.getPoint(), leftDownPoint);
                    setMySize(rectangle.getWidth(), rectangle.getHeight());
                    break;
                }
                case 8: {
                    rectangle.setFrameFromDiagonal(e.getPoint(), leftUpPoint);
                    setMySize(rectangle.getWidth(), rectangle.getHeight());
                    break;
                }
            }
            repaint();
        }
    }

}