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
    public partial class AddBookForm : Form
    {
        public AddBookForm()
        {
            InitializeComponent();

            AcceptButton = addBookButton;

            genreComboBox.DataSource = DatabaseManager.getGenresNames();
            publisherComboBox.DataSource = DatabaseManager.getPublishersNames();
        }

        public ComboBox GenreComboBox { get { return genreComboBox; } }
        public ComboBox PublisherComboBox { get { return publisherComboBox; } }

        private void cancelAddBookButton_Click(object sender, EventArgs e)
        {
            WindowManager.closeWindow(this);
        }

        private void addBookTypeButton_Click(object sender, EventArgs e)
        {
            WindowManager.Open.addBookGenreWindow();
        }

        private void addPublisherButton_Click(object sender, EventArgs e)
        {
            WindowManager.Open.addPublisherWindow();
        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            nameTextBox.Clear();
            genreComboBox.SelectedIndex = 0;
            publisherComboBox.SelectedIndex = 0;
        }

        private void addBookButton_Click(object sender, EventArgs e)
        {
            if(string.IsNullOrEmpty(nameTextBox.Text))
            {
                MessageBox.Show("Введите название книги");
                return;
            }

            DatabaseManager.addBook(nameTextBox.Text, genreComboBox.Text, publisherComboBox.Text);

            WindowManager.closeWindow(this);
            WindowManager.setStatus();
        }
    }
}
