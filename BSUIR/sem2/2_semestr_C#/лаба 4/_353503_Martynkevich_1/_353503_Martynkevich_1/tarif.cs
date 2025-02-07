using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_1
{
    public class Tarif
    {
        public int CorrectInput(int mass)
        {
            if (mass < 0)
            {
                mass *= -1;
            }

            return mass;
        }
        public Tarif(int mass)
        {

            this.mass = CorrectInput(mass);
        }
        public int GetMass() { return this.mass; }
        public void SetMass(int  mass) { this.mass = CorrectInput(mass); }

        int mass;
    }
}
