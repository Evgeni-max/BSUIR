using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_2.Services
{
    internal class Mathing
    {
        double findX(double k, double z)
        {
            if (k < 1)
            {
                Console.WriteLine("Первая ветка");
                return k * z * z * z;
            }
            else
            {
                Console.WriteLine("Вторая ветка");
                return z * (z + 1);
            }      
        }
        public void MainTask(double k, double z)
        {
            double x = findX(k, z), result;

            result = Math.Pow(Math.Log(1 + x * x) + Math.Cos(x + 1), Math.Pow(Math.E, k * x));

            if (result == double.PositiveInfinity)
            {
                Console.WriteLine("Результат бесконечно большой");
            } 
            else 
                Console.WriteLine("Результат: {0}", result);
        }
    }
}
