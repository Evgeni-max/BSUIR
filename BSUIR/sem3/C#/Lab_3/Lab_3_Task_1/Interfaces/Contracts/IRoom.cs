using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces.Contracts
{
    internal interface IRoom
    {
        int Id { get; set; }
        int Cost {  get; set; }
        bool IsOrdered { get; set; }
        string ClientName { get; set; }
        uint Popularity { get; set; }

        public bool RequestToOrder(string ordererName);
    }
}
