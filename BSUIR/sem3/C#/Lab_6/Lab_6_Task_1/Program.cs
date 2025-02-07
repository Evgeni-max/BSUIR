using System.Text.Json;
using Lab_6_Task_1.Entities;
using System.Reflection;
using Lab_6_Task_1.Interfaces;
using System.Security.AccessControl;

namespace Lab_6_Task_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            const string DirPath = @"..\..\..\data\";
            const string JSONFileName = "json.json";

            if (File.Exists(DirPath + JSONFileName))
            {
                File.Delete(DirPath + JSONFileName);
            }
            File.Create(DirPath + JSONFileName).Close();

            List<Employee> employees = new List<Employee>
            {
                new Employee(23, false, "Evgeni"),
                new Employee(54, false, "Sasha"),
                new Employee(32, true, "Alexey"),
                new Employee(78, true, "Katia"),
                new Employee(24, false, "Daniil"),
                new Employee(29, true, "Glebe")
            };

            Console.WriteLine("Original list:");
            foreach (var employee in employees)
            {
                Console.WriteLine($"Name: {employee.Name}\t " +
                                  $"Age: {employee.Age}\t " +
                                  $"Is Married {employee.IsMarried}");
            }

            Assembly assembly = Assembly.LoadFrom(@"..\..\..\..\ClassLib\bin\Debug\net8.0\ClassLib.dll");
            Type fileServiceType = assembly.GetType("ClassLib.FileService`1")?.MakeGenericType(typeof(Employee))!;
            IFileService<Employee>? fileService = Activator.CreateInstance(fileServiceType!) as IFileService<Employee>;
            fileService?.SaveData(employees, DirPath + JSONFileName);
            List<Employee> newList = fileService?.ReadFile(DirPath + JSONFileName).ToList()!;

            Console.WriteLine("\nNew list:");
            foreach (var employee in newList)
            {
                Console.WriteLine($"Name: {employee.Name}\t " +
                                  $"Age: {employee.Age}\t " +
                                  $"Is Married {employee.IsMarried}");
            }
        }
    }
}