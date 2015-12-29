using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml.Linq;


namespace HW8
{
    class Program
    {
        static int maxTemperature = -273;
        static string hottestCity;

        static List<string> init(string iniPath = "settings.ini")
        {
            FileStream iniFile = new FileStream(iniPath, FileMode.Open, FileAccess.Read);
            StreamReader initRead = new StreamReader(iniFile);
            string data = initRead.ReadToEnd();

            MatchCollection cityCodes = Regex.Matches(data, @"#\d{5}");

            List<string> cities = new List<string>();

            foreach (Match code in cityCodes)
                cities.Add(Regex.Replace(code.ToString(), "#", ""));
                       
            return cities;
        }

        static void showWeatherForCity(string code)
        {
            string xmlPath = @"http://informer.gismeteo.by/rss/" + code + ".xml";
            
            XDocument doc = XDocument.Load(xmlPath);

            IEnumerable<XElement> weather = doc.Element("rss").Element("channel").Elements();

            XElement cityInfo = doc.Element("rss").Element("channel").Element("item").Element("title");

            string city = Regex.Match(cityInfo.Value, @"\w+:").ToString();// получаем название города

            Console.WriteLine(city);// получаем название города
            
            string TempPattern = @"-?\d+..-?\d+";
            string DateTimePattern = @"\w+ \d+ \w+, \w+";
            string MaxTempPattern = @"\.\.-?\d+";

            foreach (XElement elem in weather)
            {
                if (elem.Name == "item")
                {

                    Console.Write("{0,20}{1}",
                        Regex.Match(
                            elem.Element("title").Value,
                            DateTimePattern
                        ),
                    ": ");

                    Console.WriteLine("{0,6}",
                        Regex.Match(
                            elem.Element("description").Value,
                            TempPattern
                        ).ToString()
                    );

                    int temp = int.Parse(
                        Regex.Match(
                            Regex.Match(
                                elem.Element("description").Value,
                                MaxTempPattern).ToString(),
                        @"-?\d+").ToString());

                    if (temp > maxTemperature)
                    {
                        maxTemperature = temp;
                        hottestCity = city.Trim(':');
                    }

                }
            }

            Console.WriteLine();
                

        }

        static void showHottestCity()
        {
            if (hottestCity == null)
            {
                Console.WriteLine("Сначало получите информацию о температуре хотябы для одного города.");
                return;
            }

            Console.WriteLine("Самый теплый город из выбранных - " + hottestCity + ". Днём: " + maxTemperature + "°C.");

        }

        static void Main(string[] args)
        {                     

            List<string> cityCodes = init();

            foreach(string code in cityCodes)
               showWeatherForCity(code);

            showHottestCity();

            // doc.Save("weather.xml");

        }
    }
}
