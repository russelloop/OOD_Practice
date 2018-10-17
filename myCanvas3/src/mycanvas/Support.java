package mycanvas;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
//帮助菜单功能的事项类
public class Support extends JFrame {
    private Canvas drawpad = null;
    Support(Canvas dp)
    {
        drawpad = dp;
    }

    public void MainHeip()
    {
        JOptionPane.showMessageDialog(this,"Support","Canvas",JOptionPane.WARNING_MESSAGE);
    }
    public void AboutBook()
    {
        JOptionPane.showMessageDialog(drawpad,"\n  Canvas"+"\n"+"  ver: 1.4.3"+"\n"
                +"  Create by Root "+"\n"
                +"  2018 / 06","Canvas",JOptionPane.WARNING_MESSAGE);
    }
}
