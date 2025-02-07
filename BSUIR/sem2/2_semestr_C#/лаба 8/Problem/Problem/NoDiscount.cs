using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem
{
    internal class NoDiscount : ICost
    {
        public NoDiscount(int cost) {
            this.cost = CorrectInput(cost);
        }
        public int GetPrice()
        {
            return cost;
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

        public Company icosts
        {
            get => default;
            set
            {
            }
        }
    }
}
