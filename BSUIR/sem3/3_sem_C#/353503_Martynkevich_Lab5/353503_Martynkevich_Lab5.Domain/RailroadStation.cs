using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_Lab5.Domain
{
    public class RailroadStation
    {
        public string City { get; set; }
        public BagajeDepartment BagajeDepartment { get; set; }
        public RailroadStation() {
            City = "Noname";
            BagajeDepartment = new BagajeDepartment();
        }
        public RailroadStation(string City, int RentCost, int CountOfBagaje)
        {
            this.City = City;
            BagajeDepartment = new BagajeDepartment(CountOfBagaje, RentCost);
        }
    }
}
