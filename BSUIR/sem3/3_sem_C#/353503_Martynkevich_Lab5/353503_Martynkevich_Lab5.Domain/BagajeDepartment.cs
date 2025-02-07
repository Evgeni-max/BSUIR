using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_Lab5.Domain
{
    public class BagajeDepartment
    {
        public int CountOfBagaje { get; set; }
        public int RentCost { get; set; }

        public BagajeDepartment() {
            CountOfBagaje = 0;
            RentCost = 100;
        }
        public BagajeDepartment(int CountOfBagaje, int RentCost)
        {
            this.CountOfBagaje = CountOfBagaje;
            this.RentCost = RentCost;
        }
    }
}
