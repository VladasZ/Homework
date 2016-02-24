using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_2
{
    class Program
    {
        static void Main(string[] args)
        {
            string data =
                "Вот дом, Который построил Джек. А это пшеница," +
                " Которая в темном чулане хранится В доме, Который построил Джек." +
                " А это веселая птица-синица, Которая часто ворует пшеницу," +
                " Которая в темном чулане хранится В доме, Который построил Джек.";


            string[] words = data.Split(' ');

            for (int i = 0; i < words.Count(); ++i)
                words[i] = words[i].Trim('.', ',');
            
            Dictionary<string, int> statistic = new Dictionary<string, int>();

            foreach(string word in words)
            {
                if (statistic.ContainsKey(word))
                    statistic[word]++;

                else
                    statistic.Add(word, 1);
            }

            Console.WriteLine("{0,21} {1,15}", "Слово:", "Количество:\n");

            int n = 1;

            foreach (KeyValuePair<string, int> pair in statistic)
            {                
                Console.WriteLine("{0,3}. {1,15} {2,15}", n++, pair.Key, pair.Value);
            }

            Console.WriteLine("\nВсего слов: {0}. Из них уникальных: {1}.", words.Count(), statistic.Count);


        }
    }
}
