using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem
{
    internal class Person
    {
        public static string CorrectInput(string name)
        {
            if(name == null || name == "")
            {
                Console.WriteLine("Неверный формат");
                name = "nobody";
            }

            return name;
        }

        public static int CorrectInput(int mass)
        {
            if (mass < 0)
            {
                Console.WriteLine("Неверный формат");
                mass *= -1;
            }

            return mass;
        }
        public Person(string f, string i)
        {
            this.fio = CorrectInput(f) + ' ' + CorrectInput(i);
            this.myTarifes = new List<Tarif>();
            this.masses = new List<int>();
            allCost = 0;
        }

        public string GetFio() { return this.fio; }

        public List<Tarif> GetMyTarifes() { return this.myTarifes; }
        public void SetFio(string fio) { this.fio = CorrectInput(fio); }

        public void AddZakaz(int mass, Tarif tariff)
        {
            this.myTarifes.Add(tariff);
            this.masses.Add(CorrectInput(mass));
            this.allCost += tariff.cost * CorrectInput(mass);
        }

        public void GetInformation()
        {
            Console.WriteLine("Заказчик: {0}", fio);

            Console.WriteLine("Все заказы: ");

            for (int i = 0; i < myTarifes.Count(); ++i)
            {
                Console.WriteLine(i + " : " + masses[i] + ' ' + myTarifes[i].cost);
            }

            Console.WriteLine("Общая цена: {0}", allCost);
        }

        string fio;
        List<Tarif> myTarifes;
        List<int> masses;
        int allCost;
    }
}
