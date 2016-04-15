using _15_puzzle.Forms;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _15_puzzle
{
    static class GameManager
    {
        public static MainForm mainForm { get; set; } = (MainForm)Application.OpenForms[0];

        public static Bitmap fullImage { get; set; }

        public static List<PuzzlePiece> imagePieces = new List<PuzzlePiece>();

        public static int Difficulty { get; set; } = 3;

        public static DateTime StartTime { get; set; }
        public static TimeSpan GameDuration { get; set; }
        public static int MovesCount { get; set; } = 0;

        public static Random random = new Random();

        private static bool isNotShuffling = true;

        //все картинки будут подгоняться под эту высоту с сохранением пропорций
        const int windowHeight = 500;

        public static void loadImage(string path)
        {
            fullImage = new Bitmap(path);
        }

        public static void loadDefaultImage()
        {
            fullImage = new Bitmap("default.jpg");
        }

        public static void downloadImage(string URL)
        {
            WebRequest request = WebRequest.Create(URL);
            WebResponse response = request.GetResponse();
            Stream responseStream = response.GetResponseStream();

            fullImage = new Bitmap(responseStream);
        }

        public static Size getImageSize()
        {
            float ratio = (float)fullImage.Size.Height / (float)fullImage.Size.Width;

            return new Size((int)(windowHeight / ratio), windowHeight);
        }

        public static void splitImage(int numberOfSideParts)
        {
            int pieceWidth = fullImage.Width / numberOfSideParts;
            int pieceHeight = fullImage.Height / numberOfSideParts;

            int pieceId = 0;

            for (int x = 0; x < numberOfSideParts; x++)
            {
                for (int y = 0; y < numberOfSideParts; y++)
                {
                    PuzzlePiece newPictureBox = new PuzzlePiece()
                    {
                        Image = fullImage.Clone(
                            new Rectangle(x * pieceWidth,
                                            y * pieceHeight,
                                            pieceWidth,
                                            pieceHeight), PixelFormat.DontCare),

                        Location = new Point(x * pieceWidth,
                                                 y * pieceHeight),

                        Size = new Size(pieceWidth, pieceHeight),

                        Position = new Point(x, y),

                        Id = pieceId++                       
                    };

                    mainForm.Controls.Add(newPictureBox);
                    imagePieces.Add(newPictureBox);
                }
            }

            imagePieces.Last().Visible = false;
        }


        public static void pieceClick(object sender, MouseEventArgs e)
        {
            PuzzlePiece piece = (PuzzlePiece)sender;
            // ищем пустую клетку
            PuzzlePiece emptyPiece = imagePieces.Find(p => p.Visible == false);

            Point emptyPiecePosition = emptyPiece.Position;

            //проверяем может ли текущий кусочек двигаться
            if (emptyPiecePosition.X == piece.Position.X + 1 && emptyPiecePosition.Y == piece.Position.Y ||
               emptyPiecePosition.Y == piece.Position.Y - 1 && emptyPiecePosition.X == piece.Position.X ||
               emptyPiecePosition.X == piece.Position.X - 1 && emptyPiecePosition.Y == piece.Position.Y ||
               emptyPiecePosition.Y == piece.Position.Y + 1 && emptyPiecePosition.X == piece.Position.X)
            {
                swapPieces(emptyPiece, piece);

                if(isNotShuffling)
                {
                    MovesCount++;
                }
            }

            if (puzzleIsSolved() && isNotShuffling)
            {
                recordGameResult();
            }
        }

        public static void swapPieces(PuzzlePiece pieceA, PuzzlePiece pieceB)
        {
            Point tempLocation = pieceA.Location;
            pieceA.Location = pieceB.Location;
            pieceB.Location = tempLocation;

            Point tempPosition = pieceA.Position;
            pieceA.Position = pieceB.Position;
            pieceB.Position = tempPosition;

            int tempId = pieceA.Id;
            pieceA.Id = pieceB.Id;
            pieceB.Id = tempId;
        }

        //перемешиваем рандомно вызывая метод клика на кусочек мозайки
        //потому что при обычном перемешиваннии массива могут получиться нерешаемые комбинации
        //на время перемешивания отключаем проверку на победу
        public static void shufflePieces()
        {
            isNotShuffling = false;

            StartTime = DateTime.Now;

            for (int i = 0; i < 1000; i++)
            {
                pieceClick(imagePieces[random.Next(imagePieces.Count)], null);
            }

            isNotShuffling = true;
        }


        //проверяем победил ли игрок
        //каждый кусочек имеет свой Id и если они все идут по порядку то пазл собран
        public static bool puzzleIsSolved()
        {
            int minId = 0;

            foreach(PuzzlePiece piece in imagePieces)
            {
                if(minId++ != piece.Id)
                {
                    return false;
                }
            }
            return true;
        }

        public static void recordGameResult()
        {
            GameDuration = DateTime.Now - StartTime;

            MessageBox.Show("Пазл собран!");

            AddResultForm addResultForm = new AddResultForm();

            addResultForm.ShowDialog();

        }

        public static void endGame()
        {
            imagePieces.Clear();
            MovesCount = 0;
        }

    }
}
