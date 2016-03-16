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

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DatabaseManager.insertUser(new User("146100", "12345678", "Vladas", "Zakrevskis", "http://cs317019.vk.me/v317019207/9726/UHafxj2-ueQ.jpg"));
            DialogResult = DialogResult.OK;
        }
    }
}
