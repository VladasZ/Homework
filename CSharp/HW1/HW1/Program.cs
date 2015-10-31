using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace HW1
{
    class Program
    {

        static void N1()
        {
            Console.WriteLine("Задание 1: Введите 2 числа");

            int a, b;

            do
            {
                a = int.Parse(Console.ReadLine());
                b = int.Parse(Console.ReadLine());

                if (a > b)
                    Console.WriteLine("Первое число должно быть меньше второго");
            }
            while (a > b);
            
            for(int i = a; i <= b; ++i)
               for(int j = 0; j < i; ++j)
                    Console.WriteLine(i);
        }

        static void N2()
        {
            Console.WriteLine("Задание 2: Введите количество строк");

            int n = int.Parse(Console.ReadLine());

            for (int i = 0 ; i < n; ++i)
            {
                for(int j = 0; j < 5; ++j)
                {
                    Console.Write((char)('A' + j + i));
                }
                Console.WriteLine();
            }

        }

        static void N3()
        {
            Console.WriteLine("Задание 3: Введите число");

            string a = Console.ReadLine();
            char[] temp = a.ToCharArray();
            Array.Reverse(temp);
            string b = new string(temp);


            if (a == b)
                Console.WriteLine("Число является перевертышем");
            else
                Console.WriteLine("Число не является перевертышем");

        }

        static void N4()
        {
            Console.WriteLine("Задание 4: Введите значение");

            string a = Console.ReadLine();

            switch (a)
            {
                case "вперед":
                case "следующий":
                  Console.WriteLine("Значение входит в список");
                    break;
                default:
                    Console.WriteLine("Значение не входит в список");
                break;
            }

        }

        static void N6()
        {
            Console.WriteLine("Задание 6:");

            for (double i = -5; i <= 5; i += (5+5)/11D )
                Console.WriteLine(i*i+2*i-3);

        }

        static void N7()
        {

        }

        static void Main(string[] args)
        {
            //N1();
            //N2();
            //N3();
            //N4();
            N6();


        }
    }
}
