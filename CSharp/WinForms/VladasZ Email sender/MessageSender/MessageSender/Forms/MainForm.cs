using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MessageSender
{
    public partial class MainForm : Form
    {
        List<User> selectedUsers = new List<User>();

        Event currentEvent;

        public TreeView MainTreeView { private set { } get { return treeView; } }

        Timer timer = new Timer();

        public MainForm()
        {
            InitializeComponent();

            EventTypeComboBox.SelectedIndex = 0;

            StartPosition = FormStartPosition.CenterScreen;

            foreach (TreeNode node in treeView.Nodes)
            {
                setAddContextMenu(node);
            }

            timer.Interval = 60000;
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            DateTime now = DateTime.Now;

            currentEvent = DataManager.Shedule.Find(
                _event => _event.SendDate.Month == now.Month &&
                          _event.SendDate.Day == now.Day &&
                          _event.SendDate.Hour == now.Hour &&
                          _event.SendDate.Minute == now.Minute
                );
            // есть ли более простой способ игнорировать секунды в сравнении с DateTime?
            // гугл не помог

            if (currentEvent == null)
                return;

            selectedUsers = selectUsersFromEvent(currentEvent);

            BackgroundWorker sendMessagesWorker = new BackgroundWorker();
            sendMessagesWorker.DoWork += SendMessagesWorker_DoWork;
            sendMessagesWorker.RunWorkerAsync();

        }

        private void SendMessagesWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            string[] to = selectedUsers.Select(user => user.StringMailAddress).ToArray();

            EMailManager.sentTestMail(to, currentEvent.Comment, currentEvent.MessageText);

            MessageBox.Show("Письма были успешно отправлены");
        }

        private void treeView_AfterSelect(object sender, TreeViewEventArgs e)
        {
            selectedUsers.Clear();
            getUsersFromSelectedNode(treeView.SelectedNode);

            showUsers(selectedUsers);            
        }

        private void getUsersFromSelectedNode(TreeNode threeNode)
        {
            if (threeNode.Level == 2)
            {
                selectedUsers.Add(DataManager.Users.Find(user => user.Name == threeNode.Text));
                return;
            }

            foreach (TreeNode node in threeNode.Nodes)
            {
                if (node.Level == 2)
                {
                    selectedUsers.Add(DataManager.Users.Find(user => user.Name == node.Text));
                }
                else
                {
                    getUsersFromSelectedNode(node);
                }
            }
        }

        private void setAddContextMenu(TreeNode treeNode)
        {
            foreach (TreeNode node in treeNode.Nodes)
            {
                if (node.Level == 1)
                {
                    node.ContextMenuStrip = addContextMenu;
                }
                else
                {
                    setAddContextMenu(node);
                }
            }
        }

        private void selectAllButton_Click(object sender, EventArgs e)
        {
            selectedUsers = DataManager.Users.ToList();

            toTextBox.Clear();
            adressesTextBox.Clear();

            foreach(User user in selectedUsers)
            {
                toTextBox.AppendText(user.Name + "\n");
                adressesTextBox.AppendText(user.StringMailAddress + "\n");
            }

        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            DataManager.loadData();
            showUsersInTreeView(DataManager.Users);
            showBoldDatesFromShedule();
        }

        private void addToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (treeView.SelectedNode.Level == 1)
            {
                AddUserForm addUserForm = new AddUserForm(treeView.SelectedNode.Name);
                addUserForm.StartPosition = FormStartPosition.CenterParent;
                addUserForm.ShowDialog();
            }
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DataManager.Users.RemoveAll(user => user.Name == treeView.SelectedNode.Text);

            if(treeView.SelectedNode.Level == 2)
            {
                treeView.SelectedNode.Remove();
            }
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            DataManager.saveData();
        }

        private void addToSheduleButton_Click(object sender, EventArgs e)
        {

            List<Event> sameDateEvents = DataManager.Shedule
                .FindAll(_event => _event.SendDate.Month == monthCalendar.SelectionRange.Start.Month &&
                                   _event.SendDate.Day == monthCalendar.SelectionRange.Start.Day
                ).ToList();

            if (sameDateEvents.Count != 0)
            {
                MessageBox.Show("На эту дату уже установлено событие, в текущей версии программы невозможно установить 2 события в один день");
                return;
            }

            DateTime eventDateTime = monthCalendar.SelectionRange.Start;
            eventDateTime = eventDateTime.AddHours((double)hoursNumeric.Value).AddMinutes((double)minutesNumeric.Value);

            DataManager.Shedule.Add(
                new Event(
                    eventDateTime,
                    selectedUsers.Select(user => user.ID).ToList(), 
                    (EventType)EventTypeComboBox.SelectedIndex, 
                    commentTextBox.Text, 
                    messageTextBox.Text));

            monthCalendar.AddBoldedDate(monthCalendar.SelectionRange.Start);
            monthCalendar.UpdateBoldedDates();
        }

        private void showBoldDatesFromShedule()
        {
            monthCalendar.BoldedDates = DataManager.Shedule.Select(_event => _event.SendDate).ToArray();
            monthCalendar.UpdateBoldedDates();
        }

        private void showUsersInTreeView(List<User> users)
        {
            foreach (User user in users)
            {
                switch (user.UserType)
                {
                    case UserType.CloserRelatives:
                        treeView.Nodes["Relatives"].Nodes["CloserRelatives"].Nodes.Add(user.Name);
                        treeView.Nodes["Relatives"].Nodes["CloserRelatives"].LastNode.ContextMenuStrip = deleteContextMenu;
                        break;
                    case UserType.FarRelatives:
                        treeView.Nodes["Relatives"].Nodes["FarRelatives"].Nodes.Add(user.Name);
                        treeView.Nodes["Relatives"].Nodes["FarRelatives"].LastNode.ContextMenuStrip = deleteContextMenu;
                        break;
                    case UserType.Department:
                        treeView.Nodes["Employees"].Nodes["Department"].Nodes.Add(user.Name);
                        treeView.Nodes["Employees"].Nodes["Department"].LastNode.ContextMenuStrip = deleteContextMenu;
                        break;
                    case UserType.Company:
                        treeView.Nodes["Employees"].Nodes["Company"].Nodes.Add(user.Name);
                        treeView.Nodes["Employees"].Nodes["Company"].LastNode.ContextMenuStrip = deleteContextMenu;
                        break;
                    case UserType.BestFriends:
                        treeView.Nodes["Friends"].Nodes["BestFriends"].Nodes.Add(user.Name);
                        treeView.Nodes["Friends"].Nodes["BestFriends"].LastNode.ContextMenuStrip = deleteContextMenu;
                        break;
                    case UserType.Teammates:
                        treeView.Nodes["Friends"].Nodes["Teammates"].Nodes.Add(user.Name);
                        treeView.Nodes["Friends"].Nodes["Teammates"].LastNode.ContextMenuStrip = deleteContextMenu;
                        break;
                    default:
                        throw new FormatException("Invalid user type");
                }
            }
        }

        private void showEvent(Event _event)
        {
            hoursNumeric.Value = _event.SendDate.Hour;
            minutesNumeric.Value = _event.SendDate.Minute;
            EventTypeComboBox.SelectedIndex = (int)_event.Type;

            commentTextBox.Text = _event.Comment;
            messageTextBox.Text = _event.MessageText;

            selectedUsers = selectUsersFromEvent(_event);

            showUsers(selectedUsers);
        }

        private void showUsers(List<User> users)
        {
            toTextBox.Clear();
            adressesTextBox.Clear();

            foreach (User user in users)
            {
                toTextBox.AppendText(user.Name + "\n");
                adressesTextBox.AppendText(user.StringMailAddress + "\n");
            }
        }

        private List<User> selectUsersFromEvent(Event _event)
        {
            return (from e in _event.UsersID
                    join u in DataManager.Users
                    on e equals u.ID
                    select u).ToList();
        }

        private void sendTestMail_Click(object sender, EventArgs e)
        {
            BackgroundWorker backgroundWorker = new BackgroundWorker();

            backgroundWorker.DoWork += BackgroundWorker_DoWork;

            backgroundWorker.RunWorkerAsync();

        }

        private void BackgroundWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            EMailManager.sendMail("146100@gmail.com");
            MessageBox.Show("Письмо успешно отправлено");
        }

        private void monthCalendar_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                Event selectedEvent = DataManager.Shedule.Find(
                _event => _event.SendDate.Month == monthCalendar.SelectionRange.Start.Month &&
                          _event.SendDate.Day == monthCalendar.SelectionRange.Start.Day 
                );

                if (selectedEvent == null)
                {
                    MessageBox.Show("На этот день не назначено ни одного собития");
                    return;
                } 
                showEvent(selectedEvent);
            }
 
        }
    }
}
