using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// P12014 Vladas Zakrevskis
/*
3.	Разработать метод для решения системы 2 линейных уравнений:
    A1*x + B1*y = 0
    A2*x + B2*y = 0
    Метод с помощью выходных параметров должен возвращать найденной решение или генерирует исключение ArgumentOutOfRangeException, если решение не существует. 
*/

namespace N3
{

    class SysLinEq
    {
        static double a1, b1, c1; 
        static double a2, b2, c2;

        public static void solve(out double x, out double y)
        {
            

            Console.WriteLine("Решаем систему уравнений вида:\n");
            Console.WriteLine("A1*x + B1*y = C1\nA2*x + B2*y = C2\n");

            Console.Write("Введите A1 = ");
            a1 = double.Parse(Console.ReadLine());
            Console.Write("Введите B1 = ");
            b1 = double.Parse(Console.ReadLine());
            Console.Write("Введите C1 = ");
            c1 = double.Parse(Console.ReadLine());
            Console.Write("Введите A2 = ");
            a2 = double.Parse(Console.ReadLine());
            Console.Write("Введите B2 = ");
            b2 = double.Parse(Console.ReadLine());
            Console.Write("Введите C2 = ");
            c2 = double.Parse(Console.ReadLine());

            if (a1 == a2 && b1 == b2 && c1 == c2)// если вводим 2 одинаковых уравнения, решением будет функция
            {
                x = y = 0;
                Console.WriteLine("\nСистема уравнений\n");
                Console.WriteLine(a1 + "*x + " + b1 + "*y = " + c1 + "\n" + a2 + "*x + " + b2 + "*y = " + c2 + "\n");
                Console.WriteLine("Имеет следущее решение:\n\n" + "x = (" + c1 + " - " + b1 + "*y) / " + a1 );
                return;
            }

            if (a1 == a2 && b1 == b2 && c1 != c2) throw new ArgumentOutOfRangeException("Нет решений");// при одинаковых коэффициентах прямые не пересекаются
                                                                                                        // следовательно решений нет

            y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);// формулы выводил на листочке
            x = (c1 - b1 * y) / a1;


            Console.WriteLine("\nСистема уравнений\n");
            Console.WriteLine(a1 + "*x + " + b1 + "*y = " + c1 + "\n" + a2 + "*x + " + b2 + "*y = " + c2 +"\n");

            Console.WriteLine("Имеет следущее решение:\n\n" + "x = " + x + " y = " + y);
                       

        }

    }

    class Program
    {
       

        static void Main(string[] args)
        {
            double x, y;

            try {
                SysLinEq.solve(out x, out y);
            }
            catch (ArgumentOutOfRangeException error)
            {
                Console.WriteLine(error.Message);
            }
            



        }
    }
}
