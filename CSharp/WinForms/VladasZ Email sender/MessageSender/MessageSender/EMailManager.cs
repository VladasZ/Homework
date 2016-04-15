using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Mail;
using System.Net;
using System.Windows.Forms;

namespace MessageSender
{
    static class EMailManager
    {
        static SmtpClient Smtp = new SmtpClient("smtp.mail.ru", 25);

        static EMailManager()
        {
            //почта нашего преподавателя по C# специально заведенная для тестов
            Smtp.Credentials = new NetworkCredential("ivanitstep@mail.ru", "ivan123456789");
            Smtp.EnableSsl = true;
        }

        public static void sendMail(string to)
        {
            MailMessage message = new MailMessage();

            message.From = new MailAddress("ivanitstep@mail.ru");
            message.To.Add(new MailAddress(to));
            message.Subject = "Test letter";
            message.Body = "Test Test Test Test Test Test Test Test Test";

            Smtp.Send(message);
        }

        public static void sendMail(string[] to, string subject, string body)
        {
            MailMessage message = new MailMessage();

            message.From = new MailAddress("ivanitstep@mail.ru");

            foreach(string mail in to)
            {
                message.To.Add(mail);
            }

            message.Subject = subject;
            message.Body = body;

            Smtp.Send(message);
        }

        public static void sentTestMail(string[] to, string subject, string body)
        {
            MailMessage message = new MailMessage();

            message.From = new MailAddress("ivanitstep@mail.ru");
                        
            message.To.Add("146100@gmail.com");// поменяйте для проверки на свое
            
            message.Subject = "Тест тест Тест";

            //добавляем адреса из расписания в текст нашего письма
            foreach(string mail in to)
            {
                message.Body += mail + "\n";
            }

            message.Body += body;

            Smtp.Send(message);
        }

    }
}
