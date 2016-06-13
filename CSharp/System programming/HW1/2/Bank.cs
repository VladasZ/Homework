using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;

namespace _2
{
    public class Bank
    {
        private ReaderWriterLockSlim fileLock = new ReaderWriterLockSlim();

        private int money;
        public int Money
        {
            get { return money; }
            set { money = value; propertyChanged(); }
        }

        private string name;
        public string Name
        {
            get { return name; }
            set { name = value; propertyChanged(); }
        }

        private int percent;
        public int Percent
        {
            get { return percent; }
            set { percent = value; propertyChanged(); }
        }


        private void propertyChanged()
        {
            Thread saveThread = new Thread(new ThreadStart(saveChanges));
            saveThread.Start();
        }

        private void saveChanges()
        {
            fileLock.EnterWriteLock();
            try
            {
                XmlSerializer xmlSerializer = new XmlSerializer(typeof(Bank));

                StreamWriter streamWriter = new StreamWriter("bank.xml");
                xmlSerializer.Serialize(streamWriter, this);
                streamWriter.Close();
            }
            finally
            {
                fileLock.ExitWriteLock();
            }
        }
    }
}
