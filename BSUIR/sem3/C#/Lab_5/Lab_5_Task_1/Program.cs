using Lab_5.Domain;
using SerializerLib;
using Microsoft.Extensions.Configuration.Json;
using Microsoft.Extensions.Configuration;

namespace Lab_5_Task_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            IConfiguration configuration = new ConfigurationBuilder()
            .SetBasePath(Directory.GetCurrentDirectory())
            .AddJsonFile("appsettings.json", optional: false, reloadOnChange: true)
            .Build();

            const string XmlFileName = "xml.xml";
            const string LinqToXmlFileName = "linq.xml";
                  string JsonFileName = configuration["filename"]!;
            const string DirPath = @"G:\Projects\C#\Labs\SEM_3\Lab_5\Lab_5_Task_1\Files\";

            Directory.CreateDirectory(DirPath);

            List<Sportsman> sportsmen = new List<Sportsman>()
            {
                new Sportsman("Kevin", 42, new SportType("Tennis",     33)),
                new Sportsman("Semen", 67, new SportType("Football",   73)),
                new Sportsman("Glebe", 23, new SportType("Volleyball", 56)),
                new Sportsman("Tanya", 56, new SportType("Cricket",    13)),
                new Sportsman("Henry", 34, new SportType("Golf",       17)),
                new Sportsman("Stas",  28, new SportType("Cybersport", 100))
            };

            Console.WriteLine("Original list of sportsmen:");
            foreach (Sportsman s in sportsmen)
            {
                Console.WriteLine($"Sportsman`s name: {s.Name}\t" +
                                  $"age: {s.Age}\t" +
                                  $"sport name: {s.SportTypeName}\t" +
                                  $"sport popularity: {s.SportTypePopularity}");
            }

            Serializer serializer = new Serializer();

            serializer.SerializeXML(sportsmen, DirPath + XmlFileName);
            serializer.SerializeByLINQ(sportsmen, DirPath + LinqToXmlFileName);
            serializer.SerializeJSON(sportsmen, DirPath + JsonFileName);

            List<Sportsman> xmlList = serializer.DeSerializeXML(DirPath + XmlFileName).ToList();
            List<Sportsman> jsonList = serializer.DeSerializeJSON(DirPath + JsonFileName).ToList();
            List<Sportsman> linqList = serializer.DeSerializeByLINQ(DirPath + LinqToXmlFileName).ToList();

            Console.WriteLine("\nXML list of sportsmen:");
            foreach (Sportsman s in xmlList)
            {
                Console.WriteLine($"Sportsman`s name: {s.Name}\t" +
                                  $"age: {s.Age}\t" +
                                  $"sport name: {s.SportTypeName}\t" +
                                  $"sport popularity: {s.SportTypePopularity}");
            }

            Console.WriteLine("\nJSON list of sportsmen:");
            foreach (Sportsman s in jsonList)
            {
                Console.WriteLine($"Sportsman`s name: {s.Name}\t" +
                                  $"age: {s.Age}\t" +
                                  $"sport name: {s.SportTypeName}\t" +
                                  $"sport popularity: {s.SportTypePopularity}");
            }

            Console.WriteLine("\nLINQ list of sportsmen:");
            foreach (Sportsman s in linqList)
            {
                Console.WriteLine($"Sportsman`s name: {s.Name}\t" +
                                  $"age: {s.Age}\t" +
                                  $"sport name: {s.SportTypeName}\t" +
                                  $"sport popularity: {s.SportTypePopularity}");
            }

            Console.WriteLine("\nEquations:");
            Console.WriteLine($"XML  is {(sportsmen.SequenceEqual(xmlList)  ? "not " : string.Empty)}equal to original");
            Console.WriteLine($"LINQ is {(sportsmen.SequenceEqual(linqList) ? "not " : string.Empty)}equal to original");
            Console.WriteLine($"JSON is {(sportsmen.SequenceEqual(jsonList) ? "not " : string.Empty)}equal to original");

        }
    }
}
