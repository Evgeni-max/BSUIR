using Problem.equipments;
using Problem.medics;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem.servises
{
    internal class PsihiatrBuilder : AbstractBuilder
    {
        public override Medic Build()
        {
            if (equipment != null)
            {
                return new medics.Pcihiatr(name, equipment);
            }
            else
            {
                return new medics.Pcihiatr(name, new Ucol());
            }
        }
    }
}
