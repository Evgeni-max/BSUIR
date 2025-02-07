using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_5.Domain
{
    sealed public class SportType
    {
        private string nameOfSport;
        private byte popularity;

        public string NameOfSport {  get { return nameOfSport; } set { nameOfSport = value; } }
        public byte Popularity {  get { return popularity; } set {popularity = value; } }

        public SportType(string nameOfSport, byte popularity)
        {
            this.nameOfSport = nameOfSport;
            this.popularity = popularity;
        }
    }
}
