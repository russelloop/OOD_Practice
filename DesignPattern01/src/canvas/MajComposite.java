package canvas;
import javax.swing.*;
import java.awt.*;
import java.awt.geom.Point2D;

public class MajComposite extends JComponent{

    private static final int DEFAULT_WIDTH = 1600;
    private static final int DEFAULT_HEIGHT = 1000;
    private Frame ParentFrame;
    public Dimension getPreferredSize() {
        return new Dimension(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    }

    public MajComposite(Frame frame){
        Init(frame);
    }

    private void Init(Frame frame){
        RectItem mainRect = new RectItem(new Point2D.Double(200, 350), 600, 300);
        add(mainRect, BorderLayout.CENTER);
        mainRect.setBounds(300, 0, 1400, 1000);
        TextItem heightCoor1 = new TextItem(new Point2D.Double(200, 350), 100, 50, frame);
        add(heightCoor1, BorderLayout.WEST);
        heightCoor1.setBounds(0, 0, 400, 1000);
        mainRect.addObserver(heightCoor1);
    }
}
