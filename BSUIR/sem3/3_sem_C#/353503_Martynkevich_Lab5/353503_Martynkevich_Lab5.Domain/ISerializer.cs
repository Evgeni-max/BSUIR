using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_Lab5.Domain
{
    public interface ISerializer
    {
        IEnumerable<RailroadStation> DeSerializeByLINQ(string fileName);
        IEnumerable<RailroadStation> DeSerializeXML(string fileName);
        IEnumerable<RailroadStation> DeSerializeJSON(string fileName);
        void SerializeByLINQ(IEnumerable<RailroadStation> xxx, string fileName);
        void SerializeXML(IEnumerable<RailroadStation> xxx, string fileName);
        void SerializeJSON(IEnumerable<RailroadStation> xxx, string fileName);
    }

}
