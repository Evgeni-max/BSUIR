using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Problem.equipments;

namespace Problem.medics
{
    internal class Medsister : Medic
    {
        public override void GetInfo()
        {
            Console.WriteLine($"My name is {this.name}, I'm a medsister, can i help you");
        }

        public override void Diagnose()
        {
            Random rnd = new Random();
            int a = rnd.Next(0, 2);

            if (a == 1)
            {
                Console.WriteLine("Это всего лишь вывих, сейчас забинтую");
            }
            else
            {
                Console.WriteLine("Боже! Да вы мертвы!");
            }
        }
        public Medsister(string name, IEquipment equipment) : base(name, equipment) { }
    }
}
