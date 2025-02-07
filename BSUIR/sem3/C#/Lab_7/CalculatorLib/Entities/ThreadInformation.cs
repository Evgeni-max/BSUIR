using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CalculatorLib.Entities
{
    public class ThreadInformation
    {
        public bool IsCompleted { get; set; } = false;
        public int Id { get; set; }
        public byte Status { get; set; }
        public long Time { get; set; }
        public double Result { get; set; }
    }
}
