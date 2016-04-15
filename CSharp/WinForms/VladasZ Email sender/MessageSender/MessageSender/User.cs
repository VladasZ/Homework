using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Xml.Serialization;

namespace MessageSender
{
    public enum UserType
    {
        CloserRelatives,
        FarRelatives,
        Department,
        Company,
        BestFriends,
        Teammates
    }

    public class User
    {
        public uint ID { get; }
        public string Name { get; }
        [XmlIgnore]
        public MailAddress Email { get; }
        public string StringMailAddress { get; }
        public UserType UserType { get; }

        public User(uint id, string name, MailAddress email, UserType userType)
        {
            ID = id;
            Name = name;
            Email = email;
            StringMailAddress = email.ToString();
            UserType = userType;
        }

        public User()
        {

        }
    }
}
