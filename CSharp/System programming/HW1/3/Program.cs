using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _3
{
    class Program
    {
        static Random rand = new Random();


        static void Main(string[] args)
        {

            while (true)
            {
                Thread playThread = new Thread(new ThreadStart(play));

                playThread.Start();

                playThread.Join();
            }
        }

        static void play()
        {
            //отправляем сообщение через случайный промежуток времени
            Thread.Sleep(rand.Next(3000, 5000));

            TimeSpan startTime = DateTime.Now.TimeOfDay;
            Console.WriteLine("Жми!");

            Console.ReadKey();
            TimeSpan pressTime = DateTime.Now.TimeOfDay - startTime;

            Console.WriteLine("Скорость реакции - " + pressTime.TotalMilliseconds + " милисекунд");
        }
    }
}
