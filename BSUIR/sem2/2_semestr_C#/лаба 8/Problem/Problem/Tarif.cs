using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem
{
    public class Tarif
    {
        public static int CorrectInput(int mass)
        {
            if (mass < 0)
            {
                mass *= -1;
                throw new Exception("Неверный формат");
            }

            return mass;
        }
        public static string CorrectInput(string name)
        {
            if (name == null || name == "")
            {
                name = "none";
                throw new Exception("Неверный формат");
            }

            return name;
        }

        public Tarif(int cost, string name)
        {
            _cost = CorrectInput(cost);
            _name = CorrectInput(name);
        }

        public int cost
        {
            get
            {
                return _cost;
            }

            set
            {
                _cost = CorrectInput(value);
            }
        }

        public string name
        {
            get
            {
                return _name;
            }
            set
            {
                _name = CorrectInput(value);
            }
        }

        public Company tarife
        {
            get => default;
            set
            {
            }
        }

        private int _cost;
        private string _name;
    }
}
