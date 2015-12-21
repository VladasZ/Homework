using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Loger
{
    public class Loger
    {
        public static void hi()
        {
            Console.WriteLine("iziziizi");
        }

        public static void init(string ini = "init.ini")
        {

            // StreamWriter fileWr = new StreamWriter(ini);


            // fileWr.WriteLine("blblablalbalggblablabl");


            // fileWr.Close();

            FileStream iniFile = new FileStream(ini, FileMode.Open, FileAccess.Read);
           

            StreamReader initRead = new StreamReader(iniFile);

            string data = initRead.ReadToEnd();


            string[] macro = data.Split('#');




            foreach (string a in macro)
                Console.WriteLine(a);


        }
        
    }
}
