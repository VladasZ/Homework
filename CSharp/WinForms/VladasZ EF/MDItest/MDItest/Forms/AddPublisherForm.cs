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
    public partial class AddPublisherForm : Form
    {
        public AddPublisherForm()
        {
            InitializeComponent();
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            WindowManager.closeWindow(this);
        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            nameTextBox.Clear();
            addressTextBox.Clear();
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            if(string.IsNullOrEmpty(nameTextBox.Text))
            {
                MessageBox.Show("Введите название издателя");
                return;
            }

            if (string.IsNullOrEmpty(addressTextBox.Text))
            {
                MessageBox.Show("Введите адрес издателя");
                return;
            }

            DatabaseManager.addPublisher(nameTextBox.Text, addressTextBox.Text);

            WindowManager.PublishersComboBox.Text = nameTextBox.Text;

            WindowManager.closeWindow(this);
        }
    }
}
