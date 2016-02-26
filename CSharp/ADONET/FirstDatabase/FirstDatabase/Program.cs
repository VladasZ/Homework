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

        static OleDbCommand commandForQuery(string commandString)
        {
              return new OleDbCommand(commandString, connection);
        }

        static void showAllPatients()
        {
            OleDbDataReader reader = commandForQuery("SELECT * FROM Patients").ExecuteReader();

            Console.WriteLine("Все пациенты:");

            while (reader.Read() != false)
            {
                Console.WriteLine("{0,-2}{1,-10}{2,-10}{3, -10}", 
                                  reader["patientID"],
                                  reader["patientName"],
                                  reader["patientFirstName"],
                                  reader["patientBirthDate"]);
            }
        }
        
        static void showDoctorsCount()
        {
            int doctorsCount = (int)commandForQuery("SELECT COUNT(doctorID) FROM Doctors").ExecuteScalar();

            Console.WriteLine("\nКоличество докторов в больнице: {0}", doctorsCount);

        }

        static void mostExpenssiveVisit()
        {

            OleDbDataReader reader = 
                commandForQuery("SELECT* FROM VisitCosts WHERE visitCostValue = " + 
                                "(SELECT max(visitCostValue) FROM VisitCosts)").ExecuteReader();

            Console.WriteLine("\nСамый дорогой визит:");


            while (reader.Read() != false)
            {
                Console.WriteLine("{0,-2}{1,-10}{2,-10}{3, -10}",
                                  reader["visitCostID"],
                                  reader["visitCostFrom"],
                                  reader["visitCostTill"],
                                  reader["visitCostValue"]);
            }

        }

        static void Main(string[] args)
        {
            showAllPatients();
            showDoctorsCount();
            mostExpenssiveVisit();
        }
    }
}
