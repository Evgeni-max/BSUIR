using Problem.equipments;
using Problem.medics;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Problem.servises
{
    internal class PediatrBuilder : AbstractBuilder
    {
        public PediatrBuilder() { }
        public override Medic Build()
        {
            if (equipment != null)
            {
                return new Pediatr(name, equipment);
            }
            else
            {
                return new Pediatr(name, new Ucol());
            }
        }
    }
}
