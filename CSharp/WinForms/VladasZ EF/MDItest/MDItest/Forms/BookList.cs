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
    public partial class BookList : Form
    {
        public DataGridView BooksGridView { get { return dataGridView; } }

        public BookList()
        {
            InitializeComponent();

            dataGridView.DataSource = DatabaseManager.getAllBooks();
        }

        private void AddBookButton_Click(object sender, EventArgs e)
        {
            WindowManager.Open.addBookWindow();
        }

        private void deleteBookBtn_Click(object sender, EventArgs e)
        {
            string bookName = dataGridView.CurrentRow.Cells[0].Value.ToString();

            DatabaseManager.deleteBook(bookName);

            dataGridView.DataSource = DatabaseManager.getAllBooks();

            WindowManager.setStatus();
        }
    }
}
