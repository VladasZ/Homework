using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GasStation
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            fuelTypeComboBox.DataSource = DataSource.fuelTypes;
            fuelTypeComboBox.DisplayMember = "fuelType";
            fuelTypeComboBox.ValueMember = "price";

            fuePerLiterlPriceTextBox.Text = fuelTypeComboBox.SelectedValue.ToString();
        }

        private void fuelTypeComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            fuePerLiterlPriceTextBox.Text = ((ComboBox)sender).SelectedValue.ToString();
        }



   
    }
}
