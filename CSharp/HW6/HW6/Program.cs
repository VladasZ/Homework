using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;




namespace ConsoleApplication3
{
    enum Value { J = 11, Q, K, A };
    enum Suit { Hearts = '♥', Diamonds, Clubs, Spades }; // ♦♣♠
     
    class Program
    {

        public static int i = 0;
        public static int infiniteGames = 0;
        public static int finiteGames = 0;
      
        static void TestGame(int infinity, int accuracy)
        {
            int[] playersN = { 2, 3, 4, 6, 9, 12, 18, 36 };

            Game.display = false;
                        
            Game.SetInfinity(infinity);

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

             TestGame(10000, 1000);
         
           
            //Game.Play(18);

        }


    }
}