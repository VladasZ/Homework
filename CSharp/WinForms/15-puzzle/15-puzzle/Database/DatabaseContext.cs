using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _15_puzzle
{
    class DatabaseContext : DbContext
    {
        public DbSet<Gamer> Gamers { get; set; }
        public DbSet<GameResult> GameResults { get; set; }

        public DatabaseContext()
            : base("DBConnectionString")
        {

        }
    }
}
