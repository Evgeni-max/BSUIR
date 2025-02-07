using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces.Contracts
{
    internal interface IHotel
    {
        public string Name { get; }

        public void GetInfo();

        public void RequestRoom(string ordererName, int id);

        public void GetListOfEmptyRooms();

        public void GetCostOfLiving(string ordererName);

        public void GetIdOfMostPopularRoom();
    }
}
