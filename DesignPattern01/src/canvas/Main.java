package canvas;
import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        EventQueue.invokeLater(() ->{
            JFrame frame = new MainFrame();
            frame.setTitle("Canvas");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
        });
    }
}


class MainFrame extends JFrame{

    public MainFrame(){
        add(new MajComposite(this));
        pack();
    }

}