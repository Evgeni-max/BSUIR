using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_1
{
    public class Company
    {
        private static Company? instance;

        public static int CorrectInput(int costPerTonn)
        {
            if (costPerTonn < 0)
            {
                costPerTonn *= -1;
            }

            return costPerTonn;
        }

        Company(int costPerTonn = 0, string companyName = "none") {
            this.companyName = companyName;
            this.costPerTonn = CorrectInput(costPerTonn);
            allMass = 5;
            tarifes = new List<Tarif>();
        }

        public void AddTarif(Tarif tariff)
        {
            tarifes.Add(tariff);
            allMass += tariff.GetMass();
        }

        public void GetInformation()
        {
            Console.WriteLine("имя компании: {0}", companyName);
            Console.WriteLine("Цена за тонну: {0}", costPerTonn);
            Console.WriteLine("Общая выручка: {0}", allMass * costPerTonn);

            Console.WriteLine("Все заказы: ");

            foreach (var v in tarifes)
            {
                 Console.WriteLine(v.GetMass());
            }
        }

        public void SetCostPerTonn(int costPerTonn) {
            this.costPerTonn = CorrectInput(costPerTonn);
        }

        public void SetcompanyName(string companyName)
        {
            this.companyName = companyName;
        }

        public static Company GetInstance(string companyName, int costPerTonn)
        {
            if (instance == null)
            {
                return new Company(costPerTonn, companyName);
            }
            else
            {
                return instance;
            }
        }

        private int costPerTonn;
        private string companyName;
        private static int allMass = 0;
        private static List<Tarif> tarifes;
    }

}
