using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using Problem.equipments;
using Problem.medics;

namespace Problem.servises
{
    internal abstract class AbstractBuilder
    {
        protected string name = string.Empty;
        protected IEquipment? equipment;
        protected AbstractBuilder() { }
        public AbstractBuilder SetName(string name)
        { this.name = name; return this; }
        public AbstractBuilder SetEquipment(IEquipment weapon)
        { equipment = weapon; return this; }
        public abstract Medic Build();
    }
}
