using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace Styles
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        public static Process CurrentProcess { get; set; }

        List<Process> processes;

        DispatcherTimer timer = new DispatcherTimer();

        public MainWindow()
        {
            InitializeComponent();

            processes = Process.GetProcesses().ToList();


            Binding gridBinding = new Binding();
            gridBinding.Source = from proc in processes
                                 select new GridObject
                                 {
                                     ID = proc.Id,
                                     Name = proc.ProcessName,
                                     Memory = Math.Round(proc.PagedMemorySize64 / (double)1000000, 2) + " МБ"
                                 };

            dataGrid.SetBinding(DataContextProperty, gridBinding);



            DataContext = CurrentProcess;


            timer.Tick += timer_Tick;
            timer.Interval = TimeSpan.FromSeconds(1);

            timer.Start();
        }

        static int i = 0;

        private void timer_Tick(object sender, EventArgs e)
        {
            processes = Process.GetProcesses().ToList();

            //dataGrid.DataContext = from proc in processes
            //                       select new GridObject
            //                       {
            //                           ID = proc.Id,
            //                           Name = proc.ProcessName,
            //                           Memory = Math.Round(proc.PagedMemorySize64 / (double)1000000, 2) + " МБ"
            //                       };

            Title = i++.ToString();
        }

        private void dataGrid_SelectedCellsChanged(object sender, SelectedCellsChangedEventArgs e)
        {
            if (dataGrid.SelectedItem != null)
            {
                CurrentProcess = (from proc in processes
                                 where proc.Id == ((GridObject)dataGrid.SelectedItem).ID
                                 select proc).FirstOrDefault();
            }

            //MessageBox.Show(CurrentProcess.Id.ToString());
        }

      
    }
}
