using Problem.equipments;
using Problem.medics;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem.servises
{
    internal class MedsisterBuilder : AbstractBuilder
    {
        public override Medic Build()
        {
            if (equipment != null)
            {
                return new medics.Medsister(name, equipment);
            }
            else
            {
                return new medics.Medsister(name, new Ucol());
            }
        }
    }
}
