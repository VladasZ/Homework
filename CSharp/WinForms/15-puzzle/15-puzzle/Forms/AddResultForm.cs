using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Entity;

using System.Data.Linq;
using System.Linq;

using System.Drawing;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _15_puzzle.Forms
{
    public partial class AddResultForm : Form
    {
        public AddResultForm()
        {
            InitializeComponent();

            StartPosition = FormStartPosition.CenterParent;

            movesCountLabel.Text = GameManager.MovesCount.ToString();
            gameDurationLabel.Text = GameManager.GameDuration.Seconds + " сек.";
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            GameResult newResult = new GameResult()
            {
                Difficulty = GameManager.Difficulty,
                Moves = GameManager.MovesCount,
                Time = GameManager.GameDuration
            };


            Gamer gamer = (from g in DatabaseManager.context.Gamers
                           where g.Name == nameTextBox.Text
                           select g).FirstOrDefault();

            if (gamer == null)
            {
                gamer = new Gamer()
                {
                    Name = nameTextBox.Text
                };

                gamer.GameResults.Add(newResult);

                DatabaseManager.context.Gamers.Add(gamer);

                DatabaseManager.context.SaveChanges();

                DialogResult = DialogResult.OK;

                return;
            }



            DatabaseManager.context.GameResults.Add(newResult);

            gamer.GameResults.Add(newResult);


            DatabaseManager.context.SaveChanges();

            DialogResult = DialogResult.OK;
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
        }
    }
}
