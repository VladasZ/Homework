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
        public DateTime SendDate { get; }
        public List<uint> UsersID { get; }
        public EventType Type { get; }
        public string Comment { get; }
        public string MessageText { get; }
        public string AttachedFilePath {  get; }

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
