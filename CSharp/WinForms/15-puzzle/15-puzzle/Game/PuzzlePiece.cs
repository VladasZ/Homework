using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _15_puzzle
{
    class PuzzlePiece : PictureBox
    {
        public Point Position { get; set; }

        public int Id { get; set; }

        public PuzzlePiece() : base()
        {
            MouseClick += GameManager.pieceClick;
        }

    }
}
