using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// P12014 Vladas Zakrevskis
/*5.	Разработать приложение, в котором бы сравнивалось население трех столиц из разных стран. 
Причем страна бы обозначалась пространством имен, а город – классом в данном пространстве.*/

namespace Belarus
{
    class Minsk
    {
        static int population = 1937900;
        public static void show()
        {
            Console.WriteLine("Население Минска - " + population);
        }
    }
}

namespace Ukraine
{
    class Kiev
    {
        static int population = 2888470;
        public static void show()
        {
            Console.WriteLine("Население Киева - " + population);
        }
    }
}

namespace Russia
{
    class Moscow
    {
        static int population = 12197596;
        public static void show()
        {
            Console.WriteLine("Население Москвы - " + population);
        }
    }
}


namespace N5
{
    class Program
    {
        static void Main(string[] args)
        {
            Belarus.Minsk.show();
            Ukraine.Kiev.show();
            Russia.Moscow.show();
        }
    }
}
