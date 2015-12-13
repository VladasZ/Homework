using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    static partial class Game
    {
        public static List<Player> players;
        public static List<Card> desk;

        public static bool display;

        static int infinity;

        static Game()
        {
            infinity = 0;
            display = true;
            players = new List<Player>();
            desk = new List<Card>();
        }

        public static void SetInfinity(int inf)
        {
            infinity = inf;
        }

        static int GetMaxCardIndex()
        {
            return desk.IndexOf(desk.Max());
        }

        static int GetMaxCardIndex(List<Card> cards4Check)
        {
            return cards4Check.IndexOf(cards4Check.Max());
        }

        static void SetPlayers(int n)
        {
             for (int i = 0; i < n; ++i)
                players.Add(new Player(i + 1, 36 / n));
        }

        static void Start()
        {

            if (players.Count == 0)
            {
                Console.WriteLine("Для начала игры установите количество игроков");
                return;
            }

            if (players.Count == 1)
            {
                Console.WriteLine("В игре только один игрок. Он победил.");
                return;
            }


        }

        static void Playing()
        {
            while (true)
            {
                if(display)Console.Clear();

                foreach (Player player in players) player.Move();

                if (display)foreach (Card card in desk) card.show();

                //foreach (Player player in players)
                //{
                //    player.showStatus();
                //    player.showCards();
                //}


                Player winner = /*null;// */Disput.Check();

                if (winner != null)
                {
                    winner.TakeDesk();
                }
                else { 


                int maxCardIndex = GetMaxCardIndex();

                players[maxCardIndex].TakeDesk();
                }


                #region BLA
                for (int i = 0; i < players.Count; ++i)
                {
                    if (players[i].cards.Count == 0)// убираем игроков без карт
                    {
                        players.Remove(players[i]);
                        i--;
                        continue;
                    }

                    if (players.Count == 1)
                    {
                        if (display) Console.WriteLine("Победил игрок №" + players[0].n);
                        Program.finiteGames++;
                        return;
                    }
                }




                Program.i++;
                if (Program.i > infinity)
                {
                    Program.i = 0;
                    if (display) Console.WriteLine("Игра бесконечна");
                    Program.infiniteGames++;
                    return;
                }
                #endregion


                if (display) Console.ReadKey(true);
            }
        }

        static void GameOver()
        {
            Deck.ReConstruct();
            players.Clear();
        }

        public static void Play(int numberOfPlayers)
        {
            if ((36 % numberOfPlayers != 0) || 
                (numberOfPlayers > 18 && numberOfPlayers != 36))
            {
                Console.WriteLine("Невеное количество игроков, \nигроки должны полностью забрать колоду из 36-ти карт");
                return;
            }


            SetPlayers(numberOfPlayers);
            Start();
            Playing();
            GameOver();
        }
    }
}
