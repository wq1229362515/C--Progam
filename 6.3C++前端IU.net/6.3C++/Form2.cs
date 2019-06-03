using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace _6._3C__
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
          
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            DataRow row = dataTable1.NewRow();
            row[0]= textBox1.Text.ToString();
            row[1]= textBox2.Text.ToString();
            row[2]= textBox3.Text.ToString();
            row[3]= textBox4.Text.ToString();
            dataTable1.Rows.Add(row);
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = dataTable1.Rows[0]["姓名"].ToString();
            textBox2.Text = dataTable1.Rows[0]["学号"].ToString();
            textBox3.Text = dataTable1.Rows[0]["性别"].ToString();
            textBox4.Text = dataTable1.Rows[0]["年龄"].ToString();
            dataTable1.Rows.Clear();

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form1 fom = new Form1();
            fom.Show();
            this.Hide();
        }
    }
}
