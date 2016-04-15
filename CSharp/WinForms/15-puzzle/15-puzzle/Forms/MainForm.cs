using _15_puzzle.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _15_puzzle
{
    public partial class MainForm : Form
    {
        Graphics graphics;

        public MainForm()
        {
            InitializeComponent();

            StartPosition = FormStartPosition.CenterScreen;

            graphics = CreateGraphics();
        }

        private void MainForm_Shown(object sender, EventArgs e)
        {
            //MessageBox.Show("Для начала игры выберите картинку в меню");
        }

        private void defaultImageMenu_Click(object sender, EventArgs e)
        {
            try
            {
                GameManager.loadDefaultImage();
                
            }
            catch (ArgumentException)
            {
                MessageBox.Show("Стандартная картинка не найдена!");
            }

            this.Size = GameManager.getImageSize();

            graphics.DrawImage(GameManager.fullImage, new Rectangle(new Point(0, 0), this.Size));
        }

        private void openMenu_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            openFileDialog.Filter = "Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF";

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                GameManager.loadImage(openFileDialog.FileName);

                this.Size = GameManager.getImageSize();

                graphics.DrawImage(GameManager.fullImage, new Rectangle(new Point(0, 0), this.Size));
            } 
        }

        private void openURLMenu_Click(object sender, EventArgs e)
        {
            GameManager.downloadImage(imageURLTextBoxMenu.Text);

            this.Size = GameManager.getImageSize();

            graphics.DrawImage(GameManager.fullImage, new Rectangle(new Point(0, 0), this.Size));
        }

        private void shuffleMenu_Click(object sender, EventArgs e)
        {
            if(GameManager.fullImage == null)
            {
                MessageBox.Show("Сначала выберите картинку");
                return;
            }

            GameManager.splitImage(2);
            
            graphics.Clear(Color.White);

            GameManager.shufflePieces();

        }


        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("fdsf");

        }

        private void toolStripComboBox1_Click(object sender, EventArgs e)
        {

        }

        private void clearForm(object sender, EventArgs e)
        {

            List<Control> controlsToRemove = new List<Control>();

            foreach(Control control in Controls)
            {
                if(control.GetType() == typeof(PuzzlePiece))
                {
                    controlsToRemove.Add(control);
                }
            }

            foreach(Control control in controlsToRemove)
            {
                Controls.Remove(control);
            }


            GameManager.imagePieces.Clear();
        }

        private void recordsMenu_Click(object sender, EventArgs e)
        {
            RecordsTableForm recordsForm = new RecordsTableForm();

            recordsForm.ShowDialog();
        }

        private void gfdgfdToolStripMenuItem_Click(object sender, EventArgs e)
        {
        
        }
    }
}
