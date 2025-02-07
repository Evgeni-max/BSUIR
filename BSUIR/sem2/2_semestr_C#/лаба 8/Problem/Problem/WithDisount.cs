using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem
{
    internal class WithDisount : ICost
    {
        public WithDisount(int cost, int discount)
        {
            this.cost = CorrectInput(cost);

            if (discount < 0 || discount > 100) { throw new Exception("скидка неверная"); }
            this.discount = discount;
        }

        public int GetPrice()
        {
            return cost * (100 - discount) / 100;
        }
        public static int CorrectInput(int mass)
        {
            if (mass < 0)
            {
                mass *= -1;
                throw new Exception("Неверный формат");
            }

            return mass;
        }
        public int cost { get; set; }
        public int discount { get; set; }

        public Company icosts
        {
            get => default;
            set
            {
            }
        }
    }
}
