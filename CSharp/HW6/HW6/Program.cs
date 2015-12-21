using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Loger;




namespace ConsoleApplication3
{
    enum Value { J = 11, Q, K, A };
    enum Suit { Hearts = '♥', Diamonds, Clubs, Spades }; // ♦♣♠

    static class PlayerShuffle
    {
        public static bool Yes { private set; get; } = true;
        public static bool No { private set; get; } = false;
    }

//#define PLAYER_SHUFFLE_YES true
    
    class Program
    {

        public static int i = 0;
        public static int infiniteGames = 0;
        public static int finiteGames = 0;
      
        static void TestGame(int infinity, int accuracy, bool plShuffle)
        {
            int[] playersN = { 2, 3, 4, 6, 9, 12, 18};

            Game.display = false;
                        
            Game.SetInfinity(infinity);
            Game.plShuffle = plShuffle;

            Console.WriteLine("Игра считается бесконечной после " + infinity + " ходов");

            for (int j = 0; j < playersN.Count(); ++j)
            {

               

                for (int i = 0; i < accuracy; ++i)
                {
                    Game.Play(playersN[j]);
                }

                Console.WriteLine("Для " + playersN[j] + " игроков:");
                Console.Write("Бесконечных игр - " + infiniteGames);
                Console.WriteLine(" Конечных игр - " + finiteGames + "\n");

                infiniteGames = 0;
                finiteGames = 0;
            }

        }

        static void Main(string[] args)
        {

            // TestGame(1000, 1000, PlayerShuffle.Yes); // тест игры со всеми возможыми комбинациями игроков


            Loger.Loger.hi();
            Loger.Loger.init();
            
         
           
            //Game.Play(2);

        }


    }
}