using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLib;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace DeserializeConsolApp
{
    class Program
    {
        static void Main(string[] args)
        {

            List<PC> openStorage = new List<PC>();

            using (FileStream file = new FileStream(@"C:\pcStorageData.txt", FileMode.Open))
            {
                BinaryFormatter binFormat = new BinaryFormatter();
                openStorage = (List<PC>)binFormat.Deserialize(file);
            }

            foreach (PC pc in openStorage)
                pc.turnOn();
        }
    }
}
