using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace MessageSender
{
    static class DataManager
    {
        public static List<User> Users { get; private set; } = new List<User>();
        public static List<Event> Shedule { get; private set; } = new List<Event>();

        public static uint lastUserID; // нужен для уникального ID каждого нового юзера, хранится в отдельном файле

        private static XmlSerializer usersSerializer = new XmlSerializer(typeof(List<User>));
        private static XmlSerializer sheduleSerializer = new XmlSerializer(typeof(List<Event>));
       
        private const string usersXMLFilename = "users.xml";
        private const string usersIDFilename = "lastUserID";
        private const string sheduleXMLFilename = "shedule.xml";

        static DataManager()
        {
            try
            {
                if (!uint.TryParse(File.ReadAllText(usersIDFilename), out lastUserID))
                {
                    MessageBox.Show("lastUserID file corrupted");
                    Application.Exit();
                }
            }
            catch (FileNotFoundException)
            {
                MessageBox.Show("lastUserID file not found");
                Application.Exit();
            }

        }

        private static void saveUsers()
        {
            StreamWriter usersWriter = new StreamWriter(usersXMLFilename);

            usersSerializer.Serialize(usersWriter, Users);

            usersWriter.Close();

            File.WriteAllText(usersIDFilename, lastUserID.ToString());
        }

        private static void loadUsers()
        {
            StreamReader usersReader = new StreamReader(usersXMLFilename);

            Users = (List<User>)usersSerializer.Deserialize(usersReader);

            usersReader.Close();
        }

        private static void saveShedule()
        {
            StreamWriter sheduleWriter = new StreamWriter(sheduleXMLFilename);

            sheduleSerializer.Serialize(sheduleWriter, Shedule);

            sheduleWriter.Close();
        }

        private static void loadShedule()
        {
            StreamReader sheduleWriter = new StreamReader(sheduleXMLFilename);

            Shedule = (List<Event>)sheduleSerializer.Deserialize(sheduleWriter);

            sheduleWriter.Close();
        }

        public static void loadData()
        {
            loadUsers();
            loadShedule();
        }

        public static void saveData()
        {
            saveUsers();
            saveShedule();
        }

    }
}
