using _353503_Martynkech_Lab3.Collections;
using _353503_Martynkech_Lab3.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkech_Lab3.Entities
{
    internal class PayrollDepartment
    {
        public Journal journal;
        public EachWork eachWork;
        public WorkList workList;
        public List<Worker> workers;
        public PayrollDepartment() {
            journal = new();
            eachWork = new EachWork();
            workList = new WorkList();
            workers = new List<Worker>();
        }

        public void AddWorker(string nameOfWorker)
        {
            Worker worker = new Worker(nameOfWorker);
            workers.Add(worker);
        }

        public IEnumerable<Worker> GetWorkersWithHigherSalary() {
            int maxSalary = workers.Max(w => w.salary); 
            var w = workers.Where(w => w.salary == maxSalary);
            var result = w.ToArray();

            //

            return w.ToArray();



        }

        /*public void PrintWorkersListOfPayments(string firstName)
        {
            Worker? current = workers.Find(x => x.name == firstName);
            if (current != null)
            {
                var groupedPayments = current.GetListOfWork()
                    .GroupBy(p => workList.Find(p)
                    .Select(g => new
                    {
                        tariff = g.Key,
                        TotalPrice = g.Sum(p => p.Cost)
                    });

                groupedPayments.ToList();

                //

                Console.WriteLine($"Payment List for {firstName}:");
                foreach (var payment in groupedPayments)
                    Console.WriteLine($"{payment.tariff}:{payment.TotalPrice}");
                Console.WriteLine("-----------------------");
            }
        }
        */
        public void PrintWorkersListOfPayments(string firstName)
        {
            // Находим работника по имени
            Worker? current = workers.Find(x => x.name == firstName);
            if (current != null)
            {
                // Получаем список всех работ, выполненных сотрудником
                var groupedPayments = current.GetListOfWork()
                    .GroupBy(
                        work => work, // Группируем по названию работы
                        (key, works) => new
                        {
                            Tariff = key,
                            TotalPrice = works.Count() * workList.Find(key) // Умножаем количество работ на их стоимость
                        }
                    );

                // Выводим результат
                Console.WriteLine($"Payment List for {firstName}:");
                foreach (var payment in groupedPayments)
                {
                    Console.WriteLine($"{payment.Tariff}: {payment.TotalPrice}");
                }
                Console.WriteLine("-----------------------");
            }
            else
            {
                Console.WriteLine($"Worker {firstName} not found.");
            }
        }

    }
}
