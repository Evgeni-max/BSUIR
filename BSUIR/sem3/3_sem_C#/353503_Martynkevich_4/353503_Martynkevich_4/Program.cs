using _353503_Martynkevich_4.Entities;
using System;
using static System.Runtime.InteropServices.JavaScript.JSType;
using System.Numerics;
using _353503_Martynkevich_4.Interfaces;
using System.IO;

namespace _353503_Martynkech_Lab4
{
    internal class Program
    {
        static void Main(string[] args)
        {

            DirectoryInfo dirInfo = new DirectoryInfo("E:\\repos\\bsuir\\sem3\\3 семестр C#\\353503_Martynkevich_4\\Martynkevich_Lab4");

            if (dirInfo.Exists)
            {
                foreach (FileInfo file in dirInfo.GetFiles())
                {
                    file.Delete();
                }
                foreach (DirectoryInfo dir in dirInfo.GetDirectories())
                {
                    dir.Delete(true);
                }

                Console.WriteLine($"Directory {dirInfo.Name} exists. Content deleted.");
            }
            else
            {
                dirInfo.Create();

                for (int i = 0; i < 10; i++) {
                    string path = Path.GetTempFileName();
                    FileInfo pathName = new FileInfo(path);
                    path = Path.Combine(dirInfo.FullName, pathName.Name);
                    File.Create(path);
                }

                foreach(FileInfo file in dirInfo.GetFiles())
                {
                    Console.WriteLine($"Файл: {Path.GetFileNameWithoutExtension(file.Name)} имеет расширение {file.Extension}");
                }
            }

            List<Client> oldclients = new List<Client>();
            oldclients.Add(new Client("Kate", "Dubovskai"));
            oldclients.Add(new Client("Paul", "Romanova"));
            oldclients.Add(new Client("Petr", "Kraicheva"));
            oldclients.Add(new Client("Mihail", "Osipova"));
            oldclients.Add(new Client("Diana", "Smirnova"));

            string oldpath = Path.Combine(dirInfo.FullName, "oldtext.txt");
            FileStream fs = File.Create(oldpath);
            fs.Dispose();

                try
                {
                    FileService.SaveData(oldclients, oldpath);  
                }
                catch (Exception e)
                {
                    Console.WriteLine($" ---> {e.Message}");
                }
            

            string newpath = Path.Combine(dirInfo.FullName, "newtext.txt");
            try
            {
                File.Move(oldpath, newpath);
            }
            catch (Exception ex) { 
                Console.WriteLine(ex.ToString());
            }

            List<Client> newclients = new List<Client>(FileService.ReadFile(newpath));

            foreach (Client client in newclients) { 
               Console.WriteLine($"Id: {client.Id} Name: {client.Name} Name of Mum: {client.MumName}");
            }
            Console.WriteLine("");

            var sortedByName = newclients.OrderBy(client => client.Name);
            foreach (Client client in sortedByName)
            {
                Console.WriteLine($"Id: {client.Id} Name: {client.Name} Name of Mum: {client.MumName}");
            }
            Console.WriteLine("");

            MyCustomComparer comparer = new MyCustomComparer();
            newclients.Sort(comparer);
            foreach (Client client in newclients)
            {
                Console.WriteLine($"Id: {client.Id} Name: {client.Name} Name of Mum: {client.MumName}");
            }
        }
    }
}
