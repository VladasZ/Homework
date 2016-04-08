using MDItest.Database;
using MDItest.Forms;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MDItest
{
    static class WindowManager
    {
        public static MainForm mainForm { get; } = (MainForm)Application.OpenForms[0];
        private static BookList bookListForm = new BookList();
        private static AddBookForm addBookForm = new AddBookForm();
        private static AddBookGenreForm addBookGenreForm = new AddBookGenreForm();
        private static AddPublisherForm addPublisherForm = new AddPublisherForm();

        public static ComboBox GenresComboBox { get { return addBookForm.GenreComboBox; } }
        public static ComboBox PublishersComboBox { get { return addBookForm.PublisherComboBox; } }
        public static DataGridView BooksGridView { get { return bookListForm.BooksGridView; } }

        static WindowManager()
        {
            //устанавливаем общие свойства для всех нужных форм
            setCommonFormProperties(bookListForm);
            setCommonFormProperties(addBookForm);
            setCommonFormProperties(addBookGenreForm);
            setCommonFormProperties(addPublisherForm);
        }

        //не уверен что так нужно было делать но мне кажется что теперь вызовы выглядят более красиво)
        public static class Open
        {
            public static void bookListWindow()
            {
                openWindow(bookListForm);
            }

            public static void addBookWindow()
            {
                openWindow(addBookForm);
            }

            public static void addBookGenreWindow()
            {
                openWindow(addBookGenreForm);
            }

            public static void addPublisherWindow()
            {
                openWindow(addPublisherForm);
            }

            private static void openWindow(Form window)
            {
                if (window.Visible == true)
                {
                    return;
                }

                window.Visible = true;
            }
        }

        public static void closeWindow(Form window)
        {
            window.Visible = false;
        }

        private static void setCommonFormProperties(Form form)
        {
            form.FormClosing += (oo, ee) =>
            {
                ee.Cancel = true;
                form.Visible = false;
            };

            form.MdiParent = mainForm;
        }

        public static void setStatus()
        {
            mainForm.statusLabel.Text =  "Количество книг в базе: " + DatabaseManager.getAllBooks().Count();
        }
    }
}
