using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_Lab1.Entities
{
    internal class Journal
    {
        static string mesages;

        static void LogEvent(EventArgs e)
        {
            mesages += Convert.ToString(e);
        }


    }
}
