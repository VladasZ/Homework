using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;




namespace ConsoleApplication3
{
    enum Value { J = 11, Q, K, A };
    enum Suit { Hearts = '♥', Diamonds, Clubs, Spades }; // ♦♣♠


    class Card : IComparable
    {

        public int CompareTo(object card)
        {
            if (this.value < ((Card)card).value) return -1;
            if (this.value > ((Card)card).value ||
            card == null) return 1;
            return 0;
        }

        Value value;
        Suit suit;

        public Card(Value value, Suit suit)
        {
            if (value < (Value)6) value = (Value)6;
            if (value > Value.A) value = Value.A;
            this.value = value;
            this.suit = suit;
        }

        public void show()
        {
            Console.Write(value + " ");
            if (value != (Value)10) Console.Write(' ');
            Console.Write((char)suit + "\n");

        }

        public override string ToString()
        {
            return value.ToString();
        }

    }

    static class Deck
    {
        public static List<Card> cards = new List<Card>();
        static Deck()
        {
            for (int i = 3; i <= 6; ++i)
                for (int j = 6; j <= (int)Value.A; ++j)
                    cards.Add(new Card((Value)j, (Suit)i));


            shuffle();


            // cards.Add(new Card((Value)6, Suit.Diamonds));
            // cards.Add(new Card(Value.A, Suit.Diamonds));


        }

        public static void ReConstruct()
        {
            cards.Clear();

            for (int i = 3; i <= 6; ++i)
                for (int j = 6; j <= (int)Value.A; ++j)
                    cards.Add(new Card((Value)j, (Suit)i));


            shuffle();
        }

        static void shuffle()
        {
            Random rand = new Random(DateTime.Now.Millisecond);

            for (int i = 0; i < 100000; ++i)
            {
                int a = rand.Next(0, 36), b = rand.Next(0, 35);

                Card temp = cards[a];
                cards[a] = cards[b];
                cards[b] = temp;
            }
        }
        public static void show()
        {
            foreach (Card a in cards)
                a.show();
        }
    }
    
    class Player
    {
        public int n;

        public List<Card> cards;

        public Player(int n, int cardsNumber)
        {
            cards = new List<Card>();
            
            this.n = n;

            for (int i = 0; i < cardsNumber; ++i)
            {
                cards.Add(Deck.cards[0]);
                Deck.cards.RemoveAt(0);
            }
        }

        public void showStatus()
        {
            Console.Write("Игрок №" + n /*+ "\nКарты:\n"*/);
            Console.Write( " Имеет " + cards.Count + " карт\n");

            foreach (Card card in cards)
                card.show();   

        }

        public void Move()
        {
            Game.desk.Add(cards[0]);
            cards.RemoveAt(0);
        }

        public void TakeDesk()
        {
            foreach (Card card in Game.desk)
                cards.Add(card);

            Game.desk.Clear();
        }



    }

    static class Game
    {
        public static List<Player> players;
        public static List<Card> desk;

        static Game()
        {

            players = new List<Player>();
            desk = new List<Card>();
        }


         static void SetPlayers(int n)
        {
            if (36 % n != 0)
            {
                Console.WriteLine("Невеное количество игроков, \nигроки должны полностью забрать колоду из 36-ти карт");
                return;
            }


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
           // Console.Clear();


            foreach (Player player in players) player.Move();

           // foreach (Card card in desk) card.show();
           
            int maxCard = desk.IndexOf(desk.Max());

            players[maxCard].TakeDesk();

            for (int i = 0; i < players.Count; ++i)
            {
                if (players[i].cards.Count == 0)// убираем игроков без карт
                {
                    players.Remove(players[i]);
                    i--;
                    continue;
                }

                if (players[i].cards.Count == 36)
                {
                   // Console.WriteLine("Победил игрок №" + players[i].n);
                    Program.finiteGames++;
                    return;
                }
            }




            Program.i++;
            if (Program.i > 1000)
            {
                Program.i = 0;
                Program.infiniteGames++;
                return;
            }

            //Console.ReadKey(true);
        }
    }

         static void GameOver()
        {
            Deck.ReConstruct();
            players.Clear();          
        }

         public static void Play(int numberOfPlayers)
        {
            SetPlayers(numberOfPlayers);
            Start();
            Playing();
            GameOver();
        }
    }

    class Program
    {

        public static int i = 0;
        public static int infiniteGames = 0;
        public static int finiteGames = 0;

        static void TestGame()
        {
            int[] playersN = { 2, 3, 4, 6, 9, 12, 18, 36 };


            for (int j = 0; j < playersN.Count(); ++j)
            {


                for (int i = 0; i < 1000; ++i)
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



            TestGame();

        }


    }
}