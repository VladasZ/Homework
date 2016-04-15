namespace _15_puzzle
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
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.картинкаToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.defaultImageMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.openMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.openURLMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.imageURLTextBoxMenu = new System.Windows.Forms.ToolStripTextBox();
            this.shuffleMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.solveMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripComboBox1 = new System.Windows.Forms.ToolStripComboBox();
            this.recordsMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.gfdgfdToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip
            // 
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.картинкаToolStripMenuItem,
            this.shuffleMenu,
            this.solveMenu,
            this.recordsMenu,
            this.settingsMenu,
            this.gfdgfdToolStripMenuItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(1120, 24);
            this.menuStrip.TabIndex = 0;
            this.menuStrip.Text = "menuStrip1";
            // 
            // картинкаToolStripMenuItem
            // 
            this.картинкаToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.defaultImageMenu,
            this.openMenu,
            this.openURLMenu,
            this.imageURLTextBoxMenu});
            this.картинкаToolStripMenuItem.Name = "картинкаToolStripMenuItem";
            this.картинкаToolStripMenuItem.Size = new System.Drawing.Size(70, 20);
            this.картинкаToolStripMenuItem.Text = "Картинка";
            // 
            // defaultImageMenu
            // 
            this.defaultImageMenu.Name = "defaultImageMenu";
            this.defaultImageMenu.Size = new System.Drawing.Size(160, 22);
            this.defaultImageMenu.Text = "Стандартная";
            this.defaultImageMenu.Click += new System.EventHandler(this.defaultImageMenu_Click);
            // 
            // openMenu
            // 
            this.openMenu.Name = "openMenu";
            this.openMenu.Size = new System.Drawing.Size(160, 22);
            this.openMenu.Text = "Открыть";
            this.openMenu.Click += new System.EventHandler(this.openMenu_Click);
            // 
            // openURLMenu
            // 
            this.openURLMenu.Name = "openURLMenu";
            this.openURLMenu.Size = new System.Drawing.Size(160, 22);
            this.openURLMenu.Text = "Открыть URL";
            this.openURLMenu.Click += new System.EventHandler(this.openURLMenu_Click);
            // 
            // imageURLTextBoxMenu
            // 
            this.imageURLTextBoxMenu.Name = "imageURLTextBoxMenu";
            this.imageURLTextBoxMenu.Size = new System.Drawing.Size(100, 23);
            this.imageURLTextBoxMenu.Text = "-Введите URL-";
            // 
            // shuffleMenu
            // 
            this.shuffleMenu.Name = "shuffleMenu";
            this.shuffleMenu.Size = new System.Drawing.Size(90, 20);
            this.shuffleMenu.Text = "Перемешать";
            this.shuffleMenu.Click += new System.EventHandler(this.shuffleMenu_Click);
            // 
            // solveMenu
            // 
            this.solveMenu.Name = "solveMenu";
            this.solveMenu.Size = new System.Drawing.Size(94, 20);
            this.solveMenu.Text = "Восстановить";
            this.solveMenu.Click += new System.EventHandler(this.clearForm);
            // 
            // settingsMenu
            // 
            this.settingsMenu.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripComboBox1});
            this.settingsMenu.Name = "settingsMenu";
            this.settingsMenu.Size = new System.Drawing.Size(79, 20);
            this.settingsMenu.Text = "Настройки";
            // 
            // toolStripComboBox1
            // 
            this.toolStripComboBox1.Items.AddRange(new object[] {
            "3x3",
            "4x4",
            "5x5",
            "6x6",
            "7x7",
            "8x8"});
            this.toolStripComboBox1.Name = "toolStripComboBox1";
            this.toolStripComboBox1.Size = new System.Drawing.Size(121, 23);
            this.toolStripComboBox1.Click += new System.EventHandler(this.toolStripComboBox1_Click);
            // 
            // recordsMenu
            // 
            this.recordsMenu.Name = "recordsMenu";
            this.recordsMenu.Size = new System.Drawing.Size(67, 20);
            this.recordsMenu.Text = "Рекорды";
            this.recordsMenu.Click += new System.EventHandler(this.recordsMenu_Click);
            // 
            // gfdgfdToolStripMenuItem
            // 
            this.gfdgfdToolStripMenuItem.Name = "gfdgfdToolStripMenuItem";
            this.gfdgfdToolStripMenuItem.Size = new System.Drawing.Size(55, 20);
            this.gfdgfdToolStripMenuItem.Text = "gfdgfd";
            this.gfdgfdToolStripMenuItem.Click += new System.EventHandler(this.gfdgfdToolStripMenuItem_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1120, 817);
            this.Controls.Add(this.menuStrip);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip;
            this.Name = "MainForm";
            this.Text = "Мозаика";
            this.Shown += new System.EventHandler(this.MainForm_Shown);
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem картинкаToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem shuffleMenu;
        private System.Windows.Forms.ToolStripMenuItem solveMenu;
        private System.Windows.Forms.ToolStripMenuItem settingsMenu;
        private System.Windows.Forms.ToolStripMenuItem defaultImageMenu;
        private System.Windows.Forms.ToolStripMenuItem openMenu;
        private System.Windows.Forms.ToolStripMenuItem openURLMenu;
        private System.Windows.Forms.ToolStripTextBox imageURLTextBoxMenu;
        private System.Windows.Forms.ToolStripComboBox toolStripComboBox1;
        private System.Windows.Forms.ToolStripMenuItem recordsMenu;
        private System.Windows.Forms.ToolStripMenuItem gfdgfdToolStripMenuItem;
    }
}

