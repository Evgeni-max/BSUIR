using Problem.Classes;

namespace Problem
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                CosmoObject blackHole = new BlackHole(10000000, true, "Your mum");

                blackHole.IsHaveLife();
                blackHole.Print();

                CosmoObject planet = new Planet(10000000, false, "Your mum");
                planet.IsHaveLife();
                planet.Print();

                CosmoObject e1 = new Earth(10000000, true, "Your mum", 2024);
                e1.IsHaveLife();
                e1.Print();

                Earth e2 = new Earth(10000000, true, "Your mum", 2024);
                
                e2.IsHaveLife();
                e2.Print();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }
    }
}
