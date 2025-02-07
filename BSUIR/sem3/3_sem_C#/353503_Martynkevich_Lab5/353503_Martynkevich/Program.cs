using _353503_Martynkevich_Lab5.Domain;
using SerializerLib;
using Microsoft.Extensions.Configuration.Json;
using Microsoft.Extensions.Configuration;

namespace _353503_Martynkevich
{
    internal class Program
    {
        static void Main(string[] args)
        {
            IConfiguration configuration = new ConfigurationBuilder()
             .SetBasePath(Directory.GetCurrentDirectory())
             .AddJsonFile("appsettings.json", optional: false, reloadOnChange: true)
             .Build();

            string LingToXMLFile = "linqToXML.txt";
            string XMLFile = "XML.txt";
            string JsonFile = configuration["filename"]!;
            string DirPath = "E:\\repos\\bsuir\\sem3\\3 семестр C#\\353503_Martynkevich_Lab5\\353503_Martynkevich\\files\\";
            
            Directory.CreateDirectory(DirPath);

            List<RailroadStation> railroadStations = new List<RailroadStation>();

            railroadStations.Add(new RailroadStation("Moscow", 1000, 2000));
            railroadStations.Add(new RailroadStation("Ekaterinburg", 800, 1600));
            railroadStations.Add(new RailroadStation("Leningrad", 600, 1300));
            railroadStations.Add(new RailroadStation("Voroneg", 500, 700));
            railroadStations.Add(new RailroadStation("Novosibirsk", 400, 400));
            railroadStations.Add(new RailroadStation("Omsk", 300, 200));

            Console.WriteLine("Original list of Railroad's Stations:");
            foreach (RailroadStation s in railroadStations)
            {
                Console.WriteLine($"Railroad Station`s city: {s.City}\t" +
                                  $"Rent per hour: {s.BagajeDepartment.RentCost}\t" +
                                  $"Count of Bagaje: {s.BagajeDepartment.CountOfBagaje}");
            }

            Serializer serializer = new Serializer();

            serializer.SerializeXML(railroadStations, DirPath + XMLFile);
            serializer.SerializeByLINQ(railroadStations, DirPath + LingToXMLFile);
            serializer.SerializeJSON(railroadStations, DirPath + JsonFile);

            List<RailroadStation> xmlList = serializer.DeSerializeXML(DirPath + XMLFile).ToList();
            List<RailroadStation> jsonList = serializer.DeSerializeJSON(DirPath + JsonFile).ToList();
            List<RailroadStation> linqList = serializer.DeSerializeByLINQ(DirPath + LingToXMLFile).ToList();

            Console.WriteLine("\nXML list of sportsmen:");
            foreach (RailroadStation s in xmlList)
            {
                Console.WriteLine($"Railroad Station`s city: {s.City}\t" +
                                  $"Rent per hour: {s.BagajeDepartment.RentCost}\t" +
                                  $"Count of Bagaje: {s.BagajeDepartment.CountOfBagaje}");
            }

            Console.WriteLine("\nJSON list of sportsmen:");
            foreach (RailroadStation s in jsonList)
            {
                Console.WriteLine($"Railroad Station`s city: {s.City}\t" +
                                  $"Rent per hour: {s.BagajeDepartment.RentCost}\t" +
                                  $"Count of Bagaje: {s.BagajeDepartment.CountOfBagaje}");
            }

            Console.WriteLine("\nLINQ list of sportsmen:");
            foreach (RailroadStation s in linqList)
            {
                Console.WriteLine($"Railroad Station`s city: {s.City}\t" +
                                  $"Rent per hour: {s.BagajeDepartment.RentCost}\t" +
                                  $"Count of Bagaje: {s.BagajeDepartment.CountOfBagaje}");
            }

            Console.WriteLine("\nEquations:");
            Console.WriteLine($"XML  is {(railroadStations.SequenceEqual(xmlList) ? "not " : string.Empty)}equal to original");
            Console.WriteLine($"LINQ is {(railroadStations.SequenceEqual(linqList) ? "not " : string.Empty)}equal to original");
            Console.WriteLine($"JSON is {(railroadStations.SequenceEqual(jsonList) ? "not " : string.Empty)}equal to original");

        }
    }
}
