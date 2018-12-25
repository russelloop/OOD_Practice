package canvas;
import javax.swing.*;
import java.awt.*;
import java.awt.geom.Rectangle2D;

public abstract class ABComponentFactory {
    public abstract Object makeComponent(String str);   //Abstract Factory Method
}
