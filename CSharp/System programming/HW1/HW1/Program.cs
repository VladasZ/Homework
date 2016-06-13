using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace HW1
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rand = new Random();

            List<int> array = new List<int>()
            {
                442134132, 412341234, 412341234, 63456543, 64356435, 63456435
            };

            Thread thread = new Thread(new ParameterizedThreadStart(showArray));

            thread.Start(array);
        }

        static void showArray(object array)
        {
            foreach (int a in (IEnumerable<int>)array)
                Console.WriteLine(a.ToString());
        }
    }
}
