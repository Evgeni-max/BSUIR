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
                throw new Exception("Неверный формат");
                name = "none";
            }

            return name;
        }
        public static List<Tarif> tarife { get; private set; }
        public static List<ICost> icosts { get; private set; }
        Company(string companyName = "none")
        {
            this.companyName = CorrectInput(companyName);
            tarife = new List<Tarif>();
            icosts = new List<ICost>();
            minCost = int.MaxValue;
        }

        public void AddTarif(Tarif tariff)
        {
            tarife.Add(tariff);
            icosts.Add(new NoDiscount(tariff.cost));
            if (minCost > tariff.cost)
            {
                minCost = tariff.cost;
            }
        }

        public void AddDiscount(int index, int discount)
        {
            icosts[index] = new WithDisount(tarife[index].cost, discount);
            if (minCost > icosts[index].GetPrice())
            {
                minCost = icosts[index].GetPrice();
            }
        }

        public void SetCompanyName(string companyName)
        {
            this.companyName = companyName;
        }
        public string GetCompanyName()
        {
            return this.companyName;
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
        public int minCost { get; private set; }
    }
}
