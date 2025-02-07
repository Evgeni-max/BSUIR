using _353503_Martynkevich_Lab1.Collections;
using _353503_Martynkevich_Lab1.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_Lab1.Entities
{
    internal class EachWork
    {
        MyCustomCollection<Pair<string, MyCustomCollection<string>>> ListOfWorkersOnEachWork;

        public EachWork() {
            ListOfWorkersOnEachWork = new MyCustomCollection<Pair<string, MyCustomCollection<string>>>();
        }
        public void AddWork(string nameOfWork)
        {
            ListOfWorkersOnEachWork.Add(new Pair<string, MyCustomCollection<string>>(nameOfWork, new MyCustomCollection<string>()));
        }
        public void AddWorker(string nameOfWork, string nameOfWorker) {
            foreach (var work in ListOfWorkersOnEachWork)
            {
                if (work.First == nameOfWork)
                {
                    work.Second.Add(nameOfWorker);
                }
            }
        }
        public MyCustomCollection<string> Find(string item)
        {
            foreach (var work in ListOfWorkersOnEachWork)
            {
                if (work.First == item) return work.Second;
            }
            return new MyCustomCollection<string>();
        }

        public void GiveInformation()
        {
            foreach (var work in ListOfWorkersOnEachWork)
            {
                Console.Write(work.First + ": ");
                foreach (var worker in work.Second)
                {
                    Console.Write(worker + " ");
                    Console.WriteLine();
                }
            }
        }
    }
}
