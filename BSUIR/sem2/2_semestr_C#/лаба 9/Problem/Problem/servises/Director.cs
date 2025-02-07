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
    internal class Director
    {
        public static Medic GetPediatr(string name, IEquipment equipment)
        {
            PediatrBuilder buil = new PediatrBuilder();
            buil.SetName(name);
            buil.SetEquipment(equipment);
            return buil.Build();
        }
        public static Medic GetHirurg(string name, IEquipment equipment)
        {
            HirurgBuilder buil = new HirurgBuilder();
            buil.SetName(name);
            buil.SetEquipment(equipment);
            return buil.Build();
        }
        public static Medic GetPcihiatr(string name, IEquipment equipment)
        {
            PsihiatrBuilder buil = new PsihiatrBuilder();
            buil.SetName(name);
            buil.SetEquipment(equipment);
            return buil.Build();
        }
        public static Medic GetMedsister(string name, IEquipment equipment)
        {
            MedsisterBuilder builder = new MedsisterBuilder();
            builder.SetName(name);
            builder.SetEquipment(equipment);
            return builder.Build();
        }
    }
}
