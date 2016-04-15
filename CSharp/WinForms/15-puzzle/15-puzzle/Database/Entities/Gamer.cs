using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _15_puzzle
{
    public class Gamer
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public List<GameResult> GameResults { get; set; } 
    }
}
