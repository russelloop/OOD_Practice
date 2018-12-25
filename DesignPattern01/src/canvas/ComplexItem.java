package canvas;

import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.List;

public class ComplexItem extends GraphicItem{
    private ArrayList GraphicItems;
    public ComplexItem(){
        GraphicItems = new ArrayList();
        GraphicItems.add(super.getRectangle());
    }
}
