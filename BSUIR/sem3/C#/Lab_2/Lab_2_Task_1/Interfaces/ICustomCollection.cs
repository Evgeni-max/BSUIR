using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces
{
    internal interface ICustomCollection<T>
    {
        public T this[int index] { get; set; }
        public void Reset();
        public void Next();
        public T Current();
        public int Count { get; }
        public void Add(T item);
        public void Remove(T item);
        public T RemoveCurrent();
    }
}
