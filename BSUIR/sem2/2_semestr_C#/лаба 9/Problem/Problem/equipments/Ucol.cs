using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem.equipments
{
    internal class Ucol : IEquipment
    {
        public void UseEquipment()
        {
            Console.WriteLine("Я сделал пациенту укол");
        }
    }
}
