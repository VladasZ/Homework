namespace MDItest
{
    partial class AddBookForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.nameTextBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.addBookButton = new System.Windows.Forms.Button();
            this.genreComboBox = new System.Windows.Forms.ComboBox();
            this.publisherComboBox = new System.Windows.Forms.ComboBox();
            this.addBookTypeButton = new System.Windows.Forms.Button();
            this.addPublisherButton = new System.Windows.Forms.Button();
            this.cancelAddBookButton = new System.Windows.Forms.Button();
            this.clearButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Название:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(51, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(39, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Жанр:";
            // 
            // nameTextBox
            // 
            this.nameTextBox.Location = new System.Drawing.Point(93, 12);
            this.nameTextBox.Name = "nameTextBox";
            this.nameTextBox.Size = new System.Drawing.Size(296, 20);
            this.nameTextBox.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(8, 67);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(82, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Издательство:";
            // 
            // addBookButton
            // 
            this.addBookButton.Location = new System.Drawing.Point(314, 90);
            this.addBookButton.Name = "addBookButton";
            this.addBookButton.Size = new System.Drawing.Size(75, 23);
            this.addBookButton.TabIndex = 6;
            this.addBookButton.Text = "Добавить";
            this.addBookButton.UseVisualStyleBackColor = true;
            this.addBookButton.Click += new System.EventHandler(this.addBookButton_Click);
            // 
            // genreComboBox
            // 
            this.genreComboBox.FormattingEnabled = true;
            this.genreComboBox.Location = new System.Drawing.Point(93, 38);
            this.genreComboBox.Name = "genreComboBox";
            this.genreComboBox.Size = new System.Drawing.Size(295, 21);
            this.genreComboBox.TabIndex = 7;
            // 
            // publisherComboBox
            // 
            this.publisherComboBox.FormattingEnabled = true;
            this.publisherComboBox.Location = new System.Drawing.Point(93, 64);
            this.publisherComboBox.Name = "publisherComboBox";
            this.publisherComboBox.Size = new System.Drawing.Size(295, 21);
            this.publisherComboBox.TabIndex = 8;
            // 
            // addBookTypeButton
            // 
            this.addBookTypeButton.Location = new System.Drawing.Point(394, 37);
            this.addBookTypeButton.Name = "addBookTypeButton";
            this.addBookTypeButton.Size = new System.Drawing.Size(21, 21);
            this.addBookTypeButton.TabIndex = 9;
            this.addBookTypeButton.Text = "+";
            this.addBookTypeButton.UseVisualStyleBackColor = true;
            this.addBookTypeButton.Click += new System.EventHandler(this.addBookTypeButton_Click);
            // 
            // addPublisherButton
            // 
            this.addPublisherButton.Location = new System.Drawing.Point(394, 64);
            this.addPublisherButton.Name = "addPublisherButton";
            this.addPublisherButton.Size = new System.Drawing.Size(21, 21);
            this.addPublisherButton.TabIndex = 10;
            this.addPublisherButton.Text = "+";
            this.addPublisherButton.UseVisualStyleBackColor = true;
            this.addPublisherButton.Click += new System.EventHandler(this.addPublisherButton_Click);
            // 
            // cancelAddBookButton
            // 
            this.cancelAddBookButton.Location = new System.Drawing.Point(233, 90);
            this.cancelAddBookButton.Name = "cancelAddBookButton";
            this.cancelAddBookButton.Size = new System.Drawing.Size(75, 23);
            this.cancelAddBookButton.TabIndex = 11;
            this.cancelAddBookButton.Text = "Отменить";
            this.cancelAddBookButton.UseVisualStyleBackColor = true;
            this.cancelAddBookButton.Click += new System.EventHandler(this.cancelAddBookButton_Click);
            // 
            // clearButton
            // 
            this.clearButton.Location = new System.Drawing.Point(11, 90);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(75, 23);
            this.clearButton.TabIndex = 12;
            this.clearButton.Text = "Очистить";
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // AddBookForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(419, 116);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.cancelAddBookButton);
            this.Controls.Add(this.addPublisherButton);
            this.Controls.Add(this.addBookTypeButton);
            this.Controls.Add(this.publisherComboBox);
            this.Controls.Add(this.genreComboBox);
            this.Controls.Add(this.addBookButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.nameTextBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "AddBookForm";
            this.Text = "Добавить книгу";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox nameTextBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button addBookButton;
        private System.Windows.Forms.ComboBox genreComboBox;
        private System.Windows.Forms.ComboBox publisherComboBox;
        private System.Windows.Forms.Button addBookTypeButton;
        private System.Windows.Forms.Button addPublisherButton;
        private System.Windows.Forms.Button cancelAddBookButton;
        private System.Windows.Forms.Button clearButton;
    }
}