using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLib
{
    [Serializable]
    public class PC
    {
        string manufacturer;
        public string Manufacturer
        {
            set
            {
                manufacturer = value;
            }
            get
            {
                return manufacturer;
            }
        }
        int serialNumber;
        public int SerialNumber
        {
            set
            {
                serialNumber = value;
            }
            get
            {
                return serialNumber;
            }
        }
        int hdd;
        public int HDD
        {
            set
            {
                hdd = value;
            }
            get
            {
                return hdd;
            }
        }

        public PC()
        {
            manufacturer = "Asus";
            serialNumber = 88888888;
            hdd = 500;
        }

        public PC(string manufacturer, int serialNumber, int hdd)
        {
            this.manufacturer = manufacturer;
            this.serialNumber = serialNumber;
            this.hdd = hdd;
        }

        public void turnOn()
        {
            Console.WriteLine(manufacturer + " " + serialNumber + " is ON");
        }
        public void turnOff()
        {
            Console.WriteLine(manufacturer + " " + serialNumber + " is OFF");
        }
        public void reboot()
        {
            Console.WriteLine(manufacturer + " " + serialNumber + " is rebooted");
        }


    }
}
