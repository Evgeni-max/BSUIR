using _353503_Martynkech_Lab3.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _353503_Martynkech_Lab3.Collections;

namespace _353503_Martynkech_Lab3.Entities
{
    internal class EachWork
    {
        Dictionary<string, List<string>> ListOfWorkersOnEachWork;

        public EachWork()
        {
            ListOfWorkersOnEachWork = new Dictionary<string, List<string>>();
        }
        public void AddWork(string nameOfWork)
        {
            ListOfWorkersOnEachWork[nameOfWork] = new List<string>();
        }
        public void AddWorker(string nameOfWork, string nameOfWorker)
        {
            foreach (var work in ListOfWorkersOnEachWork)
            {
                ListOfWorkersOnEachWork[nameOfWork].Add(nameOfWorker);
            }
        }
        public List<string> Find(string item)
        {
            return ListOfWorkersOnEachWork[item];
        }

        public void GiveInformation()
        {
            foreach (var work in ListOfWorkersOnEachWork)
            {
                Console.Write(work.Key + ": ");
                foreach (var worker in work.Value)
                {
                    Console.Write(worker + " ");
                    Console.WriteLine();
                }
            }
        }
       
    }
}
