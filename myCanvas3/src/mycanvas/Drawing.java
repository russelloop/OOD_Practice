package mycanvas;
import javax.swing.undo.AbstractUndoableEdit;
import javax.swing.undo.UndoableEdit;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics2D;
import java.io.Serializable;
//图形绘制类 用于绘制各种图形
/*类通过实现 java.io.Serializable 接口以启用其序列化功能。
*/
public class Drawing implements Serializable{
    private static final long serialVersionUID = -4142755153386100185L;
    int x1,x2,y1,y2;   	    //定义坐标属性
    int  R,G,B;				//定义色彩属性
    float stroke ;			//定义线条粗细的属性
    int type;				//定义字体属性
    String s1;				//定义字体的风格
    String s2;				//定义字体的风格
    void draw(Graphics2D cd){}//定义绘图函数
}
class Line extends Drawing//直线类
{
    void draw(Graphics2D cd) {
        cd.setPaint(new Color(R, G, B));// 为 Graphics2D 上下文设置 Paint 属性。
        // 使用为 null 的 Paint 对象调用此方法对此 Graphics2D 的当前 Paint 属性没有任何影响。
        cd.setStroke(new BasicStroke(stroke, BasicStroke.CAP_ROUND,
                BasicStroke.JOIN_BEVEL));
        // setStroke(Stroke s)为 Graphics2D 上下文设置 Stroke
        // BasicStroke 类定义针对图形图元轮廓呈现属性的一个基本集合
        // BasicStroke.CAP_ROUND使用半径等于画笔宽度一半的圆形装饰结束未封闭的子路径和虚线线段
        // BasicStroke.JOIN_BEVEL通过直线连接宽体轮廓的外角，将路径线段连接在一起。
        cd.drawLine(x1, y1, x2, y2);// 画直线
    }
}

//矩形类
class Rect extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(R,G,B));
        cd.setStroke(new BasicStroke(stroke));
        cd.drawRect(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x1-x2), Math.abs(y1-y2));
    }
}
//实心矩形类
class fillRect extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(R,G,B));
        cd.setStroke(new BasicStroke(stroke));
        cd.fillRect(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x1-x2), Math.abs(y1-y2));
    }
}
//椭圆类
class Oval extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(R,G,B));
        cd.setStroke(new BasicStroke(stroke));
        cd.drawOval(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x1-x2), Math.abs(y1-y2));
    }
}
//实心椭圆类
class fillOval extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(R,G,B));
        cd.setStroke(new BasicStroke(stroke));
        cd.fillOval(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x1-x2), Math.abs(y1-y2));
    }
}
//圆类
class Circle extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(R,G,B));
        cd.setStroke(new BasicStroke(stroke));
        cd.drawOval(Math.min(x1, x2), Math.min(y1, y2), Math.max(Math.abs(x1-x2),
                Math.abs(y1-y2)), Math.max(Math.abs(x1-x2), Math.abs(y1-y2)));
    }
}
//实心圆类
class fillCircle extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(R,G,B));
        cd.setStroke(new BasicStroke(stroke));
        cd.fillOval(Math.min(x1, x2), Math.min(y1, y2), Math.max(Math.abs(x1-x2),
                Math.abs(y1-y2)), Math.max(Math.abs(x1-x2), Math.abs(y1-y2)));
    }
}
//圆角矩形类
class RoundRect extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(R,G,B));
        cd.setStroke(new BasicStroke(stroke));
        cd.drawRoundRect(Math.min(x1, x2), Math.min(y1, y2),Math.abs(x1-x2), Math.abs(y1-y2),50,35);
    }
}
//实心圆角矩形类
class fillRoundRect extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(R,G,B));
        cd.setStroke(new BasicStroke(stroke));
        cd.fillRoundRect(Math.min(x1, x2), Math.min(y1, y2),Math.abs(x1-x2), Math.abs(y1-y2),50,35);
    }
}
//随笔画类
class Pencil extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(R,G,B));
        cd.setStroke(new BasicStroke(stroke,BasicStroke.CAP_ROUND,BasicStroke.JOIN_BEVEL));
        cd.drawLine(x1, y1,x2, y2);
    }
}
//橡皮擦类
class Rubber extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(255,255,255));//白色
        cd.setStroke(new BasicStroke(stroke+4,BasicStroke.CAP_ROUND,BasicStroke.JOIN_BEVEL));
        cd.drawLine(x1, y1,x2, y2);
    }
}//输入文字类
class Word extends Drawing{
    void draw(Graphics2D cd){
        cd.setPaint(new Color(R,G,B));
        cd.setFont(new Font(s2,x2+y2,((int)stroke)*18));//设置字体
        if(s1 != null)
            cd.drawString( s1, x1,y1);
    }
}

