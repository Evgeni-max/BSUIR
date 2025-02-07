using _353503_Martynkevich_Lab1.Collections;
using _353503_Martynkevich_Lab1.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_Lab1.Entities
{
    internal class Worker : IWorker
    {
        MyCustomCollection<string> ListOfWork;
        public string name { get; }
        public int salary { get; private set; }
        public Worker(string name) { 
            salary = 0;
            this.name = name;
            ListOfWork = new MyCustomCollection<string>();
        }

        public void Add(int cost)
        {
            salary += cost;
        }

    }
}
