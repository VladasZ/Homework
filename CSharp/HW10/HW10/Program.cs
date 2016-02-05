using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;


namespace ConsoleApplication6
{
    class Program
    {

        static class PhoneBook
        {
            public static List<string> Numbers { get; set; }


            static PhoneBook()
            {

                Numbers = new List<string>();

            }


            public static void savePhoneBook()
            {
                FileStream file = File.Create("phonebook.txt");
                BinaryFormatter serializer = new BinaryFormatter();
                serializer.Serialize(file, Numbers);
                file.Close();
            }

            public static void openPhoneBook()
            {
                FileStream file = File.OpenRead("phonebook.txt");
                BinaryFormatter deserializer = new BinaryFormatter();
                Numbers = (List<string>)deserializer.Deserialize(file);
            }

            public static void showNumbers()
            {
                foreach (string number in Numbers)
                    Console.WriteLine(number);
            }

            public static void addNumber(string number)
            {
                Numbers.Add(number);
            }


        }

        static class Display
        {

            class Param
            {
             
            }

            static int numberIndex;

            delegate void menuDelegate(ConsoleKeyInfo key, Param param);
            static menuDelegate menu;

            public static void start()
            {
                menu = mainMenu;
                Console.WriteLine("Choose number:");

                for (int i = 1; i <= PhoneBook.Numbers.Count; i++)
                {
                    Console.WriteLine(i + ". " + PhoneBook.Numbers[i - 1]);
                }
            }

            public static void input(ConsoleKeyInfo key)
            {
                menu(key, null);
            }

            static void mainMenu(ConsoleKeyInfo key, Param param)
            {
                Console.Clear();

                Console.WriteLine("Choose number:");

                for (int i = 1; i <= PhoneBook.Numbers.Count; i++)
                {
                    Console.WriteLine(i + ". " + PhoneBook.Numbers[i - 1]);
                }


                if (key.KeyChar >= '0' && key.KeyChar < PhoneBook.Numbers.Count + '0')
                {
                    menu = callMenu;
                    numberIndex = key.KeyChar - '0';
                    menu(key, null);
                }

            }

            static void callMenu(ConsoleKeyInfo key, Param param)
            {
                Console.Clear();
                
                    Console.WriteLine("1." + PhoneBook.Numbers[numberIndex] +
                        "\nEsc - back to main menu");
                    
                if (key.Key == ConsoleKey.Escape)
                {
                    menu = mainMenu;
                    menu(new ConsoleKeyInfo(), null);
                }
                
            }
        }

        static class Menu
        {

        }


        static void Main(string[] args)
        {

            PhoneBook.openPhoneBook();

             Display.start();

             while (true)
              Display.input(Console.ReadKey());
        }
    }
}