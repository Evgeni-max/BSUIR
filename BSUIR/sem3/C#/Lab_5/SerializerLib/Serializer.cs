using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using Lab_5.Domain;
using System.Xml.Linq;
using System.Xml.Serialization;
using System.Text.Json;
using System.IO;

namespace SerializerLib
{
    public class Serializer : ISerializer
    {
        public IEnumerable<Sportsman> DeSerializeByLINQ(string fileName)
        {
            var xDoc = XDocument.Load(fileName);
            var xEl = xDoc.Element("Sportsmen");
            List<Sportsman> result = new List<Sportsman>();
            foreach (var s in xEl!.Elements("Sportsman"))
            {
                string name = s.Attribute("name")!.Value;
                byte age = byte.Parse(s.Attribute("age")!.Value);
                XElement sportType = s.Element("SportType")!;

                string sportName = sportType.Attribute("sportName")!.Value;
                byte sportPopularity = byte.Parse(sportType.Attribute("sportPopularity")!.Value);

                result.Add(new Sportsman(name, age, new SportType(sportName, sportPopularity)));
            }
            return result;
        }

        public IEnumerable<Sportsman> DeSerializeJSON(string fileName)
        {
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                return JsonSerializer.DeserializeAsync<List<Sportsman>>(fs).Result!;
            }
        }

        public IEnumerable<Sportsman> DeSerializeXML(string fileName)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<Sportsman>));
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                return (List<Sportsman>)xmlSerializer.Deserialize(fs)!;
            }
        }

        public void SerializeByLINQ(IEnumerable<Sportsman> xxx, string fileName)
        {
            XDocument xDoc = new XDocument();
            XElement sportsmen = new XElement("Sportsmen");
            foreach (Sportsman s in xxx)
            {
                XElement xElement = new XElement("Sportsman");
                XAttribute name = new XAttribute("name", s.Name);
                XAttribute age = new XAttribute("age", s.Age);
                XElement sportType = new XElement("SportType");
                XAttribute sportName = new XAttribute("sportName", s.SportTypeName);
                XAttribute sportPopularity = new XAttribute("sportPopularity", s.SportTypePopularity);

                xElement.Add(name);
                xElement.Add(age);
                sportType.Add(sportName);
                sportType.Add(sportPopularity);
                xElement.Add(sportType);

                sportsmen.Add(xElement);
            }
            xDoc.Add(sportsmen);
            xDoc.Save(fileName);
        }

        async public void SerializeJSON(IEnumerable<Sportsman> xxx, string fileName)
        {
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                await JsonSerializer.SerializeAsync(fs, xxx.ToList());
            }
        }

        public void SerializeXML(IEnumerable<Sportsman> xxx, string fileName)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<Sportsman>));
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                xmlSerializer.Serialize(fs, xxx.ToList());
            }
        }
    }
}
