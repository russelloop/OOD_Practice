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

        ProItem proitem = new ProItem(new Point2D.Double(0, 350), 400, 500);
        add(proitem, BorderLayout.CENTER);
        proitem.setBounds(300, 0, 700, 1000);

        CoordinateItem heightCoor1 = new CoordinateItem(new Point2D.Double(100, 350), 100, 50, frame);
        add(heightCoor1, BorderLayout.WEST);
        heightCoor1.setBounds(0, 0, 300, 1000);
        proitem.addObserver(heightCoor1);

        legendItem legend = new legendItem(new Point2D.Double(0, 350), 300, 300);
        add(legend);
        legend.setBounds(1000, 0, 600, 1000);
        proitem.addObserver(legend);
    }
}
