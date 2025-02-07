namespace Problem
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Matrix mat = new(1, 2, 3, 4);
                Matrix m1 = new(2, 3, 4, 5);
                Matrix m2 = mat + m1;
                Console.WriteLine(m2.ToString());
            } catch (Exception ex) { Console.WriteLine(ex.ToString()); }
        }
    }
}
