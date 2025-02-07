using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_6_Task_1.Entities
{
    public class Employee
    {
        int age;
        bool isMarried;
        string name;
        public int Age { get { return age; } }
        public bool IsMarried { get { return isMarried; } }
        public string Name { get { return name; } }

        public Employee(int age, bool isMarried, string name)
        {
            this.age = age;
            this.isMarried = isMarried;
            this.name = name;
        }
    }
}
