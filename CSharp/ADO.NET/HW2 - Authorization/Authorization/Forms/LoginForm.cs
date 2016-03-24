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
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
            StartPosition = FormStartPosition.CenterScreen;
        }

        private void registrationButton_Click(object sender, EventArgs e)
        {
            RegistrationForm registratoonForm = new RegistrationForm();
            registratoonForm.StartPosition = FormStartPosition.CenterParent;
            registratoonForm.ShowDialog();
        }

        private void logInButton_Click(object sender, EventArgs e)
        {
            User currentUser = DatabaseManager.logIn(userNameTextBox.Text, passwordTextBox.Text);

            if(currentUser == null)
            {
                MessageBox.Show("Wrong password or username!");
                return;
            }

            UserInfoForm userInfoForm = new UserInfoForm(currentUser);
            userInfoForm.StartPosition = FormStartPosition.CenterParent;
            userInfoForm.ShowDialog();
        }

        private void LoginForm_Enter(object sender, EventArgs e)
        {
            User currentUser = DatabaseManager.logIn(userNameTextBox.Text, passwordTextBox.Text);

            if (currentUser == null)
            {
                MessageBox.Show("Wrong password or username!");
                return;
            }

            UserInfoForm userInfoForm = new UserInfoForm(currentUser);
            userInfoForm.StartPosition = FormStartPosition.CenterParent;
            userInfoForm.ShowDialog();
        }
    }
}
