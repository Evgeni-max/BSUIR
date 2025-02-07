using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem.Classes
{
    sealed class BlackHole : CosmoObject
    {
        public BlackHole(double mass = 0, bool haveLife = false, string name = "none") : base(mass, haveLife, name) { }

        internal CosmoObject CosmoObject
        {
            get => default;
            set
            {
            }
        }

        public override void Print()
        {
            Console.WriteLine($"Black Hole: {base.Name}");
            Console.WriteLine($"Mass of the Black Hole: {base.mass}");
        }
    }
}
