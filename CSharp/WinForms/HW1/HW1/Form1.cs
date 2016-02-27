using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using C3EasyRandom;

namespace HW1
{
    public partial class modelTextBox : Form
    {
        List<Smartphone> smartphones;

        public modelTextBox()
        {
            InitializeComponent();
        }

        public void init()
        {
            smartphones = DataManager.getSmartphones();
            phonesListBox.DataSource = smartphones;
            phonePictureBox.Image = smartphones.First().image;

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            init();
        }

        private void phonesListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            Smartphone selectedPhone = smartphones[phonesListBox.SelectedIndex];

            phonePictureBox.Image = selectedPhone.image;
            manufacturerTextBox.Text = selectedPhone.manufacturer;
            modelTextBox_.Text = selectedPhone.model;
            osTextBox.Text = selectedPhone.os;
            cpuTextBox.Text = selectedPhone.cpu;
            priceTextBox.Text = selectedPhone.price.ToString();

            manufacturerEditBox.Text = selectedPhone.manufacturer;
            modelEditBox.Text = selectedPhone.model;
            osEditBox.Text = selectedPhone.os;
            cpuEditBox.Text = selectedPhone.cpu;
            priceEditBox.Text = selectedPhone.price.ToString();
            photoEditBox.Text = selectedPhone.imageURL;

        }

        private void cleanButton_Click(object sender, EventArgs e)
        {
            manufacturerEditBox.Clear();
            modelEditBox.Clear();
            modelEditBox.Clear();
            osEditBox.Clear();
            cpuEditBox.Clear();
            priceEditBox.Value = 0;
            photoEditBox.Clear();

        }

        private void saveInfoButton_Click(object sender, EventArgs e)
        {
            Smartphone selectedPhone = smartphones[phonesListBox.SelectedIndex];

            selectedPhone.manufacturer = manufacturerEditBox.Text;
            selectedPhone.model = modelEditBox.Text;
            selectedPhone.cpu = cpuEditBox.Text;
            selectedPhone.os = osEditBox.Text;
            double.TryParse(priceEditBox.Text, out selectedPhone.price);
            selectedPhone.imageURL = photoEditBox.Text;
            selectedPhone.image = 
                DataManager.downloadImage(selectedPhone.imageURL);



            phonesListBox_SelectedIndexChanged(null, null);
        }
    }
}
