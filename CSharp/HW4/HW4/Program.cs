using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW4
{
    interface IPart
    {
       void build();
       void showBuildStatus();

    }

    class Part : IPart{
        public int BuildProgress {  private set; get; }
        public int Price { private set; get; }
        public string Type { private set; get; }
        public bool Done { private set; get; }

        public Part(int price, string type)
        {
            Done = false;
            Type = type;
            BuildProgress = 0;
            Price = price;
        }

        
        public void build()
        {
            ++BuildProgress;
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
        public Window() : base(1000, "Окно") {}
    }

    class Door : Part
    {
        public Door() : base(2000, "Дверь") { }
    }

    class Wall : Part
    {
        public Wall() : base(5000, "Стена") { }
    }

    class Roof : Part
    {
        public Roof() : base(5000, "Крыша") { }
    }

    class Basement : Part
    {
        public Basement() : base(6000, "Фундамент") { }
    }


    class Home
    {
        static IPart[] parts =
        {
            new Basement(),
            new Wall(), new Wall(), new Wall(), new Wall(),
            new Door(),
            new Window(), new Window(), new Window(), new Window(),
            new Roof()
        };

       public static void showProgress()
        {
            foreach (IPart a in parts)
                a.showBuildStatus();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Home.showProgress();
            


        }
    }
}
