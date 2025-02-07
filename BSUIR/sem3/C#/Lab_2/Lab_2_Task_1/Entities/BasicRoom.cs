using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces.Contracts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Entities
{
    sealed class BasicRoom : Interfaces.Contracts.IRoom
    {
        int id;
        int cost;
        bool isOrdered;
        string clientName;
        uint popularity;
        public BasicRoom(int id, int cost)
        {
            this.id = id;
            this.cost = cost;
            this.isOrdered = false;
            this.clientName = "";
            this.popularity = 0;
        }
        public int Id { get { return id; } set { id = value; } }
        public int Cost { get { return cost; } set { cost = value; } }
        public bool IsOrdered { get { return isOrdered; } set { isOrdered = value; } }
        public string ClientName { get { return clientName; } set { clientName = value; } }
        public uint Popularity { get { return popularity; } set { popularity = value; } }

        public bool RequestToOrder(string ordererName)
        {
            ++popularity;
            if (!isOrdered) 
            {
                OrderRoom(ordererName);
                return true;
            }
            return false;
        }

        private void OrderRoom(string ordererName)
        {
            isOrdered = true;
            clientName = ordererName;
        }
    }
}
