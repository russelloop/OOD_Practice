
import java.util.Iterator;
import java.util.TreeMap;

public class Process {
    int T;                    // 总时间
    int t;                    // 更换时间
    double protein;
    double O_total;            // 总的产量
    double O_c;                // C 的加工后产量
    double O_e;                // E 的加工产量
    double proteinContent;
    double cContent;
    double e1Content;

    TreeMap<Integer,Integer> treeMap = new TreeMap<Integer,Integer>();

    private boolean protein_Enough_Check() {
        protein = 130/60*t*0.7*0.07 + 40/60*(T-t-120)*0.6*0.08 + 15/60*T*0.8*0.4;
        O_total = 130/60*t*0.7 + 40/60*(T-t-120)*0.6 + 15/60*T*0.8;
        proteinContent = protein / O_total;
        System.out.print("protein = " + protein + "  O_total = " + O_total);
        System.out.println("  proteinContent = " + proteinContent);
        if (proteinContent >= 0.13 && proteinContent <= 0.16)
            return true;
        else
            return false;
    }

    private boolean c_Enough_Check() {
        O_c = 15/60*T*0.8;
        O_e = 130/60*t*0.7 + 40/60*(T-t-120)*0.6;
        cContent = O_c / O_total;
        System.out.println("  cContent= " + cContent);
        if (cContent >= 0.1 && cContent <= 0.2)
            return true;
        else
            return false;
    }

    private boolean e1_Enough_Check() {
        e1Content = ((40/60*(T-t-120)) / (130/60*t + 40/60*(T-t)));
        System.out.println("  e1Content= " + e1Content);
        if (e1Content >= 0.1)
            return true;
        else
            return false;
    }

    private boolean t_Check() {
        if (t < T)
            return true;
        return false;
    }

    public void solution() {
        for (Integer i = 1; i <= 24 * 60; i++) {
            T = i;
            for (Integer j = 1; j < T; j++) {
                t = j;
                System.out.println(T + " : " + t);
                if (protein_Enough_Check() && c_Enough_Check() && e1_Enough_Check()) {
                    treeMap.put(t, T);
                    System.out.println("found");
                }
            }
        }
    }

    public void getSolution() {
        for (Iterator<Integer> it = treeMap.keySet().iterator(); it.hasNext();) {
            Integer enough_T = treeMap.get(it.next());
            System.out.println("t: " + enough_T.toString() + " T: " + it.next());
        }
    }

    public static void main(String[] args) {
        Process math_build = new Process();
        math_build.solution();
        math_build.getSolution();
    }

}




