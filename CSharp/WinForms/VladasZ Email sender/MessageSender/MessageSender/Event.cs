using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace MessageSender
{
    public enum EventType
    {
        JustMail,
        NewYear,
        Easter,
        ValentinesDay,
        WomensDay,
        MensDay,
        Birthday,
        CompanyAnniversary
    }

    public class Event
    {
        public DateTime SendDate { set; get; }
        public List<uint> UsersID { set; get; }
        public EventType Type { set; get; }
        public string Comment { set; get; }
        public string MessageText { set; get; }
        public string AttachedFilePath { set; get; }

        public Event()
        {

        }

        public Event(DateTime sendDate, List<uint> usersID, EventType type, string comment, string messageText, string attachedFilePath)
        {
            SendDate = sendDate;
            UsersID = usersID;
            Type = type;
            Comment = comment;
            MessageText = messageText;
            AttachedFilePath = attachedFilePath;
        }

        public Event(DateTime sendDate, List<uint> usersID, EventType type, string comment, string messageText)
            : this(sendDate, usersID, type, comment, messageText, null)
        {

        }
    }
}
