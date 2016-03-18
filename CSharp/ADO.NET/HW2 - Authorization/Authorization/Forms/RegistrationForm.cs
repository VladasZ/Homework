using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Authorization
{
    public partial class RegistrationForm : Form
    {
        public RegistrationForm()
        {
            InitializeComponent();
        }

        private void cleanButton_Click(object sender, EventArgs e)
        {
            DatabaseManager.wipeAllNewUsers();
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;

        }

        private void doneButton_Click(object sender, EventArgs e)
        {
            DatabaseManager.insertUser(
                new User(userNameTextBox.Text,
                         passwordTextBox.Text, 
                         firstNameTextBox.Text,
                         lastNameTextBox.Text, 
                         photoURLTextBox.Text));

            DialogResult = DialogResult.OK;
            
        }
    }
}
