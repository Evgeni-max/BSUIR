using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4_Task_1.Entities
{
    internal class MyCustomComparer : IComparer<Patient>
    {
        public int Compare(Patient? x, Patient? y)
        {
            if (x == null || y == null)
            {
                throw new ArgumentNullException(nameof(x));
            }
            return string.Compare(x?.Name, y?.Name, StringComparison.Ordinal);
        }
    }
}
