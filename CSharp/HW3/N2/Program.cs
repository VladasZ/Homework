using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// P12014 Vladas Zakrevskis
/*2.	Разработать собственный класс для хранения целочисленных коэффициентов А и В линейного уравнения A*X + B*Y = 0. 
В классе реализовать статический метод Parse, которые принимает строку со значениями коэффициентов, разделенных запятой или пробелом. 
В случае передачи в метод строки недопустимого формата генерируется исключение FormatException.*/

namespace N2
{

    class Equation
    {
        public int A {set; get;}
        public int B {set; get;}

        public Equation(string data)
        {

            string[] coefficients;

            try
            {
                foreach (char a in data)
                    if (char.IsLetter(a))
                        throw new FormatException("Недопустимые символы");

                coefficients = data.Split(',', ' ');

                if (coefficients.Length != 2)
                    throw new FormatException("Неправильное количество аргументов");

            }
            catch (FormatException error)
            {
                Console.WriteLine("Ошибка при обработке строки: \"" + data + "\" - " + error.Message);
                return;
            }

            A = int.Parse(coefficients[0]);
            B = int.Parse(coefficients[1]);

            Console.WriteLine("Коэффициенты успешно сохранены");


        }

        public void show()
        {
            Console.WriteLine(A + "*x + " + B + "*y = 0\n");
        }


    }

    class Program
    {
        static void Main(string[] args)
        {
            Equation eq1 = new Equation("543 bla");
            eq1.show();

            Equation eq2 = new Equation("543 765 5435");
            eq2.show();

            Equation eq3 = new Equation("100");
            eq3.show();

            Equation eq4 = new Equation("543 765");
            eq4.show();

            Equation eq5 = new Equation("11543,7465");
            eq5.show();



        }
    }
}
