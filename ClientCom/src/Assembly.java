import java.util.ArrayList;

public class Assembly extends Component{
    private ArrayList part = new ArrayList();
    public void add(Part p){
        part.add(p);
    }
    public double getCost(){
        double sum_cost = 0;
        for(int i  = 0; i < part.size(); i++){
            Part itm = (Part)part.get(i);
            sum_cost += itm.getCost();
        }
        return sum_cost;
    }
}
