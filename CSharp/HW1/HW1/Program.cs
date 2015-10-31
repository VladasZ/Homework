using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace HW1
{
    class Program
    {
        static ulong fib(int n)
        {
            if (n == 1 || n == 2) return 1;

            ulong result = 0, current = 1, prev = 0;

            for(int i = 0; i<n; ++i)
            {

                result = current + prev;
                prev = current;
                current = result;
            }

            return result;
        }

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
            Console.WriteLine("Задание 7: Введите число");

            string str = Console.ReadLine();
            char[] temp = str.ToCharArray();

            int a = temp.Max() - '0';
            int b = temp.Min() - '0';

            Console.WriteLine("Max - " + a + " Min - " + b);

        }

        static void N8()
        {
            ulong result = 0;

            for(int i = 1; i<50; ++i)
            {
                result += fib(i);
            }

            Console.WriteLine(result);

        }

        static void N9()
        {


            int e = 10; // точность
            double x = 0.4;
            double result = -x;
            double addition = x*x/2;
            int iter = 2;
        
            for(; addition > 1/Math.Pow(10,e);++iter)
            {
                result -= addition;
                addition *= x*iter/(iter+1);
            }

            Console.WriteLine("Ряд тейлора:               " + result);

            Console.WriteLine("Математическая функция     " + Math.Log(1 - x));
            Console.WriteLine("Количество слагаемых требуемое для заданной точности: " + iter);



        }

        static void Main(string[] args)
        {
            //N1();
            //N2();
            //N3();
            //N4();
            //N6();
            //N7();
            //N8();
            N9();

        }
    }
}
