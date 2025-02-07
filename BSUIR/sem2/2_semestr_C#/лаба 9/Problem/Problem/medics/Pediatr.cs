using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Problem.equipments;

namespace Problem.medics
{
    internal class Pediatr : Medic
    {
        public override void GetInfo()
        {
            Console.WriteLine($"My name is {this.name}, I'm a pediatr, can i help you");
        }
        public override void Diagnose()
        {
            Random rnd = new Random();
            int a = rnd.Next(0, 2);

            if (a == 1)
            {
                Console.WriteLine("Это всего лишь вывих, мальчик, помажь мазь и пройдет");
            }
            else
            {
                Console.WriteLine("У тебя нет левой ноги, помажь мазь и пройдет");
            }
        }
        public Pediatr(string name, IEquipment equipment) : base(name, equipment) { }
    }
}
