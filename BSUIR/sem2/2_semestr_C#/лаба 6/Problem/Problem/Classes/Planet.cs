using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem.Classes
{
    internal class Planet : CosmoObject
    {
        public Planet(double mass = 0, bool haveLife = false, string name = "none", bool hasMan = false) : base(mass, haveLife, name)
        {
            if (haveLife)
               this.HasMan = hasMan;
            else this.HasMan = false;
        }

        public override void Print()
        {
            Console.WriteLine($"Planet: {base.Name}");
            Console.WriteLine($"Mass of the Planet: {base.mass}");
        }
        override public void IsHaveLife()
        {
            if (HaveLife)
            {
                Console.WriteLine("Has a life");

                if (HasMan)
                    Console.WriteLine("Has man");
                else Console.WriteLine("Hasn't man");
            }   

            else Console.WriteLine("Hasn't life");
        }

        private bool HasMan { get; set; }

        internal CosmoObject CosmoObject
        {
            get => default;
            set
            {
            }
        }

        internal CosmoObject CosmoObject1
        {
            get => default;
            set
            {
            }
        }
    }
}
