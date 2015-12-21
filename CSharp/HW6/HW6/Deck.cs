using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    static class Deck
    {
        public static List<Card> cards = new List<Card>();
        static Deck()
        {
             for (int i = 3; i <= 6; ++i)
            for (int j = 6; j <= (int)Value.A; ++j)
                cards.Add(new Card((Value)j, (Suit)i  /* Suit.Diamonds)*/ ));


            shuffle(cards);
            

        }

        public static void ReConstruct()
        {
            cards.Clear();

            for (int i = 3; i <= 6; ++i)
                for (int j = 6; j <= (int)Value.A; ++j)
                    cards.Add(new Card((Value)j, (Suit)i  /* Suit.Diamonds)*/ ));


            shuffle(cards);
        }

        public static void shuffle(List<Card> _cards)
        {
            Random rand = new Random(DateTime.Now.Millisecond);

            for (int i = 0; i < 1000; ++i)
            {
                int a = rand.Next(0, _cards.Count), b = rand.Next(0, _cards.Count);

                Card temp = _cards[a];
                _cards[a] = _cards[b];
                _cards[b] = temp;
            }
        }

        public static void shuffle(List<Card> _cards, int iterations)
        {
            Random rand = new Random(DateTime.Now.Millisecond);

            for (int i = 0; i < iterations; ++i)
            {
                int a = rand.Next(0, _cards.Count), b = rand.Next(0, _cards.Count);

                Card temp = _cards[a];
                _cards[a] = _cards[b];
                _cards[b] = temp;
            }
        }


        public static void show()
        {
            foreach (Card a in cards)
                a.show();
        }
    }
}
