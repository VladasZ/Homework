using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading;
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

namespace MediaPlayer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        bool isPlaying;
        DispatcherTimer timer = new DispatcherTimer();

        List<string> filePaths;
        BindingList<string> fileNames = new BindingList<string>();

        public MainWindow()
        {
            InitializeComponent();

            timer.Interval = TimeSpan.FromSeconds(1);
            timer.Tick += timer_Tick;
        }

        private void openButton_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Multiselect = true;

            openFileDialog.Filter = "Video files|*.avi;*.mp4;*.mkv" +
                                    "|Audio files|*.mp3;*.wav;*.flac" +
                                    "|All Files|*.*";

            bool? dialogResult = openFileDialog.ShowDialog();

            if (dialogResult.HasValue && (bool)dialogResult)
            {
                filePaths = openFileDialog.FileNames.ToList();
                fileNames.Clear();
                
                //достаем из пути только название файла для красивого отображения в списке файлов
                foreach (string path in filePaths)
                {
                    string[] fileName = path.Split('\\');
                    fileNames.Add(fileName.Last());
                }

                filesListBox.ItemsSource = fileNames;
                filesListBox.SelectedIndex = 0;
                mediaElement.Source = new Uri(filePaths.First());
            }

        }

        private void playButton_Click(object sender, RoutedEventArgs e)
        {
            if (mediaElement.Source == null) return;

            if (!isPlaying)
            {
                playButtonLabel.Content = "Pause";
                playButtonImage.Source = new BitmapImage(new Uri("/images/pause.png", UriKind.Relative));
                mediaElement.Play();
                timer.Start();
                isPlaying = true;
            }
            else
            {
                timer.Stop();
                mediaElement.Pause();
                playButtonLabel.Content = "Play";
                playButtonImage.Source = new BitmapImage(new Uri("/images/play.png", UriKind.Relative));
                isPlaying = false;
            }            
        }

        private void stopButton_Click(object sender, RoutedEventArgs e)
        {
            timer.Stop();
            mediaElement.Stop();
            playButtonLabel.Content = "Play";
            playButtonImage.Source = new BitmapImage(new Uri("/images/play.png", UriKind.Relative));
            isPlaying = false;
        }

        private void mediaElement_MediaFailed(object sender, ExceptionRoutedEventArgs e)
        {
            MessageBox.Show("Не удалось воспроизвести файл!");
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            progressTimeLabel.Content = mediaElement.Position.ToLabel();

            progressSlider.Value = mediaElement.ProgressPercentage();
        }

        private void volumeSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if (mediaElement.Volume == 0)
                muteButtonImage.Source = new BitmapImage(new Uri("/images/notMute.png", UriKind.Relative));
            
            if (volumeSlider.Value == 0)
                muteButtonImage.Source = new BitmapImage(new Uri("/images/mute.png", UriKind.Relative));
            
            mediaElement.Volume = volumeSlider.Value;
        }

        private void nextButton_Click(object sender, RoutedEventArgs e)
        {
            if (fileNames.Count == 0) return;

            if (filePaths[filesListBox.SelectedIndex] == filePaths.Last())
            {
                filesListBox.SelectedIndex = 0;
            }
            else
            {
                filesListBox.SelectedIndex++;
            }

            changeFile();
        }

        private void prevButton_Click(object sender, RoutedEventArgs e)
        {
            if (fileNames.Count == 0) return;

            if (filePaths[filesListBox.SelectedIndex] == filePaths.First())
            {
                filesListBox.SelectedIndex = filePaths.Count() - 1;
            }
            else
            {
                filesListBox.SelectedIndex--;
            }

            changeFile();
        }

        private void filesListBox_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            changeFile();
        }

        private void changeFile()
        {
            mediaElement.Source = new Uri(filePaths[filesListBox.SelectedIndex]);
        }

        private void mediaElement_MediaEnded(object sender, RoutedEventArgs e)
        {
            nextButton_Click(null, null);
        }

        private void mediaElement_MediaOpened(object sender, RoutedEventArgs e)
        {
            durationLabel.Content = mediaElement.NaturalDuration.TimeSpan.ToLabel();
        }

        private void progressSlider_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            mediaElement.SetProgress((int)progressSlider.Value);
        }

        //полноэкранный режим по двойному щелчку
        private void mediaElement_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            if (e.ClickCount == 2 && WindowState == WindowState.Normal)
            {
                WindowStyle = WindowStyle.None;
                WindowState = WindowState.Maximized;
            }
            else if (e.ClickCount == 2 && WindowState == WindowState.Maximized)
            {
                WindowStyle = WindowStyle.SingleBorderWindow;
                WindowState = WindowState.Normal;
            }
        }

        private void muteButton_Click(object sender, RoutedEventArgs e)
        {
            if(mediaElement.Volume != 0)
            {
                mediaElement.Volume = 0;
                muteButtonImage.Source = new BitmapImage(new Uri("/images/mute.png", UriKind.Relative));
            }
            else if (volumeSlider.Value != 0)
            {
                mediaElement.Volume = volumeSlider.Value;
                muteButtonImage.Source = new BitmapImage(new Uri("/images/notMute.png", UriKind.Relative));
            }

        }
    }

}
