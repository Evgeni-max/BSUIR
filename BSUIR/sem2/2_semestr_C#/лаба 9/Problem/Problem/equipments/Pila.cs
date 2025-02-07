using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem.equipments
{
    internal class Pila : IEquipment
    {
        public void UseEquipment()
        {
            Console.WriteLine("Я отрезал пациенту конечность");
        }
    }
}
