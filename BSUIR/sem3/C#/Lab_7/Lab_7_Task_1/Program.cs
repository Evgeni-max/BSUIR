using CalculatorLib.Entities;
using System.ComponentModel.Design;
using System.Diagnostics;
using System.Runtime.CompilerServices;

namespace Lab_7_Task_1
{
    internal class Program
    {
        static bool checker = true;
        static public List<ThreadInformation> threadInformation = new List<ThreadInformation>();
        static void Main(string[] args)
        {
            PrintInformation();
            IntegralCalculator integralCalculator = new IntegralCalculator();
            integralCalculator.EventCalculation += GetInformation;
            integralCalculator.EventFinish += Finish;

            new Thread(() => { integralCalculator.CalculateSin(0, 1, 0.00000001); }) 
                             { Priority = ThreadPriority.Highest }.Start();
            new Thread(() => { integralCalculator.CalculateSin(0, 1, 0.00000001); }) 
                             { Priority = ThreadPriority.Lowest }.Start();

            while (checker) ;
            
            Console.WriteLine("Enter count of threads and count of threads to do at the same time");
            int countOfThreads = int.Parse(Console.ReadLine()!);
            int countOfThreadsAtTheSameTime = int.Parse(Console.ReadLine()!);
            integralCalculator.createNewSemaphore(countOfThreads,
                                                  countOfThreadsAtTheSameTime);

            threadInformation.Clear();
            checker = true;
            PrintInformation();
            for (int i = 0; i < countOfThreads; ++i)
            {
                new Thread(() => { integralCalculator.CalculateSin(0, 1, 0.00000001); }).Start();
            }
            while (checker) ;
        }
        public static void GetInformation(int id, byte status)
        {
            bool contains = false;
            int i;
            for (i = 0; i < threadInformation.Count; ++i)
            {
                if (threadInformation[i].Id == id)
                {
                    contains = true;
                    break;
                }
            }
            if (!contains)
            {
                threadInformation.Add(new ThreadInformation() { Id = id, Status = status });
            }
            else
            {
                threadInformation[i].Status = status;
            }
        }

        public static void Finish(int id, long time, double result)
        {
            int i;
            for (i = 0; i < threadInformation.Count; ++i)
            {
                if (threadInformation[i].Id == id)
                {
                    break;
                }
            }
            threadInformation[i].IsCompleted = true;
            threadInformation[i].Status = 100;
            threadInformation[i].Time = time;
            threadInformation[i].Result = result;
        }
        async public static void PrintInformation()
        {
            while (checker)
            {
                Console.Clear();
                for (int i = 0; i < threadInformation.Count; ++i)
                { 
                    if (!threadInformation[i].IsCompleted)
                    {
                        Console.Write($"Поток {threadInformation[i].Id}:[");
                        for (int j = 0; j < threadInformation[i].Status / 5; j++)
                        {
                            Console.Write('=');
                        }
                        Console.Write('>');
                        for (int j = 0; j < 19 - threadInformation[i].Status / 5; j++)
                        {
                            Console.Write(' ');
                        }
                        Console.WriteLine($"] {threadInformation[i].Status}%");
                    }
                    else
                    {
                        Console.Write($"Поток {threadInformation[i].Id}:[");
                        for (int j = 0; j < 20; j++)
                        {
                            Console.Write('=');
                        }
                        Console.WriteLine($"] 100% {threadInformation[i].Time} ms. \t " +
                                          $"result = {threadInformation[i].Result}");
                    }
                }
                if (threadInformation.Count > 0) {
                bool checkerForChecker = false;
                for (int i = 0; i < threadInformation.Count; ++i)
                {
                    if (!threadInformation[i].IsCompleted )
                    {
                        checkerForChecker = true;
                        break;
                    }
                }
                    if (!checkerForChecker)
                    {
                        checker = false;
                    }
                }
                await Task.Delay(100);
            }
        }
    }
}
