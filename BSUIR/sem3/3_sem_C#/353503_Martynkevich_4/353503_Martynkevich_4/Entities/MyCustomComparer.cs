using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_4.Entities
{
    internal class MyCustomComparer : IComparer<Client>
    {
        public int Compare(Client x, Client y) {
            return string.Compare(x.Name, y.Name);
        }

    }
}
