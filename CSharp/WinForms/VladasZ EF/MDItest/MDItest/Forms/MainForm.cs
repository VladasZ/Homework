using MDItest.Database;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MDItest
{
    public partial class MainForm : Form
    {
        public Form[] GetMdiChildren { get { return MdiChildren; } }
        public ToolStripStatusLabel statusLabel { get { return toolStripStatusLabel; } }

        public MainForm()
        {
            InitializeComponent();

            StartPosition = FormStartPosition.CenterScreen;
        }

        private void addBookToolStripMenuItem_Click(object sender, EventArgs e)
        {
            WindowManager.Open.addBookWindow();
        }

        private void minimizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach(Form form in GetMdiChildren)
            {
                form.WindowState = FormWindowState.Minimized;
            }
        }

        private void normalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Form form in GetMdiChildren)
            {
                form.WindowState = FormWindowState.Normal;
            }
        }

        private void cascadeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.Cascade);
        }

        private void horizontalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void verticalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);
        }

        private void arrowIconsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.ArrangeIcons);
        }

        private void bookListToolStripMenuItem_Click(object sender, EventArgs e)
        {
            WindowManager.Open.bookListWindow();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            WindowManager.Open.bookListWindow();
            WindowManager.setStatus();
        }

        private void fileToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void addBookToolStripButton_Click(object sender, EventArgs e)
        {
            WindowManager.Open.addBookWindow();
        }

        private void addGenreToolStripButton_Click(object sender, EventArgs e)
        {
            WindowManager.Open.addBookGenreWindow();
        }

        private void addPublisherToolStripButton_Click(object sender, EventArgs e)
        {
            WindowManager.Open.addPublisherWindow();
        }

        private void bookListToolStripButton_Click(object sender, EventArgs e)
        {
            WindowManager.Open.bookListWindow();
        }

        private void addTypeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            WindowManager.Open.addBookGenreWindow();
        }

        private void addToolStripMenuItem_Click(object sender, EventArgs e)
        {
            WindowManager.Open.addPublisherWindow();
        }
    }
}
