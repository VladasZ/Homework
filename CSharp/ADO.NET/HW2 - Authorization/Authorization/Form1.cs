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
    public partial class AuthorizationForm : Form
    {
        public AuthorizationForm()
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
    }
}
