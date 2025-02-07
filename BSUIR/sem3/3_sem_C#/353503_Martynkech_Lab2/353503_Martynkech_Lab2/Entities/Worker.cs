using _353503_Martynkech_Lab2.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _353503_Martynkech_Lab2.Collections;
namespace _353503_Martynkech_Lab2.Entities
{
    public delegate void EventDelegate(string message);
    internal class Worker : IWorker
    {
        
        static public event EventDelegate workIsChanged;
        static public event EventDelegate newWorker;

        MyCustomCollection<string> ListOfWork;
        public string name { get; }
        public int salary { get; private set; }
        public Worker(string name)
        {
            newWorker?.Invoke($"add new Worker {name}");
            salary = 0;
            this.name = name;
            ListOfWork = new MyCustomCollection<string>();
        }

        public void Add(int cost, string job)
        {
            workIsChanged($"{this.name} does the job {job}");
            salary += cost;
        }

    }
}
