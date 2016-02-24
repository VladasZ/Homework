using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using System.Threading;
using System.Timers;

namespace Exam
{

    struct Point
    {
        public float x;
        public float y;

        public Point(float x, float y)
        {
            this.x = x;
            this.y = y;
        }

        public override bool Equals(object obj)
        {
            return x == ((Point)obj).x && y == ((Point)obj).y;
        }

        public static bool operator ==(Point a, Point b)
        {
            return (int)a.x == b.x && (int)a.y == b.y;
        }

        public static bool operator !=(Point a, Point b)
        {
            return a.x != b.x || a.y != b.y;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

    }

    static class Display
    {
        const int DisplayWidth = 70;
        const int DisplayHeight = 20;
        const int DistanceToDestination = 20;
        const int MaxAltitude = 8000;

        public const int DisplayRefreshRate = 50;

        static Timer displayRefreshTimer = new Timer(DisplayRefreshRate);

        public static void init()
        {
            displayRefreshTimer.Elapsed += display;
            displayRefreshTimer.Start();
        }

        public static void display(Object source, ElapsedEventArgs e)
        {
            Console.Clear();
            Console.WriteLine("Speed: " + Plane.speed +
                              "\nPitch: " + Plane.pitch +
                              "\nAltitude: " + Plane.coordinates.y +
                              "\nPosition: " + Plane.coordinates.x);


            for (int i = 0; i <= DisplayHeight; i++)
            {
                for (int j = 0; j <= DisplayWidth; j++)
                {
                    if (Plane.coordinates == new Point(j, i))
                    {
                        Console.SetCursorPosition(j, DisplayHeight - i);
                        Console.WriteLine(">->");
                    }

                }
            }

            Console.SetCursorPosition(0, 21);
            Plane.flyThreadMethod();

        }

        public static void input(ConsoleKeyInfo key)
        {
            if (key.Key == ConsoleKey.RightArrow)
            {
                Plane.speed += 50;
            }
            if (key.Key == ConsoleKey.LeftArrow && Plane.speed >= 50)
            {
                Plane.speed -= 50;
            }
            if (key.Key == ConsoleKey.UpArrow)
            {
                Plane.pitch += 50;
            }
            if (key.Key == ConsoleKey.DownArrow)
            {
                Plane.pitch -= 50;
            }
        }
    }

    class Dispatcher
    {
        float weatherCorrective;
        float currentCorrective;
        public int penalties;

        Timer penaltyTickTimer;

        string name;

        static Random rand = new Random();

        public Dispatcher(string name)
        {
            weatherCorrective = (float)rand.Next(-200, 200) / 200;
            penalties = 0;
            this.name = name;
            penaltyTickTimer = new Timer(1000);
            penaltyTickTimer.Elapsed += setPenalties;
            penaltyTickTimer.Start();

        }

        void setPenalties(Object source, ElapsedEventArgs e)
        {
            if (Plane.coordinates.y + 4 < currentCorrective ||
                Plane.coordinates.y - 4 > currentCorrective)
                penalties += 50;
            else if (Plane.coordinates.y + 2 < currentCorrective ||
                Plane.coordinates.y - 2 > currentCorrective)
                penalties += 25;

        }

        public void controlFlight(Point coordinates, int speed)
        {

            if (penalties >= 1000)
            {
                Console.WriteLine(name + " Pilot is not suitable for flying");
                return;
            }


            currentCorrective = speed * ((float)20 / (float)10000) - weatherCorrective;
            Console.Write(name + " - required altitude:" + currentCorrective + " ");


            if (Plane.coordinates.y + 4 < currentCorrective)
                Console.Write(" higher plane immediately! ");

            else if (Plane.coordinates.y - 4 > currentCorrective)
                Console.Write(" lower plane immediately! ");

            else if (Plane.coordinates.y + 2 < currentCorrective)
                Console.Write(" too low ");

            else if (Plane.coordinates.y - 2 > currentCorrective)
                Console.Write(" too high ");

            


            Console.Write("Penalties:" + penalties);
            Console.WriteLine();
        }

    }

    static class Plane
    {
        public static int speed = 0;
        public static float pitch = 0; 
        public static Point coordinates = new Point(0, 0);

        static List<Dispatcher> dispatchers = new List<Dispatcher>();

        //static Timer flyTickTimer = new Timer(Display.DisplayRefreshRate);

        public static void flyThreadMethod()
        {
            coordinates.x += ((float)speed / (3600 * (1000 / Display.DisplayRefreshRate)));
            coordinates.y += ((float)pitch / (3600 * (1000 / Display.DisplayRefreshRate)));

            foreach(Dispatcher dispatcher in dispatchers)
            {
                dispatcher.controlFlight(coordinates, speed);
            }
        }

        public static void addDispatcher(Dispatcher dispatcher)
        {
            dispatchers.Add(dispatcher);
        }

        public static void startFly()
        {

            if (dispatchers.Count < 2)
                throw new Exception("We need at least 2 dispatchers to fly");

           // flyTickTimer.Elapsed += flyThreadMethod;
           // flyTickTimer.Start();
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            try {
                Display.init();

                Plane.addDispatcher(new Dispatcher("Dispatcher 1"));
                Plane.addDispatcher(new Dispatcher("Dispatcher 2"));

                Plane.startFly();

                while (true)
                {
                    Display.input(Console.ReadKey());
                }
            }

            catch (Exception exception)
            {
                Console.WriteLine(exception.Message);     
            }
        }
    }
}
