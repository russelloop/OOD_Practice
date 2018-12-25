package canvas;
import java.awt.geom.Point2D;
public interface Observable {
    public void addObserver(Observer observer);
    public void deleteObserver(Observer observer);
    public void notifyObserver(Point2D point);
}
