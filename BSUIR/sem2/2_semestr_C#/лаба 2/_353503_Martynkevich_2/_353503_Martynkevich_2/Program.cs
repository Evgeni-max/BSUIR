using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_2
{
    internal class Program
    {
        readonly int a = 5;
        Program()
        {
            a = 7;
        }
        static void Main(string[] args)
        {
            double x, y, placeOfPoint;
            bool continueProgram = true;

            while (continueProgram)
            {
                string str;

                Console.WriteLine("\nВведите длинну x:");
                str = Console.ReadLine();
                while (!double.TryParse(str, out x))
                {
                    Console.WriteLine("Введите длинну x:");
                    str = Console.ReadLine();
                }

                Console.WriteLine("\nВведите длинну y:");
                str = Console.ReadLine();
                while (!double.TryParse(str, out y))
                {
                    Console.WriteLine("Введите длинну y:");
                    str = Console.ReadLine();
                }

                if (x > 0 || x < -23 || y < 0 || y > 23)
                {
                    placeOfPoint = 1;
                }
                else
                {
                    if (x == 0 || y == 23 || x == -y)
                    {
                        placeOfPoint = 2;
                    }
                    else if (-x > y)
                    {
                        placeOfPoint = 1;
                    }
                    else
                    {
                        placeOfPoint = 3;
                    }
                        
                }

                switch(placeOfPoint)
                {
                    case 1:
                        Console.WriteLine("Точка находится снаружи");
                        break;
                    case 2:
                        Console.WriteLine("Точка находится на границе");
                        break;
                    case 3:
                        Console.WriteLine("Точка находится внутри");
                        break;
                    default:
                        break;
                }

                Console.WriteLine("Продолжаем?(yes, no) ");

                if (Console.ReadLine() == "yes") { }
                else continueProgram = false;
            }
            
        }
    }
}
