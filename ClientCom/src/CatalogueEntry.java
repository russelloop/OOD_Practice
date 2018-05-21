public class CatalogueEntry {
    private String name;
    private long number;
    private double cost;

    public CatalogueEntry(String name, long number, double cost){
        this.name = name;
        this.number = number;
        this.cost = cost;
    }

    public String getName(){return name;}
    public long getNum(){return  number;}
    public double getCost(){return cost;}
}
