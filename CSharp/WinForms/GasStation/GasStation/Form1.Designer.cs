namespace GasStation
{
    partial class Form1
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
            this.fuelGroupBox = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.summRadioButton = new System.Windows.Forms.RadioButton();
            this.amountRadioButton = new System.Windows.Forms.RadioButton();
            this.fuelTotalPriceTextBox = new System.Windows.Forms.TextBox();
            this.fuelAmountTextBox = new System.Windows.Forms.TextBox();
            this.fuePerLiterlPriceTextBox = new System.Windows.Forms.TextBox();
            this.fuelTypeComboBox = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.miniCafeeGroupBox = new System.Windows.Forms.GroupBox();
            this.cocacolaCheckBox = new System.Windows.Forms.CheckBox();
            this.cheeseburderCheckBox = new System.Windows.Forms.CheckBox();
            this.hamburgerCheckBox = new System.Windows.Forms.CheckBox();
            this.hotDogCheckBox = new System.Windows.Forms.CheckBox();
            this.cocacolaPriceTextBox = new System.Windows.Forms.TextBox();
            this.cheeseBurgerPriceTextBox = new System.Windows.Forms.TextBox();
            this.hamburgerPriceTextBox = new System.Windows.Forms.TextBox();
            this.hotDogPriceTextBox = new System.Windows.Forms.TextBox();
            this.fuelPayGroupBox = new System.Windows.Forms.GroupBox();
            this.fuelToPayTexBox = new System.Windows.Forms.TextBox();
            this.cafeePayGroupBox4 = new System.Windows.Forms.GroupBox();
            this.cafeeToPayTextBox = new System.Windows.Forms.TextBox();
            this.totalBillTextBox = new System.Windows.Forms.TextBox();
            this.fuelGroupBox.SuspendLayout();
            this.miniCafeeGroupBox.SuspendLayout();
            this.fuelPayGroupBox.SuspendLayout();
            this.cafeePayGroupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // fuelGroupBox
            // 
            this.fuelGroupBox.Controls.Add(this.label3);
            this.fuelGroupBox.Controls.Add(this.label2);
            this.fuelGroupBox.Controls.Add(this.summRadioButton);
            this.fuelGroupBox.Controls.Add(this.amountRadioButton);
            this.fuelGroupBox.Controls.Add(this.fuelTotalPriceTextBox);
            this.fuelGroupBox.Controls.Add(this.fuelAmountTextBox);
            this.fuelGroupBox.Controls.Add(this.fuePerLiterlPriceTextBox);
            this.fuelGroupBox.Controls.Add(this.fuelTypeComboBox);
            this.fuelGroupBox.Controls.Add(this.label5);
            this.fuelGroupBox.Controls.Add(this.label4);
            this.fuelGroupBox.Controls.Add(this.label1);
            this.fuelGroupBox.Location = new System.Drawing.Point(12, 12);
            this.fuelGroupBox.Name = "fuelGroupBox";
            this.fuelGroupBox.Size = new System.Drawing.Size(330, 211);
            this.fuelGroupBox.TabIndex = 0;
            this.fuelGroupBox.TabStop = false;
            this.fuelGroupBox.Text = "Топливо";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.ForeColor = System.Drawing.SystemColors.Desktop;
            this.label3.Location = new System.Drawing.Point(289, 130);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(18, 13);
            this.label3.TabIndex = 12;
            this.label3.Text = "л.";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.ForeColor = System.Drawing.SystemColors.Desktop;
            this.label2.Location = new System.Drawing.Point(289, 178);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(31, 13);
            this.label2.TabIndex = 11;
            this.label2.Text = "руб.";
            // 
            // summRadioButton
            // 
            this.summRadioButton.AutoSize = true;
            this.summRadioButton.Location = new System.Drawing.Point(9, 174);
            this.summRadioButton.Name = "summRadioButton";
            this.summRadioButton.Size = new System.Drawing.Size(59, 17);
            this.summRadioButton.TabIndex = 10;
            this.summRadioButton.TabStop = true;
            this.summRadioButton.Text = "Сумма";
            this.summRadioButton.UseVisualStyleBackColor = true;
            // 
            // amountRadioButton
            // 
            this.amountRadioButton.AutoSize = true;
            this.amountRadioButton.Location = new System.Drawing.Point(9, 126);
            this.amountRadioButton.Name = "amountRadioButton";
            this.amountRadioButton.Size = new System.Drawing.Size(84, 17);
            this.amountRadioButton.TabIndex = 9;
            this.amountRadioButton.TabStop = true;
            this.amountRadioButton.Text = "Количество";
            this.amountRadioButton.UseVisualStyleBackColor = true;
            // 
            // fuelTotalPriceTextBox
            // 
            this.fuelTotalPriceTextBox.Location = new System.Drawing.Point(149, 174);
            this.fuelTotalPriceTextBox.Name = "fuelTotalPriceTextBox";
            this.fuelTotalPriceTextBox.Size = new System.Drawing.Size(134, 20);
            this.fuelTotalPriceTextBox.TabIndex = 8;
            // 
            // fuelAmountTextBox
            // 
            this.fuelAmountTextBox.Location = new System.Drawing.Point(149, 125);
            this.fuelAmountTextBox.Name = "fuelAmountTextBox";
            this.fuelAmountTextBox.Size = new System.Drawing.Size(134, 20);
            this.fuelAmountTextBox.TabIndex = 7;
            // 
            // fuePerLiterlPriceTextBox
            // 
            this.fuePerLiterlPriceTextBox.Location = new System.Drawing.Point(70, 74);
            this.fuePerLiterlPriceTextBox.Name = "fuePerLiterlPriceTextBox";
            this.fuePerLiterlPriceTextBox.Size = new System.Drawing.Size(213, 20);
            this.fuePerLiterlPriceTextBox.TabIndex = 6;
            this.fuePerLiterlPriceTextBox.Text = "fsdfds";
            // 
            // fuelTypeComboBox
            // 
            this.fuelTypeComboBox.FormattingEnabled = true;
            this.fuelTypeComboBox.Location = new System.Drawing.Point(70, 16);
            this.fuelTypeComboBox.Name = "fuelTypeComboBox";
            this.fuelTypeComboBox.Size = new System.Drawing.Size(213, 21);
            this.fuelTypeComboBox.TabIndex = 5;
            this.fuelTypeComboBox.SelectedIndexChanged += new System.EventHandler(this.fuelTypeComboBox_SelectedIndexChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.ForeColor = System.Drawing.Color.Red;
            this.label5.Location = new System.Drawing.Point(289, 77);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(31, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "руб.";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.ForeColor = System.Drawing.Color.Red;
            this.label4.Location = new System.Drawing.Point(6, 77);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(37, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Цена";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.label1.Location = new System.Drawing.Point(6, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Бензин";
            // 
            // miniCafeeGroupBox
            // 
            this.miniCafeeGroupBox.Controls.Add(this.cocacolaCheckBox);
            this.miniCafeeGroupBox.Controls.Add(this.cheeseburderCheckBox);
            this.miniCafeeGroupBox.Controls.Add(this.hamburgerCheckBox);
            this.miniCafeeGroupBox.Controls.Add(this.hotDogCheckBox);
            this.miniCafeeGroupBox.Controls.Add(this.cocacolaPriceTextBox);
            this.miniCafeeGroupBox.Controls.Add(this.cheeseBurgerPriceTextBox);
            this.miniCafeeGroupBox.Controls.Add(this.hamburgerPriceTextBox);
            this.miniCafeeGroupBox.Controls.Add(this.hotDogPriceTextBox);
            this.miniCafeeGroupBox.Location = new System.Drawing.Point(348, 12);
            this.miniCafeeGroupBox.Name = "miniCafeeGroupBox";
            this.miniCafeeGroupBox.Size = new System.Drawing.Size(330, 211);
            this.miniCafeeGroupBox.TabIndex = 1;
            this.miniCafeeGroupBox.TabStop = false;
            this.miniCafeeGroupBox.Text = "Мини-кафе";
            // 
            // cocacolaCheckBox
            // 
            this.cocacolaCheckBox.AutoSize = true;
            this.cocacolaCheckBox.Location = new System.Drawing.Point(7, 122);
            this.cocacolaCheckBox.Name = "cocacolaCheckBox";
            this.cocacolaCheckBox.Size = new System.Drawing.Size(78, 17);
            this.cocacolaCheckBox.TabIndex = 18;
            this.cocacolaCheckBox.Text = "Кока-кола";
            this.cocacolaCheckBox.UseVisualStyleBackColor = true;
            // 
            // cheeseburderCheckBox
            // 
            this.cheeseburderCheckBox.AutoSize = true;
            this.cheeseburderCheckBox.Location = new System.Drawing.Point(7, 96);
            this.cheeseburderCheckBox.Name = "cheeseburderCheckBox";
            this.cheeseburderCheckBox.Size = new System.Drawing.Size(80, 17);
            this.cheeseburderCheckBox.TabIndex = 17;
            this.cheeseburderCheckBox.Text = "Чизбургер";
            this.cheeseburderCheckBox.UseVisualStyleBackColor = true;
            // 
            // hamburgerCheckBox
            // 
            this.hamburgerCheckBox.AutoSize = true;
            this.hamburgerCheckBox.Location = new System.Drawing.Point(7, 70);
            this.hamburgerCheckBox.Name = "hamburgerCheckBox";
            this.hamburgerCheckBox.Size = new System.Drawing.Size(80, 17);
            this.hamburgerCheckBox.TabIndex = 16;
            this.hamburgerCheckBox.Text = "Гамбургер";
            this.hamburgerCheckBox.UseVisualStyleBackColor = true;
            // 
            // hotDogCheckBox
            // 
            this.hotDogCheckBox.AutoSize = true;
            this.hotDogCheckBox.Location = new System.Drawing.Point(7, 44);
            this.hotDogCheckBox.Name = "hotDogCheckBox";
            this.hotDogCheckBox.Size = new System.Drawing.Size(64, 17);
            this.hotDogCheckBox.TabIndex = 15;
            this.hotDogCheckBox.Text = "Хот-дог";
            this.hotDogCheckBox.UseVisualStyleBackColor = true;
            // 
            // cocacolaPriceTextBox
            // 
            this.cocacolaPriceTextBox.Location = new System.Drawing.Point(111, 120);
            this.cocacolaPriceTextBox.Name = "cocacolaPriceTextBox";
            this.cocacolaPriceTextBox.Size = new System.Drawing.Size(213, 20);
            this.cocacolaPriceTextBox.TabIndex = 14;
            // 
            // cheeseBurgerPriceTextBox
            // 
            this.cheeseBurgerPriceTextBox.Location = new System.Drawing.Point(111, 94);
            this.cheeseBurgerPriceTextBox.Name = "cheeseBurgerPriceTextBox";
            this.cheeseBurgerPriceTextBox.Size = new System.Drawing.Size(213, 20);
            this.cheeseBurgerPriceTextBox.TabIndex = 13;
            // 
            // hamburgerPriceTextBox
            // 
            this.hamburgerPriceTextBox.Location = new System.Drawing.Point(111, 68);
            this.hamburgerPriceTextBox.Name = "hamburgerPriceTextBox";
            this.hamburgerPriceTextBox.Size = new System.Drawing.Size(213, 20);
            this.hamburgerPriceTextBox.TabIndex = 12;
            // 
            // hotDogPriceTextBox
            // 
            this.hotDogPriceTextBox.Location = new System.Drawing.Point(111, 42);
            this.hotDogPriceTextBox.Name = "hotDogPriceTextBox";
            this.hotDogPriceTextBox.Size = new System.Drawing.Size(213, 20);
            this.hotDogPriceTextBox.TabIndex = 11;
            // 
            // fuelPayGroupBox
            // 
            this.fuelPayGroupBox.Controls.Add(this.fuelToPayTexBox);
            this.fuelPayGroupBox.Location = new System.Drawing.Point(12, 231);
            this.fuelPayGroupBox.Name = "fuelPayGroupBox";
            this.fuelPayGroupBox.Size = new System.Drawing.Size(330, 98);
            this.fuelPayGroupBox.TabIndex = 2;
            this.fuelPayGroupBox.TabStop = false;
            this.fuelPayGroupBox.Text = "К оплате";
            // 
            // fuelToPayTexBox
            // 
            this.fuelToPayTexBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.fuelToPayTexBox.Location = new System.Drawing.Point(9, 19);
            this.fuelToPayTexBox.Name = "fuelToPayTexBox";
            this.fuelToPayTexBox.Size = new System.Drawing.Size(315, 62);
            this.fuelToPayTexBox.TabIndex = 9;
            // 
            // cafeePayGroupBox4
            // 
            this.cafeePayGroupBox4.Controls.Add(this.cafeeToPayTextBox);
            this.cafeePayGroupBox4.Location = new System.Drawing.Point(348, 231);
            this.cafeePayGroupBox4.Name = "cafeePayGroupBox4";
            this.cafeePayGroupBox4.Size = new System.Drawing.Size(330, 98);
            this.cafeePayGroupBox4.TabIndex = 3;
            this.cafeePayGroupBox4.TabStop = false;
            this.cafeePayGroupBox4.Text = "К оплате";
            // 
            // cafeeToPayTextBox
            // 
            this.cafeeToPayTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.cafeeToPayTextBox.Location = new System.Drawing.Point(6, 19);
            this.cafeeToPayTextBox.Name = "cafeeToPayTextBox";
            this.cafeeToPayTextBox.Size = new System.Drawing.Size(318, 62);
            this.cafeeToPayTextBox.TabIndex = 10;
            // 
            // totalBillTextBox
            // 
            this.totalBillTextBox.Location = new System.Drawing.Point(459, 371);
            this.totalBillTextBox.Name = "totalBillTextBox";
            this.totalBillTextBox.Size = new System.Drawing.Size(213, 20);
            this.totalBillTextBox.TabIndex = 15;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(690, 428);
            this.Controls.Add(this.totalBillTextBox);
            this.Controls.Add(this.cafeePayGroupBox4);
            this.Controls.Add(this.fuelPayGroupBox);
            this.Controls.Add(this.miniCafeeGroupBox);
            this.Controls.Add(this.fuelGroupBox);
            this.Name = "Form1";
            this.Text = "Автозаправка";
            this.fuelGroupBox.ResumeLayout(false);
            this.fuelGroupBox.PerformLayout();
            this.miniCafeeGroupBox.ResumeLayout(false);
            this.miniCafeeGroupBox.PerformLayout();
            this.fuelPayGroupBox.ResumeLayout(false);
            this.fuelPayGroupBox.PerformLayout();
            this.cafeePayGroupBox4.ResumeLayout(false);
            this.cafeePayGroupBox4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox fuelGroupBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.RadioButton summRadioButton;
        private System.Windows.Forms.RadioButton amountRadioButton;
        private System.Windows.Forms.TextBox fuelTotalPriceTextBox;
        private System.Windows.Forms.TextBox fuelAmountTextBox;
        private System.Windows.Forms.TextBox fuePerLiterlPriceTextBox;
        private System.Windows.Forms.ComboBox fuelTypeComboBox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox miniCafeeGroupBox;
        private System.Windows.Forms.TextBox cocacolaPriceTextBox;
        private System.Windows.Forms.TextBox cheeseBurgerPriceTextBox;
        private System.Windows.Forms.TextBox hamburgerPriceTextBox;
        private System.Windows.Forms.TextBox hotDogPriceTextBox;
        private System.Windows.Forms.GroupBox fuelPayGroupBox;
        private System.Windows.Forms.TextBox fuelToPayTexBox;
        private System.Windows.Forms.GroupBox cafeePayGroupBox4;
        private System.Windows.Forms.TextBox cafeeToPayTextBox;
        private System.Windows.Forms.TextBox totalBillTextBox;
        private System.Windows.Forms.CheckBox cocacolaCheckBox;
        private System.Windows.Forms.CheckBox cheeseburderCheckBox;
        private System.Windows.Forms.CheckBox hamburgerCheckBox;
        private System.Windows.Forms.CheckBox hotDogCheckBox;
    }
}

