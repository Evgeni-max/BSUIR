using System;
using System.Collections.Specialized;

namespace _353503_Martynkevich_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a, b;

            Console.WriteLine("Введите числа\na: ");
            a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("b: ");
            b = Convert.ToInt32(Console.ReadLine());

            Converter converter = new();

            Console.WriteLine("Результат: ");
            Console.WriteLine(converter.MainTask(a, b));
        }
    }
}
