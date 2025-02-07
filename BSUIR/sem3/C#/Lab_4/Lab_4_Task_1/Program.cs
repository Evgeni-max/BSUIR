

using Lab_4_Task_1.Entities;

namespace Lab_4_Task_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            const string dirPath = @"G:\Projects\C#\SEM_3\Lab_4\Lab_4_Task_1\BURCHUK_Lab4\";
            if (Directory.Exists(dirPath))
            {
                Directory.Delete(dirPath, true);
            }
            Directory.CreateDirectory(dirPath);

            for (int i = 0; i < 10; ++i)
            {
                string fileName = Path.GetRandomFileName();
                File.Create(dirPath + fileName).Close();
            }

            Console.WriteLine("Files, created in runtime:");
            for (int i = 0; i < 10; ++i)
            {
                string fileName = Directory.GetFiles(dirPath).ElementAt(i).Split('\\').Last();
                Console.WriteLine($"File name: {fileName.Split('.').First()} \t" +
                                  $"File type: {fileName.Split('.').Last()}");
            }

            List<Entities.Patient> patients = new List<Entities.Patient>();

            patients.Add(new Entities.Patient("Oleg", 34, true));
            patients.Add(new Entities.Patient("Vlad", 35, true));
            patients.Add(new Entities.Patient("Kola",21, false));
            patients.Add(new Entities.Patient("Katia", 89, true));
            patients.Add(new Entities.Patient("Glebe", 67, true));
            patients.Add(new Entities.Patient("Semen", 54, true));

            const string myFileName = "myFile.bin"; 
            const string newFileName = "newFile.bin";

            Entities.FileService fileService = new Entities.FileService();

            fileService.SaveData(patients, dirPath + myFileName);
            Entities.FileService.RenameFile(dirPath + myFileName, dirPath + newFileName);

            List<Entities.Patient> newPatients = fileService.ReadFile(dirPath + newFileName).ToList();

            Console.WriteLine("\nOld list of patients:");
            for (int i = 0; i < patients.Count; ++i)
            {
                Console.WriteLine($"Patient`s name: {patients[i].Name} \t" +
                                  $"Patient`s id: {patients[i].Id} \t" +
                                  $"Patient infection status: {patients[i].Infected}");
            }

            newPatients = newPatients.OrderBy(x => x, new MyCustomComparer()).ToList();

            Console.WriteLine("\nNew list of patients:");
            for (int i = 0; i < newPatients.Count; ++i)
            {
                Console.WriteLine($"Patient`s name: {newPatients[i].Name} \t" +
                                  $"Patient`s id: {newPatients[i].Id} \t" +
                                  $"Patient infection status: {newPatients[i].Infected}");
            }
        }   
    }
}
