using _353503_Martynkech_Lab3.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _353503_Martynkech_Lab3.Collections;
using System.Dynamic;

namespace _353503_Martynkech_Lab3.Entities
{
    public delegate void EventDelegate(string message);
    internal class Worker : IWorker
    {
        
        static public event EventDelegate workIsChanged;
        static public event EventDelegate newWorker;

        List<string> ListOfWork;
        public string name { get; }
        public int salary { get; private set; }
        public Worker(string name)
        {
            newWorker?.Invoke($"add new Worker {name}");
            salary = 0;
            this.name = name;
            ListOfWork = new List<string>();
        }

        public void Add(int cost, string job)
        {
            workIsChanged($"{this.name} does the job {job}");
            salary += cost;
            ListOfWork.Add(job);
        }

        public List<string> GetListOfWork()
        {
            return ListOfWork;
        }
    }
}
