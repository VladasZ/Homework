using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IntSet
{
    class Program
    {
        static Random rand = new Random();

        static void Main(string[] args)
        {
            IntSet mySet = new IntSet();
            HashSet<int> systemSet = new HashSet<int>();

            for (int i = 0; i < 10000000; i++)
            {
                int a = rand.Next(0, 100);
                mySet.Add(a);
                systemSet.Add(a);

                int b = rand.Next(0, 100);
                mySet.Remove(b);
                systemSet.Remove(b);
            }

            int[] systemSetArray = systemSet.ToArray();
            Array.Sort(systemSetArray);

            int[] mySetArray = mySet.ToArray();

            Console.WriteLine(systemSetArray.SequenceEqual(mySetArray) ? 
                "test passed" : "test failed");
        }
    }
}
