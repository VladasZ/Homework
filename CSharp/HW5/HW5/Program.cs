using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace HW5
{


    class Events
    {
        public static void OnEvent(object sender, ref string status)
        {
            ((Car)sender).setStatus();
            status += "\nМашина #" + ((Car)sender).n + " остановилась. Причина: \n";
        }

        public static void OnOverheat(object sender, ref string status)
        {
            status += "Перегрев двигателя";

        }
        public static void OnFuelEnd(object sender, ref string status)
        {
            status += "Кончилось топливо";
        }
        public static void OnFinish(object sender, ref string status)
        {
            status += "Машина доехала до финиша";
        }


    }

    class Car
    {

        public delegate void eventHnd(object sender, ref string status);

        public event eventHnd onEvent;
       
        #region СВОЙСТВА

        static int N = 0; // переменные для нумерации автомобилей
        public int n {private set; get;}

        public int position { private set; get; } = 0;// координаты автомобиля относительно старта

        string space = " ";// строка с пробелами, увеличивающаяся каждый ход машины для ее сдвига по экрану

        public bool OK { private set; get; } = true; // поле указывающее на то, что машина едет и с ней все в порядке

        int fuel = 500;
        int consumption;
        int temp = 200;

        static Random rand = new Random();

        string status = " ";
        #endregion

        public Car(int cons)// указываем расход топлива при создании автомобиля
        {
            n = N++;// нумеруем автомобиль
            consumption = cons;
        }
        
        public void show()
        {
            Console.WriteLine(space + " ___________");
            Console.WriteLine(space + "|  |     |  |");
            Console.WriteLine(space + "|  |     |  |");
            Console.WriteLine(space + "|__|_____|__|\n");
            Console.WriteLine(status);
        }

        public void setStatus()
        {
            status = "Машина #" + n + " Температура - " + temp/10
                + " Осталось топлива - " + fuel;
        }
        
        public void move()
        {
           

            if (position < 65 &&// не даем машинам выехать за край экрана
                fuel >= 0 + consumption &&// не даем машинам ехать без топлива
                temp <= 1000)//не даем машинам ехать при перегреве
            {
                setStatus();
                fuel -= consumption;
                temp += rand.Next(1, 20);// случайным образом подогреваем все автомобили
                if (n == 2) temp += 10;// специально подогреваем третью машину чтобы вызвать событие
                space += " ";
                position++;
            }
            else
            #region ПОДПИСКА НА СОБИТИЯ
            {
                if (onEvent != null) return;

                OK = false;

                if (position >= 64)
                {
                    onEvent = Events.OnEvent;
                    onEvent += Events.OnFinish;
                    onEvent(this, ref status);
                }
               
                if(fuel <= 0 + consumption)
                {
                    onEvent = Events.OnEvent;
                    onEvent += Events.OnFuelEnd;
                    onEvent(this, ref status);
                }

                if (temp >= 1000)
                {
                    onEvent = Events.OnEvent;
                    onEvent += Events.OnOverheat;
                    onEvent(this, ref status);
                }
            }
            #endregion
        }
    }

    class Track
    {
        static Car[] cars = { new Car(5), new Car(14), new Car(7) };

        public static void show()
        {
            Console.Clear();

            foreach (Car a in cars)
            {
                a.show();               
            }
        }

        public static void race()
        {
            while (true)
            {
                for(int i = 0; i <= cars.Length; ++i)// когда у всех машин сработали события завершаем гонку
                {
                    if (i == cars.Length) return;
                    if (cars[i].OK) break;
                }

                Thread.Sleep(100);

                foreach (Car car in cars)
                    car.move();               

                show();
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            Track.race();           
           
        }
    }
}
