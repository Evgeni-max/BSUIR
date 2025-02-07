using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem.Classes
{
    internal class Earth : Planet
    {
        public int Year { get; set; }

        internal Planet Planet
        {
            get => default;
            set
            {
            }
        }

        public Earth(double mass = 0, bool haveLife = false, string name = "none", int year = 0) : base(mass, haveLife, name)
        {
            this.Year = year;
        }

        public new void IsHaveLife()
        {
            if (HaveLife)
            {
                Console.WriteLine("Has a life");

                if (Year > -3000000)
                    Console.WriteLine("Has man");
                else Console.WriteLine("Hasn't man");
            }

            else Console.WriteLine("Hasn't life");
        }

    }
}
