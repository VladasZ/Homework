using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Windows.Forms;

namespace MessageSender
{
    public partial class AddUserForm : Form
    {
        UserType newUserType;
        MainForm mainForm;

        public AddUserForm()
        {
            InitializeComponent();
        }

        public AddUserForm(string userType) : this()
        {
            switch (userType)
            {
                case "CloserRelatives":
                    newUserType = UserType.CloserRelatives;
                    break;
                case "FarRelatives":
                    newUserType = UserType.FarRelatives;
                    break;
                case "Department":
                    newUserType = UserType.Department;
                    break;
                case "Company":
                    newUserType = UserType.Company;
                    break;
                case "BestFriends":
                    newUserType = UserType.BestFriends;
                    break;
                case "Teammates":
                    newUserType = UserType.Teammates;
                    break;

                default:
                    MessageBox.Show("Error. Unknown user type");
                    break;
            }

            mainForm = (MainForm)Application.OpenForms[0];
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            MailAddress userMailAddress;

            try
            {
                if (string.IsNullOrEmpty(emailTextBox.Text))
                {
                    throw new FormatException();
                }

                userMailAddress = new MailAddress(emailTextBox.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Неверный формат электронной почты", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            User newUser = new User(DataManager.lastUserID++, nameTextBox.Text, userMailAddress, newUserType);

            DataManager.Users.Add(newUser);

            mainForm.MainTreeView.SelectedNode.Nodes.Add(newUser.Name);

            DialogResult = DialogResult.OK;
        }


    }
}
