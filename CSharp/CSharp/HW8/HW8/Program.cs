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

        //паттерны для регулярных выражений
        const string TemperaturePattern = @"-?\d+..-?\d+";
        const string DateTimePattern = @"\w+ \d+ \w+, \w+";
        const string MaxTempPattern = @"\.\.-?\d+";

        static List<string> getCitiesCodeList(string iniPath = "settings.ini")
        {
            FileStream iniFile = new FileStream(iniPath, FileMode.Open, FileAccess.Read);
            StreamReader initRead = new StreamReader(iniFile);
            string data = initRead.ReadToEnd();

            MatchCollection cityCodes = Regex.Matches(data, @"#\d{5}");

            List<string> citiesCode = new List<string>();

            foreach (Match code in cityCodes)
            {
                citiesCode.Add(Regex.Replace(code.ToString(), "#", ""));
            }

            return citiesCode;
        }

        static void showWeatherForCity(string cityCode)
        {
            string xmlPath = @"http://informer.gismeteo.by/rss/" + cityCode + ".xml";
            
            XDocument doc = XDocument.Load(xmlPath);

            IEnumerable<XElement> weather = doc.Element("rss").Element("channel").Elements();

            XElement cityInfo = doc.Element("rss").Element("channel").Element("item").Element("title");

            string city = Regex.Match(cityInfo.Value, @"\w+:").ToString();// получаем название города

            Console.WriteLine(city);

            //парсим XML-ку полученную с сайта gismeteo.by
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
                            TemperaturePattern
                        ).ToString()
                    );

                    int temperature = int.Parse(
                        Regex.Match(
                            Regex.Match(
                                elem.Element("description").Value,
                                MaxTempPattern).ToString(),
                        @"-?\d+").ToString());

                    // переписываем самый теплый город
                    if (temperature > maxTemperature)
                    {
                        maxTemperature = temperature;
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
            List<string> cityCodes = getCitiesCodeList();

            foreach(string code in cityCodes)
            {
                showWeatherForCity(code);
            }

            showHottestCity();

            Console.ReadKey();
        }
    }
}
