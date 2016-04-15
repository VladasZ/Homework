using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _15_puzzle.Forms
{
    public partial class RecordsTableForm : Form
    {
        public RecordsTableForm()
        {
            InitializeComponent();

            StartPosition = FormStartPosition.CenterParent;

            listBox.DataSource = DatabaseManager.getRecords();
        }
    }
}
