using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GasStation
{

    class Fuel
    {
        public string fuelType { set; get;}
        public uint price { set; get; }

        public Fuel(string type, uint price)
        {
            this.fuelType = type;
            this.price = price;
        }
    }


    static class DataSource
    {

        public static Fuel[] fuelTypes = new Fuel[] { 
            new Fuel("АИ-95-К5 Евро", 11900),
            new Fuel("АИ-92-К5 Евро", 11100),
            new Fuel("Газ марки ПБА", 6300),
            new Fuel("ДТ Арктика", 13800),
            new Fuel("ДТ Евро5", 12300)
        };
              

    }
}
