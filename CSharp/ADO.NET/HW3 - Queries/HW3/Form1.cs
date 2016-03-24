using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml.Serialization;
using System.IO;


namespace HW3
{
    public partial class Form1 : Form
    {

        List<CD> cds;
        List<PRODUCER> producers;

        const string cdsDataPath = "cd_catalog.xml";
        const string producersDataPath = "cd_catalog _2.xml";


        public Form1()
        {
            InitializeComponent();
            StartPosition = FormStartPosition.CenterScreen;
        }



        private void Form1_Load(object sender, EventArgs e)
        {
            //cds load

            XmlSerializer mySerializer = new XmlSerializer(typeof(List<CD>));

            StreamReader myReader = new StreamReader(cdsDataPath);

            cds = (List<CD>)mySerializer.Deserialize(myReader);

            dataGridView.DataSource = cds;

            myReader.Close();

            //producers load

            mySerializer = new XmlSerializer(typeof(List<PRODUCER>));

            myReader = new StreamReader(producersDataPath);

            producers = (List<PRODUCER>)mySerializer.Deserialize(myReader);

            myReader.Close();


        }

        private void allProducersButton_Click(object sender, EventArgs e)
        {
            dataGridView.DataSource = producers;
        }

        private void allCdsButton_Click(object sender, EventArgs e)
        {
            dataGridView.DataSource = cds;
        }

        private void artistsAfterUSSRButton_Click(object sender, EventArgs e)
        {
            var artistsAfterUSSR = from cd in cds
                                   where cd.YEAR > 1991
                                   select new { cd.ARTIST };

            dataGridView.DataSource = artistsAfterUSSR.ToArray();
        }

        private void allCountriesButton_Click(object sender, EventArgs e)
        {
            var allCountries = from cd in cds
                               select new { cd.COUNTRY };

            dataGridView.DataSource = allCountries.Distinct().ToArray();
        }

        private void USAAlbums_Click(object sender, EventArgs e)
        {
            var USAAbums = from cd in cds
                           where cd.COUNTRY == "USA"
                           orderby cd.YEAR
                           select new { cd.TITLE };

            dataGridView.DataSource = USAAbums.ToArray();
        }

        private void albumsInCountryPrice_Click(object sender, EventArgs e)
        {
            var albumsPrice = from cd in cds
                              group cd by cd.COUNTRY into gr
                              select new { COUNTRY = gr.Key, TOTAL_PRICE = gr.Sum(cd => cd.PRICE) };

            dataGridView.DataSource = albumsPrice.ToArray();
        }

        private void companyAlbumsCount_Click(object sender, EventArgs e)
        {
            var allCompanies = from cd in cds
                               select new { cd.COMPANY };

            dataGridView.DataSource = allCompanies.Distinct().ToArray();
        }

        private void sortedAlbums_Click(object sender, EventArgs e)
        {
            var sortedAlbums = cds
                .OrderBy(cd => cd.YEAR)
                .ThenBy(cd => cd.PRICE)
                .ThenBy(cd => cd.TITLE);

            dataGridView.DataSource = sortedAlbums.ToArray();                                  
        }

        private void lastAwardProducer_Click(object sender, EventArgs e)
        {
            var lastAwardProducer = producers
                .OrderByDescending(producer => producer.DATE)
                .FirstOrDefault();
                


            dataGridView.DataSource = new List<PRODUCER>() { lastAwardProducer };
        }
    }
}
