using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace McDonald_s
{
    class Program
    {
        static List<CashBox> cashBoxes;
        static List<Customer> customers = new List<Customer>();

        static int customersCount;

        static Random rand = new Random();

        static void Main(string[] args)
        {
        }

        static void Init()
        {
            cashBoxes = new List<CashBox>()
            {
                new CashBox(), new CashBox(), new CashBox()
            };

            for (int i = 0; i < customersCount; i++)
            {
                customers.Add(new Customer()
                {
                    ID = i, OrderSize = rand.Next(1, 5)
                });
            }
      
        }
    }
}
