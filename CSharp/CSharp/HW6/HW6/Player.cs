using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Player
    {
        public int n { private set; get; }

        public List<Card> cards { private set; get; }

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
            Console.Write(" Имеет " + cards.Count + " карт\n");
        }

        public void showCards()
        {
            foreach (Card card in cards)
                card.show();
        }

        public void Move()
        {
            Game.desk.Add(cards[0]);
            cards.RemoveAt(0);
        }

        public void Move(List<Card> specialDesk)
        {
            if (cards.Count == 0) return;

            Deck.shuffle(cards);

            specialDesk.Add(cards[0]);
            cards.RemoveAt(0);
        }

        public void TakeDesk()
        {
            foreach (Card card in Game.desk)
                cards.Add(card);

            Game.desk.Clear();
        }

        public void TakeDesk(List<Card> specialDesk)
        {
            foreach (Card card in specialDesk)
                cards.Add(card);

            specialDesk.Clear();
        }




    }
}
