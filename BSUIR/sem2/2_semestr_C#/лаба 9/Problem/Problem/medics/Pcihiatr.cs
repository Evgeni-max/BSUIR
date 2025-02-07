using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Problem.equipments;

namespace Problem.medics
{
    internal class Pcihiatr : Medic
    {
        public override void GetInfo()
        {
            Console.WriteLine($"My name is {this.name}, I'm a pcihiatr, can i help you");
        }
        public override void Diagnose()
        {
            Random rnd = new Random();
            int a = rnd.Next(0, 2);

            if (a == 1)
            {
                Console.WriteLine("Это всего лишь стресс, отдохните и пройдет");
            }
            else
            {
                Console.WriteLine("Вы больной на голову, срочно в палату");
            }
        }
        public Pcihiatr(string name, IEquipment equipment) : base(name, equipment) { }
    }
}
