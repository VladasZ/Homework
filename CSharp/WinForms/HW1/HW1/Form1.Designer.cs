namespace HW1
{
    partial class modelTextBox
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
            this.phonesListBox = new System.Windows.Forms.ListBox();
            this.tabControl = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.label10 = new System.Windows.Forms.Label();
            this.manufacturerTextBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.priceTextBox = new System.Windows.Forms.TextBox();
            this.cpuTextBox = new System.Windows.Forms.TextBox();
            this.osTextBox = new System.Windows.Forms.TextBox();
            this.modelTextBox_ = new System.Windows.Forms.TextBox();
            this.phonePictureBox = new System.Windows.Forms.PictureBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.priceEditBox = new System.Windows.Forms.NumericUpDown();
            this.cleanButton = new System.Windows.Forms.Button();
            this.saveInfoButton = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            this.photoEditBox = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.cpuEditBox = new System.Windows.Forms.TextBox();
            this.osEditBox = new System.Windows.Forms.TextBox();
            this.manufacturerEditBox = new System.Windows.Forms.TextBox();
            this.modelEditBox = new System.Windows.Forms.TextBox();
            this.saveDataButton = new System.Windows.Forms.Button();
            this.loadDataButton = new System.Windows.Forms.Button();
            this.deletePhoneButton = new System.Windows.Forms.Button();
            this.addPhoneButton = new System.Windows.Forms.Button();
            this.tabControl.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.phonePictureBox)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.priceEditBox)).BeginInit();
            this.SuspendLayout();
            // 
            // phonesListBox
            // 
            this.phonesListBox.FormattingEnabled = true;
            this.phonesListBox.Location = new System.Drawing.Point(12, 12);
            this.phonesListBox.Name = "phonesListBox";
            this.phonesListBox.Size = new System.Drawing.Size(197, 238);
            this.phonesListBox.TabIndex = 0;
            this.phonesListBox.SelectedIndexChanged += new System.EventHandler(this.phonesListBox_SelectedIndexChanged);
            // 
            // tabControl
            // 
            this.tabControl.Controls.Add(this.tabPage1);
            this.tabControl.Controls.Add(this.tabPage2);
            this.tabControl.Location = new System.Drawing.Point(215, 12);
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            this.tabControl.Size = new System.Drawing.Size(508, 428);
            this.tabControl.TabIndex = 1;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.label10);
            this.tabPage1.Controls.Add(this.manufacturerTextBox);
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.priceTextBox);
            this.tabPage1.Controls.Add(this.cpuTextBox);
            this.tabPage1.Controls.Add(this.osTextBox);
            this.tabPage1.Controls.Add(this.modelTextBox_);
            this.tabPage1.Controls.Add(this.phonePictureBox);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(500, 402);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Информация о телефоне";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(224, 9);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(86, 13);
            this.label10.TabIndex = 10;
            this.label10.Text = "Производитель";
            // 
            // manufacturerTextBox
            // 
            this.manufacturerTextBox.Location = new System.Drawing.Point(316, 6);
            this.manufacturerTextBox.Name = "manufacturerTextBox";
            this.manufacturerTextBox.ReadOnly = true;
            this.manufacturerTextBox.Size = new System.Drawing.Size(178, 20);
            this.manufacturerTextBox.TabIndex = 9;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(224, 113);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(33, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Цена";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(224, 87);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(63, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Процессор";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(224, 61);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(22, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "ОС";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(224, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Модель";
            // 
            // priceTextBox
            // 
            this.priceTextBox.Location = new System.Drawing.Point(316, 110);
            this.priceTextBox.Name = "priceTextBox";
            this.priceTextBox.ReadOnly = true;
            this.priceTextBox.Size = new System.Drawing.Size(178, 20);
            this.priceTextBox.TabIndex = 4;
            // 
            // cpuTextBox
            // 
            this.cpuTextBox.Location = new System.Drawing.Point(316, 84);
            this.cpuTextBox.Name = "cpuTextBox";
            this.cpuTextBox.ReadOnly = true;
            this.cpuTextBox.Size = new System.Drawing.Size(178, 20);
            this.cpuTextBox.TabIndex = 3;
            // 
            // osTextBox
            // 
            this.osTextBox.Location = new System.Drawing.Point(316, 58);
            this.osTextBox.Name = "osTextBox";
            this.osTextBox.ReadOnly = true;
            this.osTextBox.Size = new System.Drawing.Size(178, 20);
            this.osTextBox.TabIndex = 2;
            // 
            // modelTextBox_
            // 
            this.modelTextBox_.Location = new System.Drawing.Point(316, 32);
            this.modelTextBox_.Name = "modelTextBox_";
            this.modelTextBox_.ReadOnly = true;
            this.modelTextBox_.Size = new System.Drawing.Size(178, 20);
            this.modelTextBox_.TabIndex = 1;
            // 
            // phonePictureBox
            // 
            this.phonePictureBox.Location = new System.Drawing.Point(6, 6);
            this.phonePictureBox.Name = "phonePictureBox";
            this.phonePictureBox.Size = new System.Drawing.Size(211, 389);
            this.phonePictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.phonePictureBox.TabIndex = 0;
            this.phonePictureBox.TabStop = false;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.priceEditBox);
            this.tabPage2.Controls.Add(this.cleanButton);
            this.tabPage2.Controls.Add(this.saveInfoButton);
            this.tabPage2.Controls.Add(this.label9);
            this.tabPage2.Controls.Add(this.photoEditBox);
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.label7);
            this.tabPage2.Controls.Add(this.label11);
            this.tabPage2.Controls.Add(this.label8);
            this.tabPage2.Controls.Add(this.cpuEditBox);
            this.tabPage2.Controls.Add(this.osEditBox);
            this.tabPage2.Controls.Add(this.manufacturerEditBox);
            this.tabPage2.Controls.Add(this.modelEditBox);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(500, 402);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Редактирование информации";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // priceEditBox
            // 
            this.priceEditBox.Increment = new decimal(new int[] {
            50000,
            0,
            0,
            0});
            this.priceEditBox.Location = new System.Drawing.Point(93, 112);
            this.priceEditBox.Maximum = new decimal(new int[] {
            1410065407,
            2,
            0,
            0});
            this.priceEditBox.Name = "priceEditBox";
            this.priceEditBox.Size = new System.Drawing.Size(323, 20);
            this.priceEditBox.TabIndex = 21;
            this.priceEditBox.ThousandsSeparator = true;
            // 
            // cleanButton
            // 
            this.cleanButton.Location = new System.Drawing.Point(422, 4);
            this.cleanButton.Name = "cleanButton";
            this.cleanButton.Size = new System.Drawing.Size(72, 23);
            this.cleanButton.TabIndex = 20;
            this.cleanButton.Text = "Очистить";
            this.cleanButton.UseVisualStyleBackColor = true;
            this.cleanButton.Click += new System.EventHandler(this.cleanButton_Click);
            // 
            // saveInfoButton
            // 
            this.saveInfoButton.Location = new System.Drawing.Point(93, 164);
            this.saveInfoButton.Name = "saveInfoButton";
            this.saveInfoButton.Size = new System.Drawing.Size(323, 34);
            this.saveInfoButton.TabIndex = 19;
            this.saveInfoButton.Text = "Сохранить информацию";
            this.saveInfoButton.UseVisualStyleBackColor = true;
            this.saveInfoButton.Click += new System.EventHandler(this.saveInfoButton_Click);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(5, 140);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(60, 13);
            this.label9.TabIndex = 18;
            this.label9.Text = "Фото URL";
            // 
            // photoEditBox
            // 
            this.photoEditBox.Location = new System.Drawing.Point(93, 137);
            this.photoEditBox.Name = "photoEditBox";
            this.photoEditBox.Size = new System.Drawing.Size(323, 20);
            this.photoEditBox.TabIndex = 17;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(5, 114);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(33, 13);
            this.label5.TabIndex = 16;
            this.label5.Text = "Цена";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(5, 88);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(63, 13);
            this.label6.TabIndex = 15;
            this.label6.Text = "Процессор";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(5, 62);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(22, 13);
            this.label7.TabIndex = 14;
            this.label7.Text = "ОС";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(5, 10);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(86, 13);
            this.label11.TabIndex = 13;
            this.label11.Text = "Производитель";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(5, 36);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(46, 13);
            this.label8.TabIndex = 13;
            this.label8.Text = "Модель";
            // 
            // cpuEditBox
            // 
            this.cpuEditBox.Location = new System.Drawing.Point(93, 85);
            this.cpuEditBox.Name = "cpuEditBox";
            this.cpuEditBox.Size = new System.Drawing.Size(323, 20);
            this.cpuEditBox.TabIndex = 11;
            // 
            // osEditBox
            // 
            this.osEditBox.Location = new System.Drawing.Point(93, 59);
            this.osEditBox.Name = "osEditBox";
            this.osEditBox.Size = new System.Drawing.Size(323, 20);
            this.osEditBox.TabIndex = 10;
            // 
            // manufacturerEditBox
            // 
            this.manufacturerEditBox.Location = new System.Drawing.Point(93, 7);
            this.manufacturerEditBox.Name = "manufacturerEditBox";
            this.manufacturerEditBox.Size = new System.Drawing.Size(323, 20);
            this.manufacturerEditBox.TabIndex = 9;
            // 
            // modelEditBox
            // 
            this.modelEditBox.Location = new System.Drawing.Point(93, 33);
            this.modelEditBox.Name = "modelEditBox";
            this.modelEditBox.Size = new System.Drawing.Size(323, 20);
            this.modelEditBox.TabIndex = 9;
            // 
            // saveDataButton
            // 
            this.saveDataButton.Location = new System.Drawing.Point(12, 328);
            this.saveDataButton.Name = "saveDataButton";
            this.saveDataButton.Size = new System.Drawing.Size(197, 30);
            this.saveDataButton.TabIndex = 2;
            this.saveDataButton.Text = "Сохранить в файл";
            this.saveDataButton.UseVisualStyleBackColor = true;
            this.saveDataButton.Click += new System.EventHandler(this.saveDataButton_Click);
            // 
            // loadDataButton
            // 
            this.loadDataButton.Location = new System.Drawing.Point(12, 364);
            this.loadDataButton.Name = "loadDataButton";
            this.loadDataButton.Size = new System.Drawing.Size(197, 30);
            this.loadDataButton.TabIndex = 3;
            this.loadDataButton.Text = "Загрузить из файла";
            this.loadDataButton.UseVisualStyleBackColor = true;
            this.loadDataButton.Click += new System.EventHandler(this.loadDataButton_Click);
            // 
            // deletePhoneButton
            // 
            this.deletePhoneButton.Location = new System.Drawing.Point(12, 292);
            this.deletePhoneButton.Name = "deletePhoneButton";
            this.deletePhoneButton.Size = new System.Drawing.Size(197, 30);
            this.deletePhoneButton.TabIndex = 4;
            this.deletePhoneButton.Text = "Удалить";
            this.deletePhoneButton.UseVisualStyleBackColor = true;
            this.deletePhoneButton.Click += new System.EventHandler(this.deletePhoneButton_Click);
            // 
            // addPhoneButton
            // 
            this.addPhoneButton.Location = new System.Drawing.Point(12, 256);
            this.addPhoneButton.Name = "addPhoneButton";
            this.addPhoneButton.Size = new System.Drawing.Size(197, 30);
            this.addPhoneButton.TabIndex = 5;
            this.addPhoneButton.Text = "Добавить";
            this.addPhoneButton.UseVisualStyleBackColor = true;
            this.addPhoneButton.Click += new System.EventHandler(this.addPhoneButton_Click);
            // 
            // modelTextBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(735, 447);
            this.Controls.Add(this.addPhoneButton);
            this.Controls.Add(this.deletePhoneButton);
            this.Controls.Add(this.loadDataButton);
            this.Controls.Add(this.saveDataButton);
            this.Controls.Add(this.tabControl);
            this.Controls.Add(this.phonesListBox);
            this.Name = "modelTextBox";
            this.Text = "Mobile store";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tabControl.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.phonePictureBox)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.priceEditBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox phonesListBox;
        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.PictureBox phonePictureBox;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TextBox priceTextBox;
        private System.Windows.Forms.TextBox cpuTextBox;
        private System.Windows.Forms.TextBox osTextBox;
        private System.Windows.Forms.TextBox modelTextBox_;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button cleanButton;
        private System.Windows.Forms.Button saveInfoButton;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox photoEditBox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox cpuEditBox;
        private System.Windows.Forms.TextBox osEditBox;
        private System.Windows.Forms.TextBox modelEditBox;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox manufacturerTextBox;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox manufacturerEditBox;
        private System.Windows.Forms.NumericUpDown priceEditBox;
        private System.Windows.Forms.Button saveDataButton;
        private System.Windows.Forms.Button loadDataButton;
        private System.Windows.Forms.Button deletePhoneButton;
        private System.Windows.Forms.Button addPhoneButton;
    }
}

