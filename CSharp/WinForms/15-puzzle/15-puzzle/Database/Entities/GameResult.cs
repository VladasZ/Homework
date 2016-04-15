using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _15_puzzle
{
    public class GameResult
    {
        public int Id { get; set; }
        public int Moves { get; set; }
        public TimeSpan Time { get; set; }
        public int Difficulty { get; set; }
        public Gamer Gamer { get; set; }
    }
}
