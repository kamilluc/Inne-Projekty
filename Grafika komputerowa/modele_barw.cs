using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace kolory
{
    public partial class Form1 : Form
    {
        Graphics g1;
        Graphics g2;
        Graphics g3;
        Graphics g4;
        Graphics g5;
        Graphics g6;
        Graphics g7;
        Graphics g8;
        Graphics g9;
        Bitmap b1;
        Bitmap b2;
        Bitmap b3;
        Bitmap b4;
        Bitmap b5;
        Bitmap b6;
        Bitmap b7;
        Bitmap b8;
        Bitmap b9;


        public Form1()
        {
            InitializeComponent();

            b1 = new Bitmap(100, 100);
            b2 = new Bitmap(100, 100);
            b3 = new Bitmap(100, 100);
            b4 = new Bitmap(100, 100);
            b5 = new Bitmap(100, 100);
            b6 = new Bitmap(100, 100);

            pictureBox1.Image = b1;
            pictureBox2.Image = b2;
            pictureBox3.Image = b3;
            pictureBox4.Image = b4;
            pictureBox5.Image = b5;
            pictureBox6.Image = b6;

            g1 = Graphics.FromImage(b1);
            g2 = Graphics.FromImage(b2);
            g3 = Graphics.FromImage(b3);
            g4 = Graphics.FromImage(b4);
            g5 = Graphics.FromImage(b5);
            g6 = Graphics.FromImage(b6);

            b7 = new Bitmap(360, 40);
            b8 = new Bitmap(360, 40);
            b9 = new Bitmap(360, 40);

            pictureBox7.Image = b7;
            pictureBox8.Image = b8;
            pictureBox9.Image = b9;

            g7 = Graphics.FromImage(b7);
            g8 = Graphics.FromImage(b8);
            g9 = Graphics.FromImage(b9);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Color color1;
            Color color2;
            Color color3;
            Color color4;
            Color color5;
            Color color6;

            for (int x = 0; x < 100; x++)
            {
                for (int y = 0; y < 100; y++)
                {
                    int u = (int)(x * 255.0 / 100);
                    int v = (int)(y * 255.0 / 100);

                    color1 = Color.FromArgb(255, u, v);
                    color2 = Color.FromArgb(255 - u, 255, v);
                    color3 = Color.FromArgb(0, 255 - u, v);
                    color4 = Color.FromArgb(u, 0, v);
                    color5 = Color.FromArgb(255 - u, v, 0);
                    color6 = Color.FromArgb(255 - u, 255 - v, 255);

                    b1.SetPixel(x, y, color1);
                    b2.SetPixel(x, y, color2);
                    b3.SetPixel(x, y, color3);
                    b4.SetPixel(x, y, color4);
                    b5.SetPixel(x, y, color5);
                    b6.SetPixel(x, y, color6);
                }
            }

            pictureBox1.Refresh();
            pictureBox2.Refresh();
            pictureBox3.Refresh();
            pictureBox4.Refresh();
            pictureBox5.Refresh();
            pictureBox6.Refresh();

            for (int x = 0; x < 360; x++)
            {
                for (int y = 0; y < 40; y++)
                {
                    b7.SetPixel(x, y, ColorFromHSV(x, 1, 1));
                    b8.SetPixel(x, y, ColorFromHSV(x, 1, y / 40.0));
                    b9.SetPixel(x, y, ColorFromHSV(x, y / 40.0, 1));
                }
            }

            pictureBox7.Refresh();
            pictureBox8.Refresh();
            pictureBox9.Refresh();
        }

        private void pictureBox_Click(Bitmap bitmap, EventArgs e)
        {
            MouseEventArgs me = (MouseEventArgs)e;
            Point p = me.Location;

            Color c = bitmap.GetPixel(p.X, p.Y);

            textBox1.Text = Convert.ToString(c.R);
            textBox2.Text = Convert.ToString(c.G);
            textBox3.Text = Convert.ToString(c.B);

            textBox4.Text = Convert.ToString(1 - c.R / 255.0);
            textBox5.Text = Convert.ToString(1 - c.G / 255.0);
            textBox6.Text = Convert.ToString(1 - c.B / 255.0);

            int max = Math.Max(c.R, Math.Max(c.G, c.B));
            int min = Math.Min(c.R, Math.Min(c.G, c.B));

            double hue = c.GetHue();
            double saturation = (max == 0) ? 0 : 1d - (1d * min / max);
            double value = max / 255d;

            textBox7.Text = Convert.ToString(hue);
            textBox8.Text = Convert.ToString(saturation);
            textBox9.Text = Convert.ToString(value);
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            pictureBox_Click(b1, e);
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            pictureBox_Click(b2, e);
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            pictureBox_Click(b3, e);
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            pictureBox_Click(b4, e);
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            pictureBox_Click(b5, e);
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            pictureBox_Click(b6, e);
        }

        public static Color ColorFromHSV(double hue, double saturation, double value)
        {
            int hi = Convert.ToInt32(Math.Floor(hue / 60)) % 6;
            double f = hue / 60 - Math.Floor(hue / 60);

            value = value * 255;
            int v = Convert.ToInt32(value);
            int p = Convert.ToInt32(value * (1 - saturation));
            int q = Convert.ToInt32(value * (1 - f * saturation));
            int t = Convert.ToInt32(value * (1 - (1 - f) * saturation));

            if (hi == 0)
                return Color.FromArgb(255, v, t, p);
            else if (hi == 1)
                return Color.FromArgb(255, q, v, p);
            else if (hi == 2)
                return Color.FromArgb(255, p, v, t);
            else if (hi == 3)
                return Color.FromArgb(255, p, q, v);
            else if (hi == 4)
                return Color.FromArgb(255, t, p, v);
            else
                return Color.FromArgb(255, v, p, q);
        }
    }
}
