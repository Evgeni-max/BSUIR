using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Collections;
using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces.Contracts;
using Lab_3_Task_1.Entities;
using Microsoft.VisualBasic;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Entities
{
    internal class MyHotel : IHotel
    {
        string name;

        Dictionary<int, BasicRoom> rooms;
        List<Client> clients;
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
            count = countOfRooms;
            rooms = new Dictionary<int, BasicRoom>();
            clients = new List<Client>();
            for (int i = 0; i < countOfRooms; ++i)
            {
                rooms.Add(i, new BasicRoom(i, random.Next(200, 1000)));
            }
        }

        public string Name { get { return name; } }

        public delegate void EventDelegate(string message);
        public static event EventDelegate ListOfClientsIsChanged;
        public static event EventDelegate ReqestIsSent;

        public void GetInfo()
        {
            foreach (var room in rooms.Values)
            {
                Console.WriteLine($"Id: {room.Id}\tIsOrdered: {room.IsOrdered}\tCost: {room.Cost}");
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
                if (rooms[id].RequestToOrder(ordererName))
                {
                    bool checker = false;
                    foreach (Client client in clients)
                    {
                        if (client.Name == ordererName)
                        {
                            client.AddRoom(id);
                            checker = true;
                            break;
                        }
                    }
                    if (!checker)
                    {
                        var newClient = new Client(ordererName);
                        newClient.AddRoom(id);
                        clients.Add(newClient);
                    }
                    ReqestIsSent?.Invoke($"Room № {id} is ordered by {ordererName} in a price of {rooms[id].Cost} $");
                    ListOfClientsIsChanged?.Invoke($"Room № {id} was ordered by {ordererName}");
                }
                else
                {
                    ReqestIsSent?.Invoke($"Room № {id} has already been ordered");
                }
            }
        }

        public void GetListOfEmptyRooms()
        {
            foreach (var room in rooms.Values)
            {
                if (!room.IsOrdered)
                {
                    Console.WriteLine($"Id: {room.Id}");
                }
            }
        }

        public void GetListOfRooms()
        {
            List<BasicRoom> tempList = rooms.Values.ToList();
            tempList.Sort((x, y) => x.Cost.CompareTo(y.Cost));
            foreach (var room in tempList)
            {
                Console.WriteLine($"Id: {room.Id}, Cost: {room.Cost}");
            }
        }
        public int GetCostOfAllOrderedRooms()
        {
            int cost = 0;
            foreach (var room in rooms)
            {
                if (room.Value.IsOrdered)
                {
                    cost += room.Value.Cost;
                }
            }
            return cost;
        }
        public string GetNameAndPriceOfClientWhoPaidMoreThanOthers(out int maxCost)
        {
            maxCost = 0;
            string name = "";
            foreach (var client in clients)
            {
                List<int> temp = client.NumbersOfRooms;
                int tempCost = 0;
                foreach (var number in temp)
                {
                    tempCost += rooms[number].Cost;
                }
                if (maxCost < tempCost)
                {
                    maxCost = tempCost;
                    name = client.Name;
                }
            }
            return name;
        }

        public void GetCostOfLiving(string ordererName)
        {
            foreach (var room in rooms.Values)
            {
                if (room.ClientName == ordererName)
                {
                    Console.WriteLine($"Cost of room: {room.Cost}");
                    return;
                }
            }
        }

        public List<string> getListOfClientsPaidMoreThan(int value)
        {
            List<string> list = new List<string>();
            foreach (var client in clients)
            {
                List<int> temp = new List<int>();
                foreach(var number in client.NumbersOfRooms) { temp.Add(rooms[number].Cost); }
                int tempCost = temp.Aggregate((x, y) => x + y);
                if (value < tempCost)
                {
                    list.Add(client.Name);
                }
            }
            return list;
        }

        public List<(int Category, int Qty)> GetRangeList(int firstBorder, int secondBorder)
        {
            return rooms.Values
                        .GroupBy(room => room.Cost < secondBorder ?  room.Cost < firstBorder ? 0 : 1 : 2)
                        .OrderBy(group => group.Key)
                        .Select(group => (group.Key, group.Count()))
                        .ToList();
        }

        public void GetIdOfMostPopularRoom()
        {
            BasicRoom mostPopularRoom = rooms.Values.OrderByDescending(r => r.Popularity).First();
            Console.WriteLine($"Id of most popular room: {mostPopularRoom.Id}");
        }

    }
}
