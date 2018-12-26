package canvas;
import java.awt.geom.Point2D;
public interface Observer {
    public void update(GraphicItem item, int size);
}
