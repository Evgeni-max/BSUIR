using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_5.Domain
{
    public interface ISerializer
    {
        IEnumerable<Sportsman> DeSerializeByLINQ(string fileName);
        IEnumerable<Sportsman> DeSerializeXML(string fileName);
        IEnumerable<Sportsman> DeSerializeJSON(string fileName);
        void SerializeByLINQ(IEnumerable<Sportsman> xxx, string fileName);
        void SerializeXML(IEnumerable<Sportsman> xxx, string fileName);
        void SerializeJSON(IEnumerable<Sportsman> xxx, string fileName);
    }
}
