package canvas;

import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.awt.*;
import java.awt.geom.Rectangle2D;

public class CoordinateItem extends GraphicItem implements Observer{
    private Rectangle2D rectangle, rectangleUp, rectangleDown;
    private Panel dialog = null;
    String message;
    Font font;
    private Frame ParentFrame;
    private ComponentFactory factory;
    private double width1, height1;
    private int supportheight;

    public CoordinateItem(Point2D startPoint, double width, double height, Frame frame){
        super(startPoint, width, height);
        factory = new ComponentFactory();
        ParentFrame = frame;
        message = " ";
        font = new Font("Serif", Font.BOLD, 20);
        this.rectangle = super.getRectangle();
        width1 = 100;
        height1 = font.getSize() + 10;
        rectangleUp = (Rectangle2D) factory.makeComponent("rect");
        rectangleUp.setFrame(0, 0, width1, height1);
        rectangleDown = (Rectangle2D) factory.makeComponent("rect");
        rectangleDown.setFrame(0, 0, width1, height1);
        addMouseListener(new MouseHandler());
    }


    @Override
    protected void paintComponent(Graphics g) {
        int stringMessageX = (int) (rectangleUp.getX());
        int stringMessageY = (int) (rectangleUp.getY() + font.getSize());
        Graphics2D drawer = (Graphics2D)g;
        drawer.draw(rectangleUp);
        drawer.setFont(font);
        drawer.drawString(message, stringMessageX, stringMessageY);
        stringMessageX = (int) (rectangleDown.getX());
        stringMessageY = (int) (rectangleDown.getY() + font.getSize());
        drawer.draw(rectangleDown);
        drawer.setFont(font);
        drawer.drawString("    bottom", stringMessageX, stringMessageY);
    }

    public void update(GraphicItem item, int size) {
        super.cS.clear();
        rectangleUp.setFrame(item.getRectangle().getX(), item.getRectangle().getY(), width1, height1);
        rectangleDown.setFrame(item.getRectangle().getX(), item.getRectangle().getY() + item.getRectangle().getHeight(), width1, height1);
        supportheight = 4000 - (int)item.getRectangle().getHeight() * 8;
        if(supportheight < 0){
            message = "     above";
        }
        else
            message = "   " + supportheight + " m";
        repaint();
    }

    public void isShowDialog() {
        if (dialog == null)
            dialog = new Panel();

        dialog.setEditor(message);

        if (dialog.showDialog(ParentFrame, "Edit"))
        {
            Editor editor = dialog.getEditor();
            message = editor.getContent();
            if (editor.getFontStyle().equals("PLAIN"))
                font = new Font("Serif", Font.PLAIN, editor.getFontSize());
            else if (editor.getFontStyle().equals("BOLD"))
                font = new Font("Serif", Font.BOLD, editor.getFontSize());
            else if (editor.getFontStyle().equals("ITALIC"))
                font = new Font("Serif", Font.ITALIC, editor.getFontSize());
            else if (editor.getFontStyle().equals("CENTER_BASELINE"))
                font = new Font("Serif", Font.CENTER_BASELINE, editor.getFontSize());
            repaint();
        }
    }

    private class MouseHandler implements MouseListener {
        @Override
        public void mouseReleased(MouseEvent e) {

        }

        @Override
        public void mouseExited(MouseEvent e) {

        }

        @Override
        public void mouseEntered(MouseEvent e) {

        }

        @Override
        public void mousePressed(MouseEvent e) {

        }

        @Override
        public void mouseClicked(MouseEvent e) {
            if(rectangleUp.contains(e.getPoint()) || rectangleDown.contains(e.getPoint())){
                if(e.getClickCount() >= 2)
                    isShowDialog();
            }
        }


    }

}
