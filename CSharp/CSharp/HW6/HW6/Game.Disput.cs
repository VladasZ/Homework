using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    static partial class Game
    {
        static class Disput
        {
            static Player Disputing(List<Player> disputers)
            {
                List<Card> disputDesk = new List<Card>();

                foreach (Player player in disputers)
                    player.Move(disputDesk);

                if (disputers.Count == 0) return null;

                int maxCardIndex = GetMaxCardIndex(disputDesk);

                if (maxCardIndex < 0) return null;

                disputers[maxCardIndex].TakeDesk(disputDesk);
                               


                return disputers[maxCardIndex];
            }

            static Player StartDisput(Card MaxCard)
            {
                List<Player> disputers = new List<Player>();

                for (int i = 0; i < desk.Count; ++i)
                {
                    if (desk[i].value == MaxCard.value)
                        disputers.Add(players[i]);
                }

                return Disputing(disputers);
            }

            public static Player Check()
            {
                Card MaxCard = desk.Max();

                List<Card> MaxCards = new List<Card>();
                MaxCards.Add(MaxCard);

                foreach (Card card in desk)
                {
                    if (card.value == MaxCard.value && card != MaxCard)
                    {
                        MaxCards.Add(card);
                    }
                }

                if (MaxCards.Count > 1)
                {
                    //Console.WriteLine("----");
                    //MaxCard.show();
                    //Console.WriteLine("----");
                    return StartDisput(MaxCard);
                }

                return null;
            }
        }
    }
}
