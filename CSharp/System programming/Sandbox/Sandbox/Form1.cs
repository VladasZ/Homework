using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sandbox
{
    public partial class Form1 : Form
    {
        int nubmer = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Text = (nubmer++).ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //ThreadPool.QueueUserWorkItem(Work);

            Thread thread = new Thread(Work);

            thread.Start();

            thread.Join();
        }

        private void Work(object o)
        {
            int foo = 4;

            for (int i = 0; i < 1000000000; i++)
            {
                foo++;
                foo--;
            }

            MessageBox.Show("okokokoko");
        }
    }
}
