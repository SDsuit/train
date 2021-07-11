/**
 * 台球演示
 * @author SD_suit
 * @version 1.0.0
 */

import java.awt.*;
import javax.swing.*;

public class BallGame extends JFrame
{
    Image ball = Toolkit.getDefaultToolkit().getImage("images/ball.png");
    Image table = Toolkit.getDefaultToolkit().getImage("images/table.jpg");

    double degree = 3.14 / 3;

    double x = 200;
    double y = 200;
    //绘制窗口
    public void paint(Graphics g)
    {
        System.out.println("窗口被画了一次");
        g.drawImage(table,0,0,null);
        g.drawImage(ball,(int)x,(int)y,null);

        x = x + 10*Math.cos(degree);
        y = y + 10*Math.sin(degree);

        //碰到上下边界
        if(y>501-40-30||y<40+40)
        {
            degree = - degree;

        }
        //碰到左右边界
        if(x>856-40-30||x<40)
        {
            degree = 3.14 - degree;
        }


    }
    //创建窗口
    void launchFrame()
    {
        setSize(856,501);
        setLocation(100,100);
        setVisible(true);

        //实现动画，每秒绘制窗口25次
        while(true)
        {
            repaint();
            try
            {
                Thread.sleep(40);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
    public static void main(String[] args)
    {
        System.out.println("Game Start");
        BallGame game = new BallGame();
        game.launchFrame();
    }
}
