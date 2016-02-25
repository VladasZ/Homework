using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using C3EasyRandom;


namespace FirstDatabase
{
    class Program
    {
        static void Main(string[] args)
        {

            User newUser = new User("peter", 12);

            Console.WriteLine(newUser.name);
        }
    }
}
