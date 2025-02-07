using _353503_Martynkech_Lab2.Collections;
using _353503_Martynkech_Lab2.Entities;
using System;
using static System.Runtime.InteropServices.JavaScript.JSType;
using System.Numerics;
using _353503_Martynkech_Lab2.Interfaces;

namespace _353503_Martynkech_Lab2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Journal journal = new();
            string str;
            EachWork eachWork = new EachWork();
            WorkList workList = new WorkList();
            MyCustomCollection<Worker> workers = new MyCustomCollection<Worker>();

            WorkList.workListIsChanged += journal.GetEvent;
            Worker.workIsChanged += GetEvent;
            //Worker.newWorker += journal.GetEvent;

            while (true)
            {
                Console.WriteLine("выберите или нажмите любую другую кнопку чтобы выйти:\n" +

                "1 - Добавить работу и зарплату за ее выполнение \n" +
                "2 - Добавить работника \n" +
                "3 - Вывести всех работников выполняющих определенную работу \n" +
                "4 - Вывести зарплату работника \n" +
                "5 - Вывести информацию по всем работникам \n" +
                "6 - Добавить работу определенному работнику \n");

                str = Console.ReadLine();

                if (str != "1" && str != "2" && str != "3" && str != "4" && str != "5" && str != "6") Environment.Exit(0);

                switch (int.Parse(str))
                {
                    case 1:
                        {
                            string work, strcost;
                            int cost;
                            Console.WriteLine("Введите название работы:");
                            work = Console.ReadLine();
                            Console.WriteLine("Введите зарплату за выполнение работы:");
                            strcost = Console.ReadLine();
                            while (!int.TryParse(strcost, out cost) || work == "" || work == " ")
                            {
                                Console.WriteLine("Введите название работы:");
                                work = Console.ReadLine();
                                Console.WriteLine("Введите зарплату за выполнение работы:");
                                strcost = Console.ReadLine();
                            }
                            workList.Add(new Pair<string, int>(work, cost));
                            eachWork.AddWork(work);
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("Введите ФИО работника:");
                            string workerr = Console.ReadLine();

                            while (workerr == "" || workerr == " ")
                            {
                                Console.WriteLine("Введите ФИО работника:");
                                workerr = Console.ReadLine();
                            }

                            workers.Add(new Worker(workerr));
                            break;
                        }
                    case 3:
                        {
                            int number;
                            string workName;

                            Console.WriteLine("Введите название работы:");
                            workName = Console.ReadLine();

                            while (workName == "" || workName == " ")
                            {
                                Console.WriteLine("Введите название работы:");
                                workName = Console.ReadLine();
                            }

                            MyCustomCollection<string> wrk = eachWork.Find(workName);

                            foreach (var wrkName in wrk)
                            {
                                Console.WriteLine(wrkName);
                            }
                            break;
                        }
                    case 4:
                        Console.WriteLine("Введите ФИО работника:");
                        string worker = Console.ReadLine();

                        while (worker == "" || worker == " ")
                        {
                            Console.WriteLine("Введите ФИО работника:");
                            worker = Console.ReadLine();
                        }

                        Worker worker3 = null;

                        while (true)
                        {
                            foreach (var work in workers)
                            {
                                if (work.name == worker) worker3 = work;
                            }

                            if (worker3 == null) Console.WriteLine("Не найден такой работник");
                            else break;

                            Console.WriteLine("Введите ФИО работника:");
                            worker = Console.ReadLine();
                        }

                        Console.WriteLine("Зарплата: " + Convert.ToString(worker3.salary));
                        break;
                    case 5:
                        {
                            eachWork.GiveInformation();
                            break;
                        }
                    case 6:
                        {
                            Console.WriteLine("Введите ФИО работника:");
                            string worker2 = Console.ReadLine();

                            while (worker2 == "" || worker2 == " ")
                            {
                                Console.WriteLine("Введите ФИО работника:");
                                worker2 = Console.ReadLine();
                            }
                            Worker worker4 = null;

                            while (true)
                            {
                                foreach (var work in workers)
                                {
                                    if (work.name == worker2) worker4 = work;
                                }

                                if (worker4 == null) Console.WriteLine("Не найден такой работник");
                                else break;

                                Console.WriteLine("Введите ФИО работника:");
                                worker2 = Console.ReadLine();
                            }

                            string workName;

                            workList.GiveInformation();

                            Console.WriteLine("Введите название работы:");
                            workName = Console.ReadLine();

                            Pair<string, int> workpair;

                            workpair = workList.Find(workName);
                            while (workpair.First == "NoFind")
                            {
                                Console.WriteLine("Введите название работы:");
                                workName = Console.ReadLine();
                                workpair = workList.Find(workName);
                            }

                            worker4.Add(workpair.Second, workName);

                            eachWork.AddWorker(workName, worker2);
                            break;
                        }
                    default:
                        break;
                }
            }

            Console.WriteLine("\nJournal messages:");
            foreach (string mes in journal)
            {
                Console.WriteLine($"\t{mes}");
            }
        }
        static void GetEvent(string message)
        {
            Console.WriteLine("Event has been uploaded in class Program");
            Console.WriteLine($"\tMessage: {message}");
        }
    }
}
