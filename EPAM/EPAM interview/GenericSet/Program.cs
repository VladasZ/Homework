using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenericSet
{
    class TestClass
    {
        public int Value { get; set; }

        public TestClass(int value)
        {
            Value = value;
        }
    }

    class Program
    {
        static Random rand = new Random();

        static void Main(string[] args)
        {
            Set<TestClass> mySet = new Set<TestClass>();
            HashSet<TestClass> systemSet = new HashSet<TestClass>();

            for (int i = 0; i < 10000000; i++)
            {
                TestClass a = new TestClass(rand.Next(0, 100));
                mySet.Add(a);
                systemSet.Add(a);

                TestClass b = new TestClass(rand.Next(0, 100));
                mySet.Remove(b);
                systemSet.Remove(b);
            }

            TestClass[] systemSetArray = systemSet.ToArray();
            Array.Sort(systemSetArray);

            TestClass[] mySetArray = mySet.ToArray();

            Console.WriteLine(systemSetArray.SequenceEqual(mySetArray) ? 
                "test passed" : "test failed");
        }
    }
}
