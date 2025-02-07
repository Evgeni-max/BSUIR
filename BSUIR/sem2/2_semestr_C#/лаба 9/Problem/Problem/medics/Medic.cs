using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Problem.equipments;

namespace Problem.medics
{
    abstract internal class Medic
    {
        public string name { get; set; }
        public IEquipment equipment { get; set; }

        internal IEquipment _equipment
        {
            get => default;
            set
            {
            }
        }

        public Medic(string name, IEquipment equipment)
        {
            this.name = name;
            this.equipment = equipment;
        }
        public abstract void GetInfo();
        public abstract void Diagnose();

        public void UseYourEquipment()
        {
            equipment.UseEquipment();
        }
    }
}
