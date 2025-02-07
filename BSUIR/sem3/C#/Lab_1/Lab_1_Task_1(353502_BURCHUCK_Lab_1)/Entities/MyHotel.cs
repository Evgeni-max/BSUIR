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
                rooms[id].RequestToOrder(ordererName);
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
            int price = 0;
            for (int i =0; i < count; ++i)
            {
                if (rooms[i].ClientName == ordererName)
                {
                    price = rooms.Sum(rooms[i].Cost, price);
                    Console.WriteLine("Cost of room: " + price);
                    return;
                }
            }
            Console.WriteLine("Non-logged in");
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
