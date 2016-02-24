using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Card : IComparable
    {

        public int CompareTo(object card)
        {
            if (this.value < ((Card)card).value) return -1;
            if (this.value > ((Card)card).value ||
            card == null) return 1;
            return 0;
        }

        public Value value;
        private Suit suit;

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

}
