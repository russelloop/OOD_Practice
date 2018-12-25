package canvas;

import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.awt.*;

import java.awt.geom.Rectangle2D;

public class TextItem extends GraphicItem implements Observer{
    private Rectangle2D rectangle;
    private Panel dialog = null;
    String message;
    Font font;
    private Frame ParentFrame;

    public TextItem(Point2D startPoint, double width, double height, Frame frame){
        super(startPoint, width, height);
        ParentFrame = frame;
        message = "Height"; //Data here
        font = new Font("Serif", Font.BOLD, 10);
        this.rectangle = super.getRectangle();
        addMouseListener(new MouseHandler());
    }


    @Override
    protected void paintComponent(Graphics g) {
        int stringMessageX = (int) (rectangle.getX());
        int stringMessageY = (int) (rectangle.getY() + font.getSize());
        super.paintComponent(g);
        Graphics2D graphics2D = (Graphics2D)g;
        graphics2D.setFont(font);
        graphics2D.drawString(message, stringMessageX, stringMessageY);
    }

    public void update(Point2D point) {
        super.conerS.clear();
        rectangle.setFrame(point.getX(), point.getY(), super.getMyWidth(), super.getMyHeight());
        repaint();
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
            if(rectangle.contains(e.getPoint())){
                if(e.getClickCount() >= 2)
                    isShowDialog();
            }
        }


    }

    public void isShowDialog() {
        if (dialog == null)
            dialog = new Panel();

        dialog.setEditor(message);

        // pop up dialog
        if (dialog.showDialog(ParentFrame, "Edit"))
        {
            // if accepted, retrieve user input
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

}
