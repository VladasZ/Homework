using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW3
{

  

    /// <remarks/>
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class CD
    {

        private string tITLEField;

        private string aRTISTField;

        private string cOUNTRYField;

        private string cOMPANYField;

        private decimal pRICEField;

        private ushort yEARField;

        private byte pRODUCERField;

        /// <remarks/>
        public string TITLE
        {
            get
            {
                return this.tITLEField;
            }
            set
            {
                this.tITLEField = value;
            }
        }

        /// <remarks/>
        public string ARTIST
        {
            get
            {
                return this.aRTISTField;
            }
            set
            {
                this.aRTISTField = value;
            }
        }

        /// <remarks/>
        public string COUNTRY
        {
            get
            {
                return this.cOUNTRYField;
            }
            set
            {
                this.cOUNTRYField = value;
            }
        }

        /// <remarks/>
        public string COMPANY
        {
            get
            {
                return this.cOMPANYField;
            }
            set
            {
                this.cOMPANYField = value;
            }
        }

        /// <remarks/>
        public decimal PRICE
        {
            get
            {
                return this.pRICEField;
            }
            set
            {
                this.pRICEField = value;
            }
        }

        /// <remarks/>
        public ushort YEAR
        {
            get
            {
                return this.yEARField;
            }
            set
            {
                this.yEARField = value;
            }
        }

        /// <remarks/>
        public byte PRODUCER
        {
            get
            {
                return this.pRODUCERField;
            }
            set
            {
                this.pRODUCERField = value;
            }
        }
    }


}
