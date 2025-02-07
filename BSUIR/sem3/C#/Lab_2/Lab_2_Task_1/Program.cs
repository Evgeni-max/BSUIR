using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Collections;
using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Entities;
using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces;
using Lab_2_Task_1.Entities;

namespace Lab_2_Task_1
{
    internal class Program
    {

        static void Main(string[] args)
        {
            Journal journal = new();
            MyHotel.ListOfClientsIsChanged += journal.GetEvent;
            MyHotel.ReqestIsSent += GetEvent;
            MyHotel hotel = new("BSUIR Hotel", 21);

            hotel.RequestRoom("Viliam", 4);
            hotel.RequestRoom("Viliam", 4);
            hotel.RequestRoom("Henry", 5);

            Console.WriteLine("\nJournal messages:");
            foreach (string mes in journal)
            {
                Console.WriteLine($"\t{mes}");
            }

            //_ = hotel[22];    * Exception

                //MyCustomCollection<int> temp = new    MyCustomCollection<int>(){ 1 };
            //temp.Remove(0);   * Exception
        }
        static void GetEvent(string message)
        {
            Console.WriteLine("Event has been uploaded in class Program");
            Console.WriteLine($"\tMessage: {message}");
        }
    }
}
