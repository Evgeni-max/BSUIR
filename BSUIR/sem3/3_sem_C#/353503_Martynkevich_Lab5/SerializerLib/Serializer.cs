using _353503_Martynkevich_Lab5.Domain;
using Newtonsoft.Json;
using System.Collections.Generic;
using System.Xml.Linq;
using System.Xml.Serialization;

namespace SerializerLib
{
    public class Serializer : ISerializer
    {
        public IEnumerable<RailroadStation> DeSerializeByLINQ(string fileName)
        {
            var xml = XElement.Load(fileName);

            var tempList = from dauther in xml.Elements()
                           where dauther.Name != "Noname"
                           select new
                           {

                               City = (string)dauther,
                               RentCost = (int)dauther.Element("RateCost"),
                               CountOfBagaje = (int)dauther.Element("Countofbagaje")
                           };
            List<RailroadStation> result = new List<RailroadStation>();
            foreach (var item in tempList)
            {
                result.Add(new RailroadStation(item.City, item.RentCost, item.CountOfBagaje));
            }

            return result;
        }
        public IEnumerable<RailroadStation> DeSerializeXML(string fileName) {
            var xml = new XmlSerializer(typeof(List<RailroadStation>));
            List<RailroadStation> result;

            using (FileStream fc = new FileStream(fileName, FileMode.Open, FileAccess.Read))
            {
                result = (List<RailroadStation>)xml.Deserialize(fc);
            }

            return result;
        }
        public IEnumerable<RailroadStation> DeSerializeJSON(string fileName) {
            string json_str;
            using (StreamReader wr = new StreamReader(fileName)) json_str = wr.ReadToEnd();

            var json = JsonConvert.DeserializeObject<IEnumerable<RailroadStation>>(json_str);
            return json;
        }
        public void SerializeByLINQ(IEnumerable<RailroadStation> xxx, string fileName) {
            var xml = new XElement("RailroadStationsofThePlanet");
            foreach (RailroadStation xxx2 in xxx) { 
               xml.Add(new XElement(xxx2.City,
                   new XElement("RateCost", xxx2.BagajeDepartment.RentCost),
                   new XElement("Countofbagaje", xxx2.BagajeDepartment.CountOfBagaje)));
            }

            xml.Save(fileName);
        }
        public void SerializeXML(IEnumerable<RailroadStation> xxx, string fileName) {
            var serializer = new XmlSerializer(typeof(List<RailroadStation>));

            using(FileStream fc = new FileStream(fileName, FileMode.Create ,FileAccess.Write))
            {
                 serializer.Serialize(fc, xxx);
            }
        }
        public void SerializeJSON(IEnumerable<RailroadStation> xxx, string fileName) { 
            string json = JsonConvert.SerializeObject(xxx, Formatting.Indented);

            using(StreamWriter wr = new StreamWriter(fileName))
            {
                wr.Write(json);
            }
        }
    }
}
