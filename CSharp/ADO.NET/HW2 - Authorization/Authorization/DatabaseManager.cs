using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;

namespace Authorization
{
    static class DatabaseManager
    {
        static SqlConnection connection;
        static int usersCount;

        static DatabaseManager()
        {
            connection = new SqlConnection(@"Data Source=(localdb)\MSSQLLocalDB;Initial Catalog=Authorization;Integrated Security=True");
            connection.Open();

            SqlCommand commandCount = connection.CreateCommand();
            commandCount.CommandText = @"SELECT COUNT(*) FROM Users";

            usersCount = (int)commandCount.ExecuteScalar();
        }


        public static void insertUser(User newUser)
        {
            SqlCommand commandInsert = connection.CreateCommand();
            
            commandInsert.CommandText = @"Insert Into Users(id, userName, password, firstName, lastName, photoURL)" +
                                        @"Values ('"  + usersCount++ + "', '" + newUser.UserName  + "', '" + newUser.Password + "' , '" +
                                                       newUser.FirstName + "', '" + newUser.LastName + "' , '" +
                                                       newUser.PhotoURL  + "')";
            commandInsert.ExecuteNonQuery();
        }

        public static void wipeAllNewUsers()
        {
            SqlCommand commandClean = connection.CreateCommand();

            commandClean.CommandText = @"DELETE FROM Users WHERE id > 0";
            commandClean.ExecuteNonQuery();
            usersCount = 1;
        }

        public static User logIn(string userName, string password)
        {
            SqlCommand commangLogIn = connection.CreateCommand();
            commangLogIn.CommandText = "SELECT firstName, lastName, photoURL FROM Users WHERE userName = '" + userName + "' AND password = '" + password + "'";

            SqlDataReader reader = commangLogIn.ExecuteReader();

            if (!reader.HasRows)
            {
                reader.Close();
                return null;
            }
    

            User currentUser = null;

            while (reader.Read())
            {
                currentUser =
                    new User(userName,
                             password,
                             (string)reader["firstName"],
                             (string)reader["lastName"],
                             (string)reader["photoURL"]);
            }


            reader.Close();
            return currentUser;
        }
    }
}
