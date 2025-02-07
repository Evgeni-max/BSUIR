using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace _353503_Martynkevich_4.Entities
{
    internal class Client
    {
        static private int ClientCount = 0;
        public int Id { get; private set; }
        public string Name { get; private set; }
        public string MumName { get; private set; }

        public Client() {
            Id = ++ClientCount;
            Name = "Noname";
            MumName = "Nomum";
        }
        public Client(int _id, string _name, string _mumName)
        {
            Id = _id;
            ++ClientCount;
            Name = _name;
            MumName = _mumName;
        }
        public Client(string _name, string _mumName)
        {
            Id = ++ClientCount;
            Name = _name;
            MumName = _mumName;
        }
    }
}
