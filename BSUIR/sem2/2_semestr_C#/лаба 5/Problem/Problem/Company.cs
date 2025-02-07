using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem
{
    public class Company
    {
        private static Company? instance;

        public string CorrectInput(string name)
        {
            if (name == null || name == "")
            {
                Console.WriteLine("Неверный формат");
                name = "none";
            }

            return name;
        }
        public static List<Tarif> tarife { get; private set; }

        Company(string companyName = "none")
        {
            this.companyName = CorrectInput(companyName);
            tarife = new List<Tarif>();
        }

        public void AddTarif(Tarif tariff)
        {
            tarife.Add(tariff);
            allCost += tariff.cost;
        }

        public void GetInformation()
        {
            Console.WriteLine("имя компании: {0}", companyName);
            //Console.WriteLine("Общая выручка: {0}", allCost);

            Console.WriteLine("Все тарифы: ");

            for (int i = 0; i < tarife.Count(); ++i)
            {
                Console.WriteLine(i + " : " + tarife[i].cost);
            }
        }

        public void SetCompanyName(string companyName)
        {
            this.companyName = companyName;
        }

        public static Company GetInstance()
        {
            if (instance == null)
            {
                return new Company();
            }
            else
            {
                return instance;
            }
        }

        private string companyName;
        private static int allCost = 0;
    }
}
