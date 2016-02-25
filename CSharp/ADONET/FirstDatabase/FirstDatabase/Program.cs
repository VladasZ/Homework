using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.OleDb;


namespace FirstDatabase
{
    class Program
    {
        static OleDbConnection connection = new OleDbConnection();

        static Program()
        {
            connection.ConnectionString = @"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\Vladas\Desktop\WinForms\Day1 ADO\med.mdb";

            connection.Open();
        }

        static OleDbDataReader readerForCommand(string commandString)
        {
            OleDbCommand command = new OleDbCommand(commandString, connection);

            return command.ExecuteReader();
        }

        static void showAllPatients()
        {
            OleDbDataReader reader = readerForCommand("SELECT * FROM Patients");


            Console.WriteLine("Все пациенты:");

            while (reader.Read() != false)
            {

                Console.WriteLine("{0,-10} {1,-10} {2,-10}", reader["patientID"], 
                                                            reader["patientName"], reader["patientFirstName"]);

            }
        }


        static void Main(string[] args)
        {
            showAllPatients();
        }
    }
}
