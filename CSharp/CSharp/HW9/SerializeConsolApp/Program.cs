using ClassLib;
using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace SerializeConsolApp
{
    class Program
    {

        static void Main(string[] args)
        {
            List<PC> pcStorage = new List<PC>();

            pcStorage.AddRange(new PC[] {
                new PC(),
                new PC("Samsung", 123456789, 1000),
                new PC("Lenovo", 987654321, 320),
                new PC("Apple", 46518928, 550)});

            foreach (PC pc in pcStorage)
            {
                pc.turnOn(); 
            }

            using (FileStream file = new FileStream(@"C:\pcStorageData.txt", FileMode.OpenOrCreate))
            {
                BinaryFormatter binFormat = new BinaryFormatter();
                binFormat.Serialize(file, pcStorage);
            }


        }
    }
}
