using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _15_puzzle
{
    static class DatabaseManager
    {
        public static DatabaseContext context = new DatabaseContext();

        public static List<string> getRecords()
        {
            List<string> records = new List<string>();

            foreach(Gamer gamer in context.Gamers)
            {
                foreach(GameResult result in gamer.GameResults)
                {
                    string resultString = result.Gamer.Name + " " + result.Moves + " ходов, " + result.Time.Seconds + " сек.";

                    records.Add(resultString);
                }

                MessageBox.Show(gamer.Name);

            }

            return records;
        }

        public static Gamer findGamer(string name)
        {
           return (from g in context.Gamers
                   where g.Name == name
                   select g).FirstOrDefault();
        }

        public static void addResult(GameResult result, string name)
        {
            Gamer gamer = findGamer(name);

            if (gamer == null)
            {
                gamer = new Gamer()
                {
                    Name = name,
                    GameResults = new List<GameResult>() { result }
                };

                context.Gamers.Add(gamer);

                context.SaveChanges();

                return;
            }

            gamer.GameResults.Add(result);

            context.SaveChanges();
        }
    }
}
