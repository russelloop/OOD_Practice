package mycanvas;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.undo.UndoableEdit;
import java.awt.event.MouseMotionAdapter;
//绘图区类（各种图形的绘制和鼠标事件）
public class DrawArea extends JPanel{
    Canvas drawpad =null;
    Drawing[] itemList =new Drawing[5000];; //绘制图形类
    private int currentChoice = 3;//设置默认基本图形状态为随笔画
    int index = 0;//当前已经绘制的图形数目
    private Color color = Color.black;//当前画笔的颜色
    int R,G,B;//用来存放当前颜色的彩值
    int f1,f2;//用来存放当前字体的风格
    String stytle ;//存放当前字体
    float stroke = 1.0f;//设置画笔的粗细 ，默认的是 1.0
    DrawArea(Canvas dp) {
        drawpad = dp;
        // 把鼠标设置成十字形
        setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
        // setCursor 设置鼠标的形状 ，getPredefinedCursor()返回一个具有指定类型的光标的对象
        setBackground(Color.white);// 设置绘制区的背景是白色
        addMouseListener(new xMouse());// 添加鼠标事件
        addMouseMotionListener(new yMouse());
        createNewitem();
    }

    public void paintComponent(Graphics g){
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D)g;//定义随笔画
        int  j = 0;
        while(j<=index)
        {
            draw(g2d,itemList[j]);
            j++;
        }

    }

    void draw(Graphics2D g2d , Drawing i)
    {
        i.draw(g2d);//将画笔传到个各类的子类中，用来完成各自的绘图
    }

    //新建一个图形的基本单元对象的程序段
    void createNewitem(){
        if(currentChoice == 14)//字体的输入光标相应的设置为文本输入格式
            setCursor(Cursor.getPredefinedCursor(Cursor.TEXT_CURSOR));
        else  	setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
        switch(currentChoice){
            case 3: itemList[index] = new Pencil();break;
            case 4://Line line = new Line();
                //UndoableEdit ud_line = line;
                //manager.addChangeable(line);
                itemList[index] = new Line();break;
            case 5: itemList[index] = new Rect();break;
            case 6: itemList[index] = new fillRect();break;
            case 7: itemList[index] = new Oval();break;
            case 8: itemList[index] = new fillOval();break;
            case 9: itemList[index] = new Circle();break;
            case 10: itemList[index] = new fillCircle();break;
            case 11: itemList[index] = new RoundRect();break;
            case 12: itemList[index] = new fillRoundRect();break;
            case 13: itemList[index] = new Rubber();break;
            case 14: itemList[index] = new Word();break;
        }
        itemList[index].type = currentChoice;
        itemList[index].R = R;
        itemList[index].G = G;
        itemList[index].B = B;
        itemList[index].stroke = stroke ;

    }

    public void setIndex(int x){//设置index的接口
        index = x;
    }
    public int getIndex(){//设置index的接口
        return index ;
    }
    //public void undo(){ manager.undo();}
    public void setColor(Color color)//设置颜色的值
    {
        this.color = color;
    }
    public void setStroke(float f)//设置画笔粗细的接口
    {
        stroke = f;
    }
    public void chooseColor()//选择当前颜色
    {
        color = JColorChooser.showDialog(drawpad, "Pick a color", color);
        try {
            R = color.getRed();
            G = color.getGreen();
            B = color.getBlue();
        } catch (Exception e) {
            R = 0;
            G = 0;
            B = 0;
        }
        itemList[index].R = R;
        itemList[index].G = G;
        itemList[index].B = B;
    }
    public void setFontStyle(){
        GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();//计算机上字体可用的名称
        String[] obj = ge.getAvailableFontFamilyNames();
        String s = (String) JOptionPane.showInputDialog(null,"Pick a FontType:\n", "Font", JOptionPane.PLAIN_MESSAGE, new ImageIcon("icon.png"), obj, "default");
        stytle = s;
    }
    public void setStroke()//画笔粗细的调整
    {
        String input ;
        input = JOptionPane.showInputDialog("Set Pen Radius( >0 )");
        try {
            stroke = Float.parseFloat(input);

        } catch (Exception e) {
            stroke = 1.0f;

        }itemList[index].stroke = stroke;

    }
    public void setCurrentChoice(int i )//文字的输入
    {
        currentChoice = i;
    }
    public void setFont(int  i,int font)//设置字体
    {
        if(i == 1)
        {
            f1 = font;
        }
        else
            f2 = font;
    }
    //鼠标事件xMouse类继承了xMousedapter
//用来完成鼠标的响应事件的操作（鼠标的按下、释放、单击、移动、拖动、何时进入一个组件、何时退出、何时滚动鼠标滚轮 )
    class xMouse extends MouseAdapter {

        @Override
        public void mouseEntered(MouseEvent me) {
            //鼠标进入
            drawpad.setStratBar("MouseInAt：["+me.getX()+" ,"+me.getY()+"]");
        }
        @Override
        public void mouseExited(MouseEvent me) {
            //鼠标退出
            drawpad.setStratBar("MouseOutAt：["+me.getX()+" ,"+me.getY()+"]");
        }
        @Override
        public void mousePressed(MouseEvent me) {
            //鼠标按下
            drawpad.setStratBar("MouseClickAt：["+me.getX()+" ,"+me.getY()+"]");//设置状态栏提示

            itemList[index].x1 = itemList[index].x2 = me.getX();
            itemList[index].y1 = itemList[index].y2 = me.getY();

            //如果当前选择为随笔画或橡皮擦 ，则进行下面的操作
            if(currentChoice == 3||currentChoice ==13){
                itemList[index].x1 = itemList[index].x2 = me.getX();
                itemList[index].y1 = itemList[index].y2 = me.getY();
                index++;
                createNewitem();//创建新的图形的基本单元对象
            }
            //如果选择图形的文字输入，则进行下面的操作
            if(currentChoice == 14){
                itemList[index].x1 = me.getX();
                itemList[index].y1 = me.getY();
                String input ;
                input = JOptionPane.showInputDialog("Enter your text");
                itemList[index].s1 = input;
                itemList[index].x2 = f1;
                itemList[index].y2 = f2;
                itemList[index].s2 = stytle;

                index++;
                currentChoice = 14;
                createNewitem();//创建新的图形的基本单元对象
                repaint();
            }

        }
        @Override
        public void mouseReleased(MouseEvent me) {
            //鼠标松开
            drawpad.setStratBar("MouseReleaseAt：["+me.getX()+" ,"+me.getY()+"]");
            if(currentChoice == 3||currentChoice ==13){
                itemList[index].x1 = me.getX();
                itemList[index].y1 = me.getY();
            }
            itemList[index].x2 = me.getX();
            itemList[index].y2 = me.getY();
            repaint();
            index++;
            createNewitem();//创建新的图形的基本单元对象
        }
    }

    // 鼠标事件yMouse继承了MouseMotionAdapter
    // 用来处理鼠标的滚动与拖动
    class yMouse extends MouseMotionAdapter {
        public void mouseDragged(MouseEvent me)//鼠标的拖动
        {
            drawpad.setStratBar("MouseDragAt：["+me.getX()+" ,"+me.getY()+"]");
            if(currentChoice == 3||currentChoice ==13){
                itemList[index-1].x1 = itemList[index].x2 = itemList[index].x1 =me.getX();
                itemList[index-1].y1 = itemList[index].y2 = itemList[index].y1 = me.getY();
                index++;
                createNewitem();//创建新的图形的基本单元对象
            }
            else
            {
                itemList[index].x2 = me.getX();
                itemList[index].y2 = me.getY();
            }
            repaint();
        }
        public void mouseMoved(MouseEvent me)//鼠标的移动
        {
            drawpad.setStratBar("MouseMoveAt：["+me.getX()+" ,"+me.getY()+"]");
        }
    }
}
