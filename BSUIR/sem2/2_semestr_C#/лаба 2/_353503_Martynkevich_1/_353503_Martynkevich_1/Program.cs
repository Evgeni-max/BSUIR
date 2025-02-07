using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double a, b, c;
            bool continueProgram = true;

            while (continueProgram)
            {
                string str;

                Console.WriteLine("\nВведите длинну a:");
                str = Console.ReadLine();
                while (!double.TryParse(str, out a) || a <= 0)
                {
                    Console.WriteLine("Введите длинну a:");
                    str = Console.ReadLine();
                }

                Console.WriteLine("Введите длинну b:");
                str = Console.ReadLine();
                while (!double.TryParse(str, out b) || b <= 0)
                {
                    Console.WriteLine("Введите длинну b:");
                    str = Console.ReadLine();
                }

                Console.WriteLine("Введите длинну c:");
                str = Console.ReadLine();
                while (!double.TryParse(str, out c) || c <= 0)
                {
                    Console.WriteLine("Введите длинну c:");
                    str = Console.ReadLine();
                }

                if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == b * b + a * a))
                {
                    Console.WriteLine("Прямоугольный");
                }
                else
                {
                    Console.WriteLine("НЕ Прямоугольный");
                }

                Console.WriteLine("Продолжаем?(yes, no) ");

                if (Console.ReadLine() == "yes") { }
                else continueProgram = false;
            }
        }
    }
}

