using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Entities;
using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces.Contracts;

namespace Lab_1_Task_1_353502_BURCHUCK_Lab_1_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            MyHotel hotel = new MyHotel("BSUIR_Land", 21);
            Console.WriteLine(hotel.Name);
            hotel.GetInfo();
            hotel.GetCostOfLiving("f");
        }
    }
}
