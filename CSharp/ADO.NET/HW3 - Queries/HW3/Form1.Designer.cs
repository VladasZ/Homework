namespace HW3
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
            this.dataGridView = new System.Windows.Forms.DataGridView();
            this.allCdsButton = new System.Windows.Forms.Button();
            this.artistsAfterUSSRButton = new System.Windows.Forms.Button();
            this.allCountriesButton = new System.Windows.Forms.Button();
            this.USAAlbums = new System.Windows.Forms.Button();
            this.albumsInCountryPrice = new System.Windows.Forms.Button();
            this.companyAlbumsCount = new System.Windows.Forms.Button();
            this.mostExpensiveAlbum = new System.Windows.Forms.Button();
            this.producerAlbumsCount = new System.Windows.Forms.Button();
            this.lastAwardProducer = new System.Windows.Forms.Button();
            this.theCheapestAlbum = new System.Windows.Forms.Button();
            this.sortedAlbums = new System.Windows.Forms.Button();
            this.allProducersButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView
            // 
            this.dataGridView.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView.Location = new System.Drawing.Point(12, 12);
            this.dataGridView.Name = "dataGridView";
            this.dataGridView.Size = new System.Drawing.Size(656, 339);
            this.dataGridView.TabIndex = 2;
            // 
            // allCdsButton
            // 
            this.allCdsButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.allCdsButton.Location = new System.Drawing.Point(674, 12);
            this.allCdsButton.Name = "allCdsButton";
            this.allCdsButton.Size = new System.Drawing.Size(258, 23);
            this.allCdsButton.TabIndex = 4;
            this.allCdsButton.Text = "Все CD";
            this.allCdsButton.UseVisualStyleBackColor = true;
            this.allCdsButton.Click += new System.EventHandler(this.allCdsButton_Click);
            // 
            // artistsAfterUSSRButton
            // 
            this.artistsAfterUSSRButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.artistsAfterUSSRButton.Location = new System.Drawing.Point(674, 70);
            this.artistsAfterUSSRButton.Name = "artistsAfterUSSRButton";
            this.artistsAfterUSSRButton.Size = new System.Drawing.Size(258, 23);
            this.artistsAfterUSSRButton.TabIndex = 5;
            this.artistsAfterUSSRButton.Text = "Артисты после распада СССР";
            this.artistsAfterUSSRButton.UseVisualStyleBackColor = true;
            this.artistsAfterUSSRButton.Click += new System.EventHandler(this.artistsAfterUSSRButton_Click);
            // 
            // allCountriesButton
            // 
            this.allCountriesButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.allCountriesButton.Location = new System.Drawing.Point(674, 99);
            this.allCountriesButton.Name = "allCountriesButton";
            this.allCountriesButton.Size = new System.Drawing.Size(258, 23);
            this.allCountriesButton.TabIndex = 6;
            this.allCountriesButton.Text = "Все страны";
            this.allCountriesButton.UseVisualStyleBackColor = true;
            this.allCountriesButton.Click += new System.EventHandler(this.allCountriesButton_Click);
            // 
            // USAAlbums
            // 
            this.USAAlbums.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.USAAlbums.Location = new System.Drawing.Point(674, 128);
            this.USAAlbums.Name = "USAAlbums";
            this.USAAlbums.Size = new System.Drawing.Size(258, 23);
            this.USAAlbums.TabIndex = 7;
            this.USAAlbums.Text = "Альбомы США по году выпуска";
            this.USAAlbums.UseVisualStyleBackColor = true;
            this.USAAlbums.Click += new System.EventHandler(this.USAAlbums_Click);
            // 
            // albumsInCountryPrice
            // 
            this.albumsInCountryPrice.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.albumsInCountryPrice.Location = new System.Drawing.Point(674, 157);
            this.albumsInCountryPrice.Name = "albumsInCountryPrice";
            this.albumsInCountryPrice.Size = new System.Drawing.Size(258, 23);
            this.albumsInCountryPrice.TabIndex = 8;
            this.albumsInCountryPrice.Text = "Стоимость альбомов за страну";
            this.albumsInCountryPrice.UseVisualStyleBackColor = true;
            this.albumsInCountryPrice.Click += new System.EventHandler(this.albumsInCountryPrice_Click);
            // 
            // companyAlbumsCount
            // 
            this.companyAlbumsCount.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.companyAlbumsCount.Location = new System.Drawing.Point(674, 186);
            this.companyAlbumsCount.Name = "companyAlbumsCount";
            this.companyAlbumsCount.Size = new System.Drawing.Size(258, 23);
            this.companyAlbumsCount.TabIndex = 9;
            this.companyAlbumsCount.Text = "Компания и кол-во альбомов за год";
            this.companyAlbumsCount.UseVisualStyleBackColor = true;
            this.companyAlbumsCount.Click += new System.EventHandler(this.companyAlbumsCount_Click);
            // 
            // mostExpensiveAlbum
            // 
            this.mostExpensiveAlbum.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.mostExpensiveAlbum.Location = new System.Drawing.Point(674, 215);
            this.mostExpensiveAlbum.Name = "mostExpensiveAlbum";
            this.mostExpensiveAlbum.Size = new System.Drawing.Size(258, 23);
            this.mostExpensiveAlbum.TabIndex = 10;
            this.mostExpensiveAlbum.Text = "Самый дорогой альбом и продюссер";
            this.mostExpensiveAlbum.UseVisualStyleBackColor = true;
            // 
            // producerAlbumsCount
            // 
            this.producerAlbumsCount.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.producerAlbumsCount.Location = new System.Drawing.Point(674, 244);
            this.producerAlbumsCount.Name = "producerAlbumsCount";
            this.producerAlbumsCount.Size = new System.Drawing.Size(258, 23);
            this.producerAlbumsCount.TabIndex = 11;
            this.producerAlbumsCount.Text = "Количества альбомов у продюссера 1988-1990";
            this.producerAlbumsCount.UseVisualStyleBackColor = true;
            this.producerAlbumsCount.Click += new System.EventHandler(this.producerAlbumsCount_Click);
            // 
            // lastAwardProducer
            // 
            this.lastAwardProducer.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lastAwardProducer.Location = new System.Drawing.Point(674, 273);
            this.lastAwardProducer.Name = "lastAwardProducer";
            this.lastAwardProducer.Size = new System.Drawing.Size(258, 23);
            this.lastAwardProducer.TabIndex = 12;
            this.lastAwardProducer.Text = "Продюссер получивший премию последним";
            this.lastAwardProducer.UseVisualStyleBackColor = true;
            this.lastAwardProducer.Click += new System.EventHandler(this.lastAwardProducer_Click);
            // 
            // theCheapestAlbum
            // 
            this.theCheapestAlbum.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.theCheapestAlbum.Location = new System.Drawing.Point(674, 299);
            this.theCheapestAlbum.Name = "theCheapestAlbum";
            this.theCheapestAlbum.Size = new System.Drawing.Size(258, 23);
            this.theCheapestAlbum.TabIndex = 13;
            this.theCheapestAlbum.Text = "Самый дешевый альбом";
            this.theCheapestAlbum.UseVisualStyleBackColor = true;
            // 
            // sortedAlbums
            // 
            this.sortedAlbums.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.sortedAlbums.Location = new System.Drawing.Point(674, 328);
            this.sortedAlbums.Name = "sortedAlbums";
            this.sortedAlbums.Size = new System.Drawing.Size(258, 23);
            this.sortedAlbums.TabIndex = 14;
            this.sortedAlbums.Text = "Отсортированные альбомы";
            this.sortedAlbums.UseVisualStyleBackColor = true;
            this.sortedAlbums.Click += new System.EventHandler(this.sortedAlbums_Click);
            // 
            // allProducersButton
            // 
            this.allProducersButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.allProducersButton.Location = new System.Drawing.Point(674, 41);
            this.allProducersButton.Name = "allProducersButton";
            this.allProducersButton.Size = new System.Drawing.Size(258, 23);
            this.allProducersButton.TabIndex = 15;
            this.allProducersButton.Text = "Все продюссеры";
            this.allProducersButton.UseVisualStyleBackColor = true;
            this.allProducersButton.Click += new System.EventHandler(this.allProducersButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(944, 357);
            this.Controls.Add(this.allProducersButton);
            this.Controls.Add(this.sortedAlbums);
            this.Controls.Add(this.theCheapestAlbum);
            this.Controls.Add(this.lastAwardProducer);
            this.Controls.Add(this.producerAlbumsCount);
            this.Controls.Add(this.mostExpensiveAlbum);
            this.Controls.Add(this.companyAlbumsCount);
            this.Controls.Add(this.albumsInCountryPrice);
            this.Controls.Add(this.USAAlbums);
            this.Controls.Add(this.allCountriesButton);
            this.Controls.Add(this.artistsAfterUSSRButton);
            this.Controls.Add(this.allCdsButton);
            this.Controls.Add(this.dataGridView);
            this.Name = "Form1";
            this.Text = "Альбомы";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView;
        private System.Windows.Forms.Button allCdsButton;
        private System.Windows.Forms.Button artistsAfterUSSRButton;
        private System.Windows.Forms.Button allCountriesButton;
        private System.Windows.Forms.Button USAAlbums;
        private System.Windows.Forms.Button albumsInCountryPrice;
        private System.Windows.Forms.Button companyAlbumsCount;
        private System.Windows.Forms.Button mostExpensiveAlbum;
        private System.Windows.Forms.Button producerAlbumsCount;
        private System.Windows.Forms.Button lastAwardProducer;
        private System.Windows.Forms.Button theCheapestAlbum;
        private System.Windows.Forms.Button sortedAlbums;
        private System.Windows.Forms.Button allProducersButton;

    }
}

