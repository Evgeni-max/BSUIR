using Problem.equipments;
using Problem.medics;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem.servises
{
    internal class HirurgBuilder : AbstractBuilder
    {
        public override Medic Build()
        {
            if (equipment != null)
            {
                return new medics.Hirurg(name, equipment);
            }
            else
            {
                return new medics.Hirurg(name, new Ucol());
            }
        }
    }
}
