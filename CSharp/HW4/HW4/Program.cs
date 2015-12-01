using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace HW4
{
    interface IPart
    {
       void build();
       void showBuildStatus();
       int getBuildStatus();

    }

    class Part : IPart{
        public int BuildProgress {  private set; get; }
        public int BuildSpeed { private set; get; }
        public int Price { private set; get; }
        public string Type { private set; get; }
        public bool Done { private set; get; }
        public int getBuildStatus()
        {
            return BuildProgress;
        }

        public Part(int price, string type, int buildSpeed)
        {
            Done = false;
            Type = type;
            BuildProgress = 0;
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
        public Window() : base(1000, "Окно", 10) {}
    }

    class Door : Part
    {
        public Door() : base(2000, "Дверь",10) { }
    }

    class Wall : Part
    {
        public Wall() : base(5000, "Стена",2) { }
    }

    class Roof : Part
    {
        public Roof() : base(5000, "Крыша",5) { }
    }

    class Basement : Part
    {
        public Basement() : base(6000, "Фундамент",1) { }
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
                a.build();
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



       public static bool done = false;

       public static void showProgress()
        {
            for(int i = 0; i <= parts.Length; ++i)
            {
                if(i == parts.Length)
                {
                    done = true;
                    return;
                }
                if (parts[i].getBuildStatus() != 100)
                    break;
            }

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
