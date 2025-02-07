using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_3_Task_1.Entities
{
    internal class Client
    {
        private string name;
        public string Name { get { return name; } }

        private List<int> numbersOfRooms;

        public List<int> NumbersOfRooms {  get { return numbersOfRooms; } }
        public Client(string name) 
        {
            this.name = name;   
            numbersOfRooms = new List<int>();
        }

        public void AddRoom(int RoomNumber) 
        {
            numbersOfRooms.Add(RoomNumber);
            numbersOfRooms.Sort();
        }
    }
}
