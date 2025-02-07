using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4_Task_1.Entities
{
    internal class Patient
    {
        private int _id;
        private bool _infected;
        private string _name;
        public int Id { get => _id; }
        public bool Infected { get => _infected; }
        public string Name { get => _name; }

        public Patient(string name, int id, bool infected)
        {
            _id = id;
            _infected = infected;
            _name = name;
        }

        public Patient(string info)
        {
            string[] strings = info.Split(':');
            _id = int.Parse(strings[0]);
            _infected = bool.Parse(strings[1]);
            _name = strings[2];
        }
    }
}
