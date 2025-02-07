using PatientsLib.Entities;
using StreamServiceLib.Entities;
using System.Reflection;

namespace Lab_8_Task_1
{
    internal class Program
    {
        public static async Task Main(string[] args)
        {
            var streamService = new StreamService<BasicPatient>();
            var stream = new MemoryStream();
            Progress<string> progress = new(Console.WriteLine);

            var rand = new Random();
            List<BasicPatient> patients = new List<BasicPatient>();
            for (int i = 0; i < 1000; ++i)
            {
                patients.Add(new(LoremNET.Lorem.Words(1),rand.Next(20,56),(Diagnoses)rand.Next(0,8)));
            }

            //await Console.Out.WriteLineAsync($"------> {Thread.CurrentThread.ManagedThreadId}");

            Task task1 = streamService.WriteToStreamAsync(stream, patients, progress);
            await Task.Delay(300);

            Task task2 = streamService.CopyFromStreamAsync(stream, "stream1.xml", progress);
            Task.WaitAll(task1, task2);

            Task<int>? result = streamService.GetStatisticsAsync("stream1.xml", patient => patient.Diagnose == Diagnoses.Schizophrenia);
            Console.WriteLine($"Number of patients with Schizophrenia: {await result}");


        }
    }
}
