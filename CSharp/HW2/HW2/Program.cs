using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// P12014 Vladas Zakrevskis
 
namespace HW2
{
    class Program
    {
        static void Main(string[] args)
        {

           /* Задание 1.Строки
               4.Дана строка текста, в которой слова разделены пробелами. Необходимо:
            -определить количество слов в строке;
            -вычислить, сколько слов в строке имеют минимальную длину;
            -найти в строке слова, которые начинаются с буквы «с» и вывести их на экран.*/

            Console.WriteLine("Задание 1.\n");


            string str = "bla bla bla bl tr mp bl cblalal blalal c2blalal"; //
            //string str = Console.ReadLine(); // раскомментировать для ввода своей строки

            string[] words = str.Split(new char[] { ' ', ',', '.' });

            Console.WriteLine("Количество слов в строке: " + words.Length + '\n');


            int minWordLength = int.MaxValue;

            foreach (string a in words)// ищем длинну минимального слова
            {
                if (a.Length < minWordLength) minWordLength = a.Length;
            }

            Console.WriteLine("Список слов минимальной длинны: ");
            foreach (string a in words)
            {
                if (a.Length == minWordLength)
                    Console.WriteLine(a);
            }

            Console.WriteLine("\nСлова начинающиеся на 'c': ");
            foreach (string a in words)
            {
                if (a[0] == 'c')
                    Console.WriteLine(a);
            }


            Console.WriteLine("\nЗадание 2.\n");


          /*Задание 2.Массивы
                 4.Напишите программу, которая для рваного массива находит номера строк, все элементы которых – нули.*/

            int[][] mass = new int[5][];

            mass[0] = new int[3] { 0, 0, 0 };
            mass[1] = new int[7] { 0, 3, 4, 0, 0, 0, 6 };
            mass[2] = new int[5] { 1, 3, 4, 13, 43 };
            mass[3] = new int[4] { 0, 0, 0, 0 };
            mass[4] = new int[2] { 100, 5555555 };


            for (int i = 0; i < mass.Length; ++i) 
            {
                for (int j = 0; j <= mass[i].Length; ++j) 
                {
                    if(j == mass[i].Length)
                    {
                        Console.WriteLine("Строка номер " + i + " содержит только нули");
                        break;
                    }
                    if (mass[i][j] != 0) break;
                }
            }




        }
    }
}
