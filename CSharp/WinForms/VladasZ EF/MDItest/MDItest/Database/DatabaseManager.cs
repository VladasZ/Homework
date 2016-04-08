using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MDItest.Database
{
    public static class DatabaseManager
    {
        static BooksContainer booksContainer = new BooksContainer();

        static Random rand = new Random();

        public static void addGenre(string name)
        {
            Genre duplicateGenre = getGenreNamed(name);
                                   
            if (duplicateGenre != null)
            {
                MessageBox.Show("Такой жанр уже есть в базе");
                return;
            }

            Genre newGenre = new Genre()
            {
                Name = name
            };

            booksContainer.GenreSet.Add(newGenre);
            booksContainer.SaveChanges();

            WindowManager.GenresComboBox.DataSource = getGenresNames();
        }

        public static void addPublisher(string name, string address)
        {
            Publisher duplicatePublisher = getPublisherNamed(name);

            if(duplicatePublisher != null)
            {
                MessageBox.Show("Такой издатель уже есть в базе");
                return;
            }

            Publisher newPublisher = new Publisher
            {
                Name = name,
                Address = address
            };

            booksContainer.PublisherSet.Add(newPublisher);
            booksContainer.SaveChanges();

            WindowManager.PublishersComboBox.DataSource = getPublishersNames();
        }

        public static void addBook(string name, string genre, string publisher)
        {
            Book duplicateBook = getBookNamed(name);

            if (duplicateBook != null)
            {
                MessageBox.Show("Такая книга уже есть в базе");
                return;
            }

            Book newBook = new Book()
            {
                Title = name,
                Genre = getGenreNamed(genre),
                Publisher = getPublisherNamed(publisher),
                Price = rand.Next(1, 1500) * 100
            };

            booksContainer.BookSet.Add(newBook);
            booksContainer.SaveChanges();

            WindowManager.BooksGridView.DataSource = getAllBooks();
        }

        public static void deleteBook(string name)
        {
            Book book = (from b in booksContainer.BookSet
                         where b.Title == name
                         select b).FirstOrDefault();

            booksContainer.BookSet.Remove(book);
            booksContainer.SaveChanges();
        }

        private static string[] getBooksNames()
        {
            return (from b in booksContainer.BookSet
                    select b.Title).ToArray();
        }

        public static string[] getGenresNames()
        {
            return (from g in booksContainer.GenreSet
                    select g.Name).ToArray();
        }

        public static string[] getPublishersNames()
        {
            return (from p in booksContainer.PublisherSet
                    select p.Name).ToArray();
        }

        private static Publisher getPublisherNamed(string name)
        {
            return (from p in booksContainer.PublisherSet
                    where p.Name == name
                    select p).FirstOrDefault();
        }

        private static Genre getGenreNamed(string name)
        {
            return (from g in booksContainer.GenreSet
                    where g.Name == name
                    select g).FirstOrDefault();
        }

        private static Book getBookNamed(string name)
        {
            return (from b in booksContainer.BookSet
                    where b.Title == name
                    select b).FirstOrDefault();
        }


        //сильно плохо ли здесь указывать имена полей русскими?
        public static object[] getAllBooks()
        {
            return (from b in booksContainer.BookSet
                    select new { Название = b.Title, Жанр = b.Genre.Name, Издательство = b.Publisher.Name, Цена = b.Price }).ToArray();
        }
        
    }
}
