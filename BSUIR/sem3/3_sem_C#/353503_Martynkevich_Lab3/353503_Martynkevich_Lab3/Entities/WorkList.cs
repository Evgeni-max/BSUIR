using _353503_Martynkech_Lab3.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _353503_Martynkech_Lab3.Collections;

namespace _353503_Martynkech_Lab3.Entities
{
    internal class WorkList
    {
        static public event EventDelegate workListIsChanged;
        private Dictionary<string, int> ListWorkAndCost;
        public WorkList()
        {
            ListWorkAndCost = new Dictionary<string, int>();
        }

        public void Add(Pair<string, int> item)
        {
            workListIsChanged?.Invoke($"add new job {item.First} for cost {item.Second}");
            ListWorkAndCost.Add(item.First, item.Second);
        }

        public int Find(string item)
        {
            foreach (var wrk in ListWorkAndCost)
            {
                if (wrk.Key == item) return wrk.Value;
            }
            return -1;
        }

        public void GiveInformation()
        {
            foreach (var work in ListWorkAndCost)
            {
                Console.WriteLine(work.Key + " : " + work.Value);
            }
        }
    }
}
