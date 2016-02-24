using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Loger
{

    struct Message
    {
        public static int counter = 1;
        public string error;
        public string message;

        public Message(string error, string message)
        {
            this.message = message;
            this.error = error;
        }
    }

    delegate void func(Message message, StreamWriter logWrite);

    static class MessagesSender
    {
        public static void number(Message message, StreamWriter logWrite)
        {
            logWrite.WriteLine(Message.counter);
            Message.counter++;
        }

        public static void time(Message message, StreamWriter logWrite)
        {
            logWrite.WriteLine(DateTime.Now);
        }

        public static void space(Message message, StreamWriter logWrite)
        {
            logWrite.WriteLine(" ");
        }

        public static void nothing(Message message,  StreamWriter logWrite)
        {
            return;
        }

        public static void message(Message message,  StreamWriter logWrite)
        {
            logWrite.WriteLine(message.message);
        }

        public static void error(Message message, StreamWriter logWrite)
        {
            logWrite.WriteLine(message.error);
        }

        public static void endl(Message message, StreamWriter logWrite)
        {
            logWrite.WriteLine(" ");
        }

    }

    public class Loger
    {
        static func message;

        static bool initDone = false;
        static FileStream logFile;
        static StreamWriter logWrite;

        static Loger()
        {
            logFile = new FileStream("log.txt", FileMode.OpenOrCreate, FileAccess.Write);
            logWrite = new StreamWriter(logFile);
            message = MessagesSender.nothing;
        }

        public static void log()
        {

            if (!initDone) init();

          
            message(new Message("error", "bla bla"),  logWrite);


        }

        public static void init(string ini = "init.ini")
        {
            
            FileStream iniFile = new FileStream(ini, FileMode.Open, FileAccess.Read);
           
            StreamReader initRead = new StreamReader(iniFile);

            string data = initRead.ReadToEnd();
            
            string[] macro = data.Split('#');

            for(int i = 1; i < macro.Length; ++i)
            {

               // Console.WriteLine(macro[i]);

                switch (macro[i])
                {
                   

                    case "NUMBER":
                      //  message += MessagesSender.number;
                        Console.WriteLine("NUMBER");
                        break;
                    case "TIME":
                      //  message += MessagesSender.time;
                        Console.WriteLine("TIME");
                        break;
                    case "ERROR":
                     //   message += MessagesSender.error;
                        Console.WriteLine("ERROR");
                        break;
                    case "MESSAGE":
                        message += MessagesSender.message;
                        Console.WriteLine("MESSAGE");
                        break;
                }

               // message += MessagesSender.space;
            }

          //  message += MessagesSender.endl;


            initDone = true;
            initRead.Close();
            iniFile.Close();
        }

        public static void closeLog()
        {
            logWrite.Close();
            logFile.Close();
        }
        
    }
}
