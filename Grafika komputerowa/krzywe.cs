using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace grafika_kamil
{
    public partial class Form1 : Form
    {
        private System.Drawing.Graphics g;
        private System.Drawing.Pen pen1 = new System.Drawing.Pen(Color.Blue, 3);
        private System.Drawing.Pen pen2 = new System.Drawing.Pen(Color.Red, 3);
        public Form1()
        {
            InitializeComponent();
            g = pictureBox1.CreateGraphics();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Refresh();

            double x1, x2, x3, x4;
            double y1, y2, y3, y4;
            double.TryParse(textBox1.Text.Replace(".", ","), out x1);
            double.TryParse(textBox2.Text.Replace(".", ","), out y1);
            double.TryParse(textBox3.Text.Replace(".", ","), out x2);
            double.TryParse(textBox4.Text.Replace(".", ","), out y2);
            double.TryParse(textBox5.Text.Replace(".", ","), out x3);
            double.TryParse(textBox6.Text.Replace(".", ","), out y3);
            double.TryParse(textBox7.Text.Replace(".", ","), out x4);
            double.TryParse(textBox8.Text.Replace(".", ","), out y4);

            double tmpx = x1, tmpy = y1, tmpx2, tmpy2;
            double t = 0.0;

            tmpx2 = Math.Pow(1 - t, 3) * x1 + 3 * Math.Pow(1 - t, 2) * t * x2 + 3 * (1 - t) * t * t * x3 + t * t * t * x4;
            tmpy2 = Math.Pow(1 - t, 3) * y1 + 3 * Math.Pow(1 - t, 2) * t * y2 + 3 * (1 - t) * t * t * y3 + t * t * t * y4;
            for (t = 0.001; t < 1; t += 0.0001)
            {
                tmpx = tmpx2;
                tmpy = tmpy2;
                tmpx2 = Math.Pow(1 - t, 3) * x1 + 3 * Math.Pow(1 - t, 2) * t * x2 + 3 * (1 - t) * t * t * x3 + t * t * t * x4;
                tmpy2 = Math.Pow(1 - t, 3) * y1 + 3 * Math.Pow(1 - t, 2) * t * y2 + 3 * (1 - t) * t * t * y3 + t * t * t * y4;
                g.DrawLine(pen1, (float)tmpx, (float)tmpy, (float)tmpx2, (float)tmpy2);
               
            }
          
        }

        private void button2_Click(object sender, EventArgs e)
        {

            pictureBox1.Refresh();
            double x1, x2, x3, x4;
            double y1, y2, y3, y4;
            double liczba, liczba2;
            double xz;
            double yz;
            double r1x, r1y, r4x, r4y;



            double.TryParse(textBox1.Text.Replace(".", ","), out x1);
            double.TryParse(textBox2.Text.Replace(".", ","), out y1);
            double.TryParse(textBox3.Text.Replace(".", ","), out x2);
            double.TryParse(textBox4.Text.Replace(".", ","), out y2);
            double.TryParse(textBox5.Text.Replace(".", ","), out x3);
            double.TryParse(textBox6.Text.Replace(".", ","), out y3);
            double.TryParse(textBox7.Text.Replace(".", ","), out x4);
            double.TryParse(textBox8.Text.Replace(".", ","), out y4);
            double.TryParse(textBox3.Text, out liczba);

            liczba2 = 1 / liczba;
            double Qx = x1;
            double Qy = y1;

            r1x = x2 - x1;
            r1y = y2 - y1;
            r4x = x4 - x3;
            r4y = y4 - y3;

            for (double t = 0; t <= 1; t += 0.0001)
            {
                xz = Qx;
                yz = Qy;
                Qx = ((2 * Math.Pow(t, 3) - 3 * Math.Pow(t, 2) + 1) * x1) + (-2 * Math.Pow(t, 3) + 3 * Math.Pow(t, 2)) * x4 + (Math.Pow(t, 3) - 2 * Math.Pow(t, 2) + t) *
                r1x + (Math.Pow(t, 3) - (Math.Pow(t, 2))) * r4x;
                Qy = ((2 * Math.Pow(t, 3) - 3 * Math.Pow(t, 2) + 1) * y1) + (-2 * Math.Pow(t, 3) + 3 * Math.Pow(t, 2)) * y4 + (Math.Pow(t, 3) - 2 * Math.Pow(t, 2) + t) *
                r1y + (Math.Pow(t, 3) - (Math.Pow(t, 2))) * r4y;
                g.DrawLine(pen1, (float)xz, (float)yz, (float)Qx, (float)Qy);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {

            pictureBox1.Refresh();

            PointF[] p = new PointF[4];
            double x1, x2, x3, x4;
            double y1, y2, y3, y4;
            double.TryParse(textBox1.Text.Replace(".", ","), out x1);
            double.TryParse(textBox2.Text.Replace(".", ","), out y1);
            double.TryParse(textBox3.Text.Replace(".", ","), out x2);
            double.TryParse(textBox4.Text.Replace(".", ","), out y2);
            double.TryParse(textBox5.Text.Replace(".", ","), out x3);
            double.TryParse(textBox6.Text.Replace(".", ","), out y3);
            double.TryParse(textBox7.Text.Replace(".", ","), out x4);
            double.TryParse(textBox8.Text.Replace(".", ","), out y4);

            p[0] = new PointF((float)x1, (float)y1);
            p[1] = new PointF((float)x2, (float)y2);
            p[2] = new PointF((float)x3, (float)y3);
            p[3] = new PointF((float)x4, (float)y4);




            double t = 0;
            double px, py;

            double x, y;

            px = (((1 - t) * (1 - t) * (1 - t) * p[0].X) / 6) + ((3 * t * t * t) - (6 * t * t) + 4) * p[1].X / 6 + (-3 * t * t * t + 3 * t * t + 3 * t + 1) * p[2].X / 6 + (t * t * t) * p[3].X / 6;
            py = (((1 - t) * (1 - t) * (1 - t) * p[0].Y) / 6) + ((3 * t * t * t) - (6 * t * t) + 4) * p[1].Y / 6 + (-3 * t * t * t + 3 * t * t + 3 * t + 1) * p[2].Y / 6 + (t * t * t) * p[3].Y / 6;

            int i = 0;

            for (t = 0; t <= 1; t += 0.0001)
            {

                x = (((1 - t) * (1 - t) * (1 - t) * p[i].X) / 6) + ((3 * t * t * t) - (6 * t * t) + 4) * p[i + 1].X / 6 + (-3 * t * t * t + 3 * t * t + 3 * t + 1) * p[i + 2].X / 6 + (t * t * t) * p[i + 3].X / 6;
                y = (((1 - t) * (1 - t) * (1 - t) * p[i].Y) / 6) + ((3 * t * t * t) - (6 * t * t) + 4) * p[i + 1].Y / 6 + (-3 * t * t * t + 3 * t * t + 3 * t + 1) * p[i + 2].Y / 6 + (t * t * t) * p[i + 3].Y / 6;

                g.DrawLine(pen1, (float)px, (float)py, (float)x, (float)y);

                px = x;
                py = y;

            }
            /*
             *       {

            g = pictureBox1.CreateGraphics();
            pictureBox1.Refresh();

            PointF[] p = new PointF[14];

        
            p[0] = new PointF(100, 150);
            p[1] = new PointF(234, 550);
            p[2] = new PointF(250, 330);
            p[3] = new PointF(400, 320);

            p[4] = new PointF(200, 150);
            p[5] = new PointF(633, 150);
            p[6] = new PointF(430, 140);
            p[7] = new PointF(400, 150);

            p[8] = new PointF(300, 70);
            p[9] = new PointF(200, 140);

            p[10] = new PointF(300, 450);
            p[11] = new PointF(450, 350);
            p[12] = new PointF(250, 350);
            p[13] = new PointF(230, 300);


            float t = 0;
            float px, py;

            float x, y;

            px = (((1 - t) * (1 - t) * (1 - t) * p[0].X) / 6) + ((3 * t * t * t) - (6 * t * t) + 4) * p[1].X / 6 + (-3 * t * t * t + 3 * t * t + 3 * t + 1) * p[2].X / 6 + (t * t * t) * p[3].X / 6;
            py = (((1 - t) * (1 - t) * (1 - t) * p[0].Y) / 6) + ((3 * t * t * t) - (6 * t * t) + 4) * p[1].Y / 6 + (-3 * t * t * t + 3 * t * t + 3 * t + 1) * p[2].Y / 6 + (t * t * t) * p[3].Y / 6;


            for (int i = 0; i < 11; i++)
            {
                for (t = 0; t <= 1; t += 0.2f)
                {

                    x = (((1 - t) * (1 - t) * (1 - t) * p[i].X) / 6) + ((3 * t * t * t) - (6 * t * t) + 4) * p[i + 1].X / 6 + (-3 * t * t * t + 3 * t * t + 3 * t + 1) * p[i + 2].X / 6 + (t * t * t) * p[i + 3].X / 6;
                    y = (((1 - t) * (1 - t) * (1 - t) * p[i].Y) / 6) + ((3 * t * t * t) - (6 * t * t) + 4) * p[i + 1].Y / 6 + (-3 * t * t * t + 3 * t * t + 3 * t + 1) * p[i + 2].Y / 6 + (t * t * t) * p[i + 3].Y / 6;

                    g.DrawLine(pen1, px, py, x, y);

                    px = x;
                    py = y;
                }
            }

          
        }*/
        }
    }
}
