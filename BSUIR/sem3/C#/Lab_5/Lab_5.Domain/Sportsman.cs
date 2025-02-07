using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_5.Domain
{
    sealed public class Sportsman
    {
        private SportType sportType;
        private string name;
        private byte age;
        
        public string Name { get { return name; } set { name = value; } }
        public byte Age { get { return age; } set { age = value; } }
        public string SportTypeName { get { return sportType.NameOfSport; } set { sportType.NameOfSport = value; } }
        public byte SportTypePopularity { get { return sportType.Popularity; } set { sportType.Popularity = value; } }

        public Sportsman(string name, byte age, SportType sportType)
        {
            this.name = name;
            this.age = age;
            this.sportType = sportType;
        } 

        public Sportsman()
        {
            sportType = new SportType("",0);
            name = "";
            age = 0;
        }

        static public bool operator ==(Sportsman? sportsman_1, Sportsman? sportsman_2)
        {
            SportsmanEqualityComparer comparer = new SportsmanEqualityComparer();
            return comparer.Equals(sportsman_1, sportsman_2);
        }
        static public bool operator !=(Sportsman? sportsman_1, Sportsman? sportsman_2)
        {
            SportsmanEqualityComparer comparer = new SportsmanEqualityComparer();
            return !comparer.Equals(sportsman_1, sportsman_2);
        }
    }
}
