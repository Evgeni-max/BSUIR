using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Problem.Classes
{
    abstract internal class CosmoObject
    {
        protected CosmoObject(double mass = 0, bool haveLife = false, string name = "none") { 
            this.HaveLife = haveLife;
            this.mass = CorrectInput(mass);
            this.Name = CorrectInput(name);
        }
        protected double mass {  get; set; }

        public abstract void Print();
        virtual public void IsHaveLife()
        {
            if (HaveLife)
                Console.WriteLine("Has a life");
            else Console.WriteLine("Hasn't life");
        }
        protected bool HaveLife {  get; set; }
        protected string Name { get; set; }

        protected static string CorrectInput(string name)
        {
            if (name == null || name == "")
            {
                name = "nobody";
                throw new Exception("неверный ввод");
            }

            return name;
        }

        protected static double CorrectInput(double mass)
        {
            if (mass < 0)
            {
                mass *= -1;
                throw new Exception("неверный ввод");

            }

            return mass;
        }
    }
}
