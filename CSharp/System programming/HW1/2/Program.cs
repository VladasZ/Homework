using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2
{
    class Program
    {
        static void Main(string[] args)
        {
            Bank bank = new Bank()
            {
                Money = 5000,
                Name = "Super Bank",
                Percent = 100
            };

            bank.Name = "Super Elite Bank";
        }
    }
}
