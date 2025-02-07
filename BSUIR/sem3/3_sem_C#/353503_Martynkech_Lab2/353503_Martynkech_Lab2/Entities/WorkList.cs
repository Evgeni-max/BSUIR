using _353503_Martynkech_Lab2.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _353503_Martynkech_Lab2.Collections;

namespace _353503_Martynkech_Lab2.Entities
{
    internal class WorkList
    {
        static public event EventDelegate workListIsChanged;
        private MyCustomCollection<Pair<string, int>> ListWorkAndCost;
        public WorkList()
        {
            ListWorkAndCost = new MyCustomCollection<Pair<string, int>>();
        }

        public void Add(Pair<string, int> item)
        {
            workListIsChanged($"add new job {item.First} for cost {item.Second}");
            ListWorkAndCost.Add(item);
        }

        public Pair<string, int> Find(string item)
        {
            foreach (Pair<string, int> wrk in ListWorkAndCost)
            {
                if (wrk.First == item) return wrk;
            }
            return new Pair<string, int>("NoFind", -1);
        }

        public void GiveInformation()
        {
            foreach (var work in ListWorkAndCost)
            {
                Console.WriteLine(work.First + " : " + work.Second);
            }
        }
    }
}
