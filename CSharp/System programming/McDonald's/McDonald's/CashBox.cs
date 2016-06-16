using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace McDonald_s
{
    public class CashBox
    {
        public Queue<Customer> CustomersInLine { get; set; } = new Queue<Customer>();
    }
}
