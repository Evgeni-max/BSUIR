using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _353503_Martynkevich_Lab1.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using static System.Runtime.InteropServices.JavaScript.JSType;
using System.Xml.Linq;

namespace _353503_Martynkevich_Lab1.Entities
{
    internal class WorkList
    {
        private MyCustomCollection<Pair<string, int>> ListWorkAndCost;
        public WorkList() {
            ListWorkAndCost = new MyCustomCollection<Pair<string, int>>();
        }

        public void Add(Pair<string, int> item)
        {
            ListWorkAndCost.Add(item);
        }

        public Pair<string, int> Find(string item)
        {
            foreach(Pair<string, int> wrk in ListWorkAndCost)
            {
                if (wrk.First == item) return wrk;
            }
            return new Pair<string, int> ( "NoFind", -1 );
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
