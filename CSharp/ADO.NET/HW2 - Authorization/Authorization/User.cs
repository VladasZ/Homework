using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Authorization
{
    public class User
    {
        public int    ID        { get; set; }
        public string UserName  { get; set; }
        public string Password  { get; set; }
        public string FirstName { get; set; }
        public string LastName  { get; set; }
        public string PhotoURL  { get; set; }

        public User(string UserName,
                    string Password,
                    string FirstName,
                    string LastName,
                    string PhotoURL)
        {
            this.UserName  = UserName;
            this.Password  = Password;
            this.FirstName = FirstName;
            this.LastName  = LastName;
            this.PhotoURL  = PhotoURL;
        }
    }
}