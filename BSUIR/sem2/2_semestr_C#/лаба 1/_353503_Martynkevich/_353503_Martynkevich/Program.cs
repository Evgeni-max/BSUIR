namespace _353503_Martynkevich
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a, b, c;

            Console.WriteLine("Введите a:");
            a = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Введите b:");
            b = Convert.ToInt32(Console.ReadLine());

            c = a / b;

            Console.WriteLine("Частное:\n{0}", c);
        }
    }
}
