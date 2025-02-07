using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_1
{
    internal class Converter
    {
        public int MinArg(int a, int b)
        {
            if (a > b)
            {
                return b;
            }
            else 
                return a;
        }
        public int MainTask(int a, int b)
        {
            return MinArg(a, 2 * b + a) - MinArg(7 * a + 2 * b, b);
        }
    }
}
