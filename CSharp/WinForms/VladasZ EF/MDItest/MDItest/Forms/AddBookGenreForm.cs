using MDItest.Database;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MDItest.Forms
{
    public partial class AddBookGenreForm : Form
    {
        public AddBookGenreForm()
        {
            InitializeComponent();
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            WindowManager.closeWindow(this);
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            if(string.IsNullOrEmpty(genreTextBox.Text))
            {
                MessageBox.Show("Введите название жанра");
                return;
            }

            DatabaseManager.addGenre(genreTextBox.Text);

            WindowManager.GenresComboBox.Text = genreTextBox.Text;

            WindowManager.closeWindow(this);
        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            genreTextBox.Clear();
        }
    }
}
