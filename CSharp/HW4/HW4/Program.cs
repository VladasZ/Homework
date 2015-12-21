using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace HW4
{

    enum priority
    {
        Basement, Wall, Door, Window, Roof
    };

    interface IPart
    {
       void build();
       priority GetPriority();
       void showBuildStatus();
       int getBuildStatus();

    }

    class Part : IPart{
        public int BuildProgress {  private set; get; }
        public int BuildSpeed { private set; get; }
        public int Price { private set; get; }
        public priority Priority { private set; get; }
        public string Type { private set; get; }
        public bool Done { private set; get; }
        public int getBuildStatus()
        {
            return BuildProgress;
        }

        public priority GetPriority()
        {
            return Priority;
        }


        public Part(int price, string type, int buildSpeed, priority pr)
        {
            Done = false;
            Type = type;
            BuildProgress = 0;
            Priority = pr;
            BuildSpeed = buildSpeed;
            Price = price;
        }

        
        public void build()
        {
            if (BuildProgress == 100) return;
            BuildProgress += BuildSpeed;
        }
        
        public void showBuildStatus()
        {
            if (Done)
            {
                Console.WriteLine(Type + "- строительство завершено");
                return;
            } 

            Console.WriteLine(Type + " построено на " + BuildProgress + "%");
        }
    }

    class Window : Part
    {
        public Window() : base(1000, "Окно", 10, priority.Window) {}
    }

    class Door : Part
    {
        public Door() : base(2000, "Дверь",10,priority.Door) { }
    }

    class Wall : Part
    {
        public Wall() : base(5000, "Стена",2, priority.Wall) { }
    }

    class Roof : Part
    {
        public Roof() : base(5000, "Крыша",5, priority.Roof) { }
    }

    class Basement : Part
    {
        public Basement() : base(6000, "Фундамент",1, priority.Basement) { }
    }

    interface IWorker
    {
        void build(ref IPart[] parts);
    }

    class Worker : IWorker
    {
        public void build(ref IPart[] parts)
        {
            foreach (IPart a in parts)
            {
                if (Home.Priority == a.GetPriority())
                {
                    a.build();
                }
            }
        }

    }

    class TeamLeader
    {
        public void Report()
        {
            Console.Clear();

            if (!Home.done)
               Home.showProgress();
            
            else
               Console.WriteLine("Дом готов!");
            
         }
    }

    class Home
    {
       public static IPart[] parts =
        {
            new Basement(),
            new Wall(), new Wall(), new Wall(), new Wall(),
            new Door(),
            new Window(), new Window(), new Window(), new Window(),
            new Roof()
        };


       public static priority Priority = priority.Basement; // В первую очередь строим фундамент

       public static bool done = false;

       public static void showProgress()
        {

            foreach(IPart a in parts)
            {
                if (a.GetPriority() == Home.Priority &&
                    a.getBuildStatus() == 100)
                {
                    Home.Priority++;
                    break;
                }
            }

            if (Home.Priority == priority.Roof + 1)
                done = true;

            foreach (IPart a in parts)            
                a.showBuildStatus();

            
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            Worker Ravshan = new Worker();
            Worker Djumschut = new Worker();
            TeamLeader Naschalnika = new TeamLeader();

            Naschalnika.Report();

            while (!Home.done)
            {
                Thread.Sleep(200);

                Ravshan.build(ref Home.parts);
                Djumschut.build(ref Home.parts);
                
                Naschalnika.Report();
            }


            Naschalnika.Report();
            
            
        }
    }
}
