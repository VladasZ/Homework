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
    public partial class UserInfoForm : Form
    {
        User currentUser;

        public UserInfoForm()
        {
            InitializeComponent();
        }

        public UserInfoForm(User user) : this()
        {
            currentUser = user;
        }

        private void UserInfoForm_Load(object sender, EventArgs e)
        {
            firstNameTextBox.Text = currentUser.FirstName;
            lastNameTextBox.Text = currentUser.LastName;
            avatarPictureBox.Load(currentUser.PhotoURL);
        }
    }
}
