using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Entities;
using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces.Contracts;
using Lab_3_Task_1.Services;

namespace Lab_3_Task_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Journal journal = new();
            MyHotel.ListOfClientsIsChanged += journal.GetEvent;
            MyHotel.ReqestIsSent += GetEvent;

            MyHotel hotel = new("BSUIR", 21);

            hotel.RequestRoom("Victor", 2);
            hotel.RequestRoom("Victor", 3);
            hotel.RequestRoom("Victor", 4);
            hotel.RequestRoom("Viliam", 5);

            Console.WriteLine();
            hotel.GetListOfRooms();

            Console.WriteLine($"\nCost of all ordered rooms = {hotel.GetCostOfAllOrderedRooms()}");

            Console.WriteLine($"\nName of orderer, who paid more than others is " +
                              $"{hotel.GetNameAndPriceOfClientWhoPaidMoreThanOthers(out int price)}" +
                              $" with price = {price}");

            const int value = 1000;
            List<string> clients = hotel.getListOfClientsPaidMoreThan(value);

            Console.WriteLine($"\nClients, paid more than {value}");
            foreach (string client in clients)
            {
                Console.WriteLine("\t" + client);
            }

            Console.WriteLine("\nJournal messages:");
            foreach (string mes in journal)
            {
                Console.WriteLine($"\t{mes}");
            }

            const int firstBorder = 350;
            const int secondBorder = 750;
            var list = hotel.GetRangeList(firstBorder, secondBorder);

            Console.WriteLine($"\n{list[0].Category}: {list[0].Qty}");
            Console.WriteLine($"\nComfort rooms: {list[1]}");
            Console.WriteLine($"\nPremium rooms: {list[2]}");

        }
        static void GetEvent(string message)
        {
            Console.WriteLine("Event has been uploaded in class Program");
            Console.WriteLine($"\tMessage: {message}");
        }
    }
}
