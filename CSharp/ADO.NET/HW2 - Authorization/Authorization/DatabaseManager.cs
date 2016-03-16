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


        static DatabaseManager()
        {
            connection = new SqlConnection(@"Data Source = VLADAS - PC\SQLEXPRESS; Initial Catalog = users; Integrated Security = True");
            connection.Open();
        }


        public static void insertUser(User newUser)
        {
            SqlCommand commandInsert = connection.CreateCommand();
            commandInsert.CommandText = @"Insert Into Users(userName, password, firstName, lastName, photoUrl)" +
                                        @"Values ('" + newUser.UserName  + "', '" + newUser.Password + "' , '" +
                                                       newUser.FirstName + "', '" + newUser.LastName + "' , '" +
                                                       newUser.PhotoURL  + "')";
            commandInsert.ExecuteNonQuery();
        }
    }
}
