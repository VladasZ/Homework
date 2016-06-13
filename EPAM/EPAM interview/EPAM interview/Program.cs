using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EPAM_interview
{
    class BinarySearch
    {
        static int arraySize = 1000;
        static int[] testArray = new int[arraySize];
        static Random rand = new Random();

        static int Find(int[] array, int number)
        {
            int leftLimit = 0;
            int rightLimit = array.Count() - 1;
            int middle = (leftLimit + rightLimit) / 2;

            while (array[middle] != number)
            {
                if (array[middle] < number)
                    leftLimit = middle + 1;

                else
                    rightLimit = middle - 1;
                 
                //number not found
                if (leftLimit > rightLimit)
                    return 0;

                middle = (leftLimit + rightLimit) / 2;
            }
            return array[middle];
        }

        static bool Test(int testsCount)
        {

            while(--testsCount > 0)
            {
                int testNumber = 
                    rand.Next(testArray.First() - 100, testArray.Last() + 100);

                if (Array.Find(testArray, n => n == testNumber) !=
                    Find(testArray, testNumber))
                    return false;
            }
            return true;
        }

        static void Main(string[] args)
        {
            for (int i = 0; i < testArray.Count(); i++)
                testArray[i] = i + 100;

            Console.WriteLine(Test(1000) ? "test passed" : "test failed");
        }
    }
}
