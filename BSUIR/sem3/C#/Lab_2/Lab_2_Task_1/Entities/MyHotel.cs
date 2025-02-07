using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Collections;
using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces.Contracts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Entities
{
    internal class MyHotel : Interfaces.Contracts.IHotel
    {
        string name;

        MyCustomCollection<BasicRoom> rooms;
        int count;

        public int Count { get { return count; } }

        public BasicRoom this[int index]
        {
            get { return rooms[index]; }
        }

        public MyHotel(string name, int countOfRooms)
        {
            Random random = new Random();
            this.name = name;
            this.count = countOfRooms;
            rooms = new MyCustomCollection<BasicRoom>();
            for (int i = 0; i < countOfRooms; ++i)
            {
                rooms.Add(new BasicRoom(i + 1,random.Next(200,1000)));
            }
        }

        public string Name { get { return name; } }


        public delegate void EventDelegate(string message);
        static public event EventDelegate ListOfClientsIsChanged;
        static public event EventDelegate ReqestIsSent;

        public void GetInfo()
        {
            for (int i = 0; i < count; ++i)
            {
                BasicRoom temp = rooms[i];
                Console.Write("Id: " + temp.Id + "\tIsOrdered: " + temp.IsOrdered + "\tCost: " + temp.Cost + "\n");
            }
        }

        public void RequestRoom(string ordererName, int id)
        {
            if (id >= count)
            {
                throw new Exception("Out of range");
            }
            else
            {
                if(rooms[id].RequestToOrder(ordererName))
                {
                    ReqestIsSent($"Room № {id} is ordered by {ordererName} in a price of {rooms[id].Cost} $");
                    ListOfClientsIsChanged($"Room № {id} was ordered by {ordererName}");
                }
                else
                {
                    ReqestIsSent($"Room № {id} has been all ready ordered");
                }
            }
        }

        public void GetListOfEmptyRooms()
        {
            for (int i = 0; i < count; ++i)
            {
                BasicRoom temp = rooms[i];
                if (!temp.IsOrdered)
                {
                    Console.Write("Id: " + temp.Id + "\n");
                }
            }
        }

        public void GetCostOfLiving(string ordererName)
        {
            for (int i =0; i < count; ++i)
            {
                if (rooms[i].ClientName == ordererName)
                {
                    Console.WriteLine("Cost of room: " + rooms[i].Cost);
                    return;
                }
            }
        }

        public void GetIdOfMostPopularRoom()
        {
            BasicRoom temp = rooms[0];
            for (int i = 1; i < count; ++i)
            {
                if (temp.Popularity < rooms[i].Popularity)
                {
                    temp = rooms[i];
                }
            }
            Console.Write("Id of most popular room: " + temp.Id + "\n");
        }
    }
}
