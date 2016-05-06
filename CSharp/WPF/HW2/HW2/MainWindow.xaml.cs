using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace HW2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        DispatcherTimer timer = new DispatcherTimer();
        DateTime timerStart;
        BindingList<string> laps = new BindingList<string>();

        NotifyIcon notifyIcon = new NotifyIcon();
        ContextMenu notifyContextMenu = new ContextMenu();

        public MainWindow()
        {
            InitializeComponent();

            timer.Tick += timer_Tick;
            timer.Interval = TimeSpan.FromMilliseconds(1);

            lapsListBox.ItemsSource = laps;

            setNotifyMenu();
        }

        private void setNotifyMenu()
        {
            notifyIcon.Visible = true;
            notifyIcon.Icon = new Icon("timer.ico");
            notifyIcon.MouseDoubleClick += notifyIcon_MouseDoubleClick;
            notifyIcon.ContextMenu = notifyContextMenu;

            addContextMenuItem("Запуск",     (oo, ee) => startButton_Click(null, null));
            addContextMenuItem("Сброс",      (oo, ee) => resetButton_Click(null, null));
            addContextMenuItem("Круг",       (oo, ee) => lapButton_Click(null, null));
            addContextMenuItem("Развернуть", (oo, ee) => WindowState = WindowState.Normal);
            addContextMenuItem("Закрыть",    (oo, ee) => App.Current.Shutdown());
        }

        public void addContextMenuItem(string Text, EventHandler handler)
        {
            notifyContextMenu.MenuItems.Add(new MenuItem() { Text = Text });
            notifyContextMenu.MenuItems[notifyContextMenu.MenuItems.Count - 1].Click += handler;
        }

        private void notifyIcon_MouseDoubleClick(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            WindowState = WindowState.Normal;
        }

        private void window_StateChanged(object sender, EventArgs e)
        {
            if (WindowState == WindowState.Minimized)
            {
                ShowInTaskbar = false;
            }
            else if (WindowState == WindowState.Normal)
            {
                ShowInTaskbar = true;
            }
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            timeTextBox.Text = getInterval();
            notifyIcon.Text = getInterval();
        }

        private void startButton_Click(object sender, RoutedEventArgs e)
        {
            timerStart = DateTime.Now;
            timer.Start();
            laps.Clear();
        }

        private void resetButton_Click(object sender, RoutedEventArgs e)
        {
            timer.Stop();
            timeTextBox.Text = "00:00:00:000";
            laps.Clear();
        }

        private void lapButton_Click(object sender, RoutedEventArgs e)
        {
            if (!timer.IsEnabled) return;
            laps.Add(getInterval());
        }

        private string getInterval()
        {
            TimeSpan time = DateTime.Now - timerStart;
            return string.Format("{0:00}:{1:00}:{2:00}:{3:000}", time.Hours, time.Minutes, time.Seconds, time.Milliseconds);
        }

    }
}
