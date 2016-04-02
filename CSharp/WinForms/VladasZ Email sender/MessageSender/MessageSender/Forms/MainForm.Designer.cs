namespace MessageSender
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Близкие родственники");
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Дальник родственники");
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Родственники", new System.Windows.Forms.TreeNode[] {
            treeNode1,
            treeNode2});
            System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("Отдел");
            System.Windows.Forms.TreeNode treeNode5 = new System.Windows.Forms.TreeNode("Компания");
            System.Windows.Forms.TreeNode treeNode6 = new System.Windows.Forms.TreeNode("Сотрудники", new System.Windows.Forms.TreeNode[] {
            treeNode4,
            treeNode5});
            System.Windows.Forms.TreeNode treeNode7 = new System.Windows.Forms.TreeNode("Лучшие друзья");
            System.Windows.Forms.TreeNode treeNode8 = new System.Windows.Forms.TreeNode("Друзья по команде");
            System.Windows.Forms.TreeNode treeNode9 = new System.Windows.Forms.TreeNode("Друзья", new System.Windows.Forms.TreeNode[] {
            treeNode7,
            treeNode8});
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.treeView = new System.Windows.Forms.TreeView();
            this.imageList = new System.Windows.Forms.ImageList(this.components);
            this.toTextBox = new System.Windows.Forms.TextBox();
            this.selectAllUsersButton = new System.Windows.Forms.Button();
            this.deleteContextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.удалитьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addContextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.добавитьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.addToSheduleButton = new System.Windows.Forms.Button();
            this.messageTextBox = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.commentTextBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.minutesNumeric = new System.Windows.Forms.NumericUpDown();
            this.hoursNumeric = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.EventTypeComboBox = new System.Windows.Forms.ComboBox();
            this.monthCalendar = new System.Windows.Forms.MonthCalendar();
            this.label2 = new System.Windows.Forms.Label();
            this.adressesTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.sendTestMail = new System.Windows.Forms.Button();
            this.deleteContextMenu.SuspendLayout();
            this.addContextMenu.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.minutesNumeric)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.hoursNumeric)).BeginInit();
            this.SuspendLayout();
            // 
            // treeView
            // 
            this.treeView.ImageIndex = 3;
            this.treeView.ImageList = this.imageList;
            this.treeView.Location = new System.Drawing.Point(12, 12);
            this.treeView.Name = "treeView";
            treeNode1.Name = "CloserRelatives";
            treeNode1.Text = "Близкие родственники";
            treeNode2.Name = "FarRelatives";
            treeNode2.Text = "Дальник родственники";
            treeNode3.Checked = true;
            treeNode3.ImageIndex = 1;
            treeNode3.Name = "Relatives";
            treeNode3.Text = "Родственники";
            treeNode4.Name = "Department";
            treeNode4.Text = "Отдел";
            treeNode5.Name = "Company";
            treeNode5.Text = "Компания";
            treeNode6.ImageIndex = 0;
            treeNode6.Name = "Employees";
            treeNode6.Text = "Сотрудники";
            treeNode7.Name = "BestFriends";
            treeNode7.Text = "Лучшие друзья";
            treeNode8.Name = "Teammates";
            treeNode8.Text = "Друзья по команде";
            treeNode9.ImageIndex = 2;
            treeNode9.Name = "Friends";
            treeNode9.Text = "Друзья";
            this.treeView.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode3,
            treeNode6,
            treeNode9});
            this.treeView.SelectedImageIndex = 4;
            this.treeView.Size = new System.Drawing.Size(382, 521);
            this.treeView.TabIndex = 0;
            this.treeView.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView_AfterSelect);
            // 
            // imageList
            // 
            this.imageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList.ImageStream")));
            this.imageList.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList.Images.SetKeyName(0, "employee.png");
            this.imageList.Images.SetKeyName(1, "family.png");
            this.imageList.Images.SetKeyName(2, "friends.png");
            this.imageList.Images.SetKeyName(3, "person.png");
            this.imageList.Images.SetKeyName(4, "select.png");
            // 
            // toTextBox
            // 
            this.toTextBox.Location = new System.Drawing.Point(56, 3);
            this.toTextBox.Multiline = true;
            this.toTextBox.Name = "toTextBox";
            this.toTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.toTextBox.Size = new System.Drawing.Size(321, 89);
            this.toTextBox.TabIndex = 2;
            // 
            // selectAllUsersButton
            // 
            this.selectAllUsersButton.Location = new System.Drawing.Point(12, 539);
            this.selectAllUsersButton.Name = "selectAllUsersButton";
            this.selectAllUsersButton.Size = new System.Drawing.Size(114, 23);
            this.selectAllUsersButton.TabIndex = 3;
            this.selectAllUsersButton.Text = "Выбрать всех";
            this.selectAllUsersButton.UseVisualStyleBackColor = true;
            this.selectAllUsersButton.Click += new System.EventHandler(this.selectAllButton_Click);
            // 
            // deleteContextMenu
            // 
            this.deleteContextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.удалитьToolStripMenuItem});
            this.deleteContextMenu.Name = "deleteContextMenu";
            this.deleteContextMenu.Size = new System.Drawing.Size(119, 26);
            // 
            // удалитьToolStripMenuItem
            // 
            this.удалитьToolStripMenuItem.Name = "удалитьToolStripMenuItem";
            this.удалитьToolStripMenuItem.Size = new System.Drawing.Size(118, 22);
            this.удалитьToolStripMenuItem.Text = "Удалить";
            this.удалитьToolStripMenuItem.Click += new System.EventHandler(this.deleteToolStripMenuItem_Click);
            // 
            // addContextMenu
            // 
            this.addContextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.добавитьToolStripMenuItem});
            this.addContextMenu.Name = "addContextMenu";
            this.addContextMenu.Size = new System.Drawing.Size(127, 26);
            // 
            // добавитьToolStripMenuItem
            // 
            this.добавитьToolStripMenuItem.Name = "добавитьToolStripMenuItem";
            this.добавитьToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.добавитьToolStripMenuItem.Text = "Добавить";
            this.добавитьToolStripMenuItem.Click += new System.EventHandler(this.addToolStripMenuItem_Click);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(400, 12);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(388, 550);
            this.tabControl1.TabIndex = 4;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.addToSheduleButton);
            this.tabPage1.Controls.Add(this.messageTextBox);
            this.tabPage1.Controls.Add(this.label6);
            this.tabPage1.Controls.Add(this.label5);
            this.tabPage1.Controls.Add(this.commentTextBox);
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.minutesNumeric);
            this.tabPage1.Controls.Add(this.hoursNumeric);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.EventTypeComboBox);
            this.tabPage1.Controls.Add(this.monthCalendar);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.adressesTextBox);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.toTextBox);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(380, 524);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Главное";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // addToSheduleButton
            // 
            this.addToSheduleButton.Location = new System.Drawing.Point(229, 495);
            this.addToSheduleButton.Name = "addToSheduleButton";
            this.addToSheduleButton.Size = new System.Drawing.Size(145, 23);
            this.addToSheduleButton.TabIndex = 16;
            this.addToSheduleButton.Text = "Добавить в расписание";
            this.addToSheduleButton.UseVisualStyleBackColor = true;
            this.addToSheduleButton.Click += new System.EventHandler(this.addToSheduleButton_Click);
            // 
            // messageTextBox
            // 
            this.messageTextBox.Location = new System.Drawing.Point(6, 386);
            this.messageTextBox.Multiline = true;
            this.messageTextBox.Name = "messageTextBox";
            this.messageTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.messageTextBox.Size = new System.Drawing.Size(368, 103);
            this.messageTextBox.TabIndex = 15;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(9, 370);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(100, 13);
            this.label6.TabIndex = 14;
            this.label6.Text = "Текст сообщения:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(176, 278);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(80, 13);
            this.label5.TabIndex = 13;
            this.label5.Text = "Комментарий:";
            // 
            // commentTextBox
            // 
            this.commentTextBox.Location = new System.Drawing.Point(179, 294);
            this.commentTextBox.Multiline = true;
            this.commentTextBox.Name = "commentTextBox";
            this.commentTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.commentTextBox.Size = new System.Drawing.Size(195, 67);
            this.commentTextBox.TabIndex = 12;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(176, 239);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(108, 13);
            this.label4.TabIndex = 11;
            this.label4.Text = "Время отправления";
            // 
            // minutesNumeric
            // 
            this.minutesNumeric.Location = new System.Drawing.Point(218, 255);
            this.minutesNumeric.Maximum = new decimal(new int[] {
            59,
            0,
            0,
            0});
            this.minutesNumeric.Name = "minutesNumeric";
            this.minutesNumeric.Size = new System.Drawing.Size(33, 20);
            this.minutesNumeric.TabIndex = 10;
            // 
            // hoursNumeric
            // 
            this.hoursNumeric.Location = new System.Drawing.Point(179, 255);
            this.hoursNumeric.Maximum = new decimal(new int[] {
            23,
            0,
            0,
            0});
            this.hoursNumeric.Name = "hoursNumeric";
            this.hoursNumeric.Size = new System.Drawing.Size(33, 20);
            this.hoursNumeric.TabIndex = 9;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(176, 199);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(54, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "Событие:";
            // 
            // EventTypeComboBox
            // 
            this.EventTypeComboBox.FormattingEnabled = true;
            this.EventTypeComboBox.Items.AddRange(new object[] {
            "Просто письмо",
            "Новый год",
            "Пасха",
            "День святого Валентина",
            "8 марта",
            "23 февраля",
            "День рождения",
            "Юбилей фирмы"});
            this.EventTypeComboBox.Location = new System.Drawing.Point(179, 215);
            this.EventTypeComboBox.Name = "EventTypeComboBox";
            this.EventTypeComboBox.Size = new System.Drawing.Size(195, 21);
            this.EventTypeComboBox.TabIndex = 7;
            // 
            // monthCalendar
            // 
            this.monthCalendar.Location = new System.Drawing.Point(12, 199);
            this.monthCalendar.MaxSelectionCount = 1;
            this.monthCalendar.Name = "monthCalendar";
            this.monthCalendar.TabIndex = 6;
            this.monthCalendar.KeyDown += new System.Windows.Forms.KeyEventHandler(this.monthCalendar_KeyDown);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(7, 101);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Адреса:";
            // 
            // adressesTextBox
            // 
            this.adressesTextBox.Location = new System.Drawing.Point(56, 98);
            this.adressesTextBox.Multiline = true;
            this.adressesTextBox.Name = "adressesTextBox";
            this.adressesTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.adressesTextBox.Size = new System.Drawing.Size(321, 89);
            this.adressesTextBox.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(18, 6);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(36, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Кому:";
            // 
            // tabPage2
            // 
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(380, 524);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Настройки";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // sendTestMail
            // 
            this.sendTestMail.Location = new System.Drawing.Point(211, 539);
            this.sendTestMail.Name = "sendTestMail";
            this.sendTestMail.Size = new System.Drawing.Size(183, 23);
            this.sendTestMail.TabIndex = 5;
            this.sendTestMail.Text = "Отправить тестовое письмо";
            this.sendTestMail.UseVisualStyleBackColor = true;
            this.sendTestMail.Click += new System.EventHandler(this.sendTestMail_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(796, 566);
            this.Controls.Add(this.sendTestMail);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.selectAllUsersButton);
            this.Controls.Add(this.treeView);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "MainForm";
            this.Text = "Рассылка сообщений";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.deleteContextMenu.ResumeLayout(false);
            this.addContextMenu.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.minutesNumeric)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.hoursNumeric)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView treeView;
        private System.Windows.Forms.ImageList imageList;
        private System.Windows.Forms.TextBox toTextBox;
        private System.Windows.Forms.Button selectAllUsersButton;
        private System.Windows.Forms.ContextMenuStrip deleteContextMenu;
        private System.Windows.Forms.ToolStripMenuItem удалитьToolStripMenuItem;
        private System.Windows.Forms.ContextMenuStrip addContextMenu;
        private System.Windows.Forms.ToolStripMenuItem добавитьToolStripMenuItem;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TextBox adressesTextBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.MonthCalendar monthCalendar;
        private System.Windows.Forms.ComboBox EventTypeComboBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown minutesNumeric;
        private System.Windows.Forms.NumericUpDown hoursNumeric;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox commentTextBox;
        private System.Windows.Forms.TextBox messageTextBox;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button addToSheduleButton;
        private System.Windows.Forms.Button sendTestMail;
    }
}

