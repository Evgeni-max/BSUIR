using System;

namespace Problem
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                string nameCompany, str, f, i, nameOfZakaz;
                int cost, mass;
                Console.WriteLine("Введите название компании:");
                nameCompany = Console.ReadLine();

                Company myCompany = Company.GetInstance();
                myCompany.SetCompanyName(nameCompany);

                while (true)
                {
                    Console.WriteLine("выберите или нажмите любую другую кнопку чтобы выйти:\n" +

                    "1 - информация о компании \n" +
                    "2 - добавить тариф компании \n" +
                    "3 - изменить тариф\n" +
                    "4 - добавить скидку \n" +
                    "5 - минимальный тариф \n");

                    str = Console.ReadLine();

                    if (str != "1" && str != "2" && str != "3" && str != "4" && str != "5") Environment.Exit(0);

                    switch (int.Parse(str))
                    {
                        case 1:
                            {
                                Console.WriteLine("имя компании: {0}", myCompany.GetCompanyName());
                                //Console.WriteLine("Общая выручка: {0}", allCost);

                                Console.WriteLine("Все тарифы: ");

                                for (int j = 0; j < Company.icosts.Count(); ++j)
                                {
                                    Console.WriteLine(j + " : " + Company.icosts[j].GetPrice());
                                }
                                break;
                            }
                        case 2:
                            {
                                Console.WriteLine("Добавьте цену за перевозку одной тонны груза:");
                                str = Console.ReadLine();

                                while (!int.TryParse(str, out mass))
                                {
                                    Console.WriteLine("Добавьте цену за перевозку одной тонны груза:");
                                    str = Console.ReadLine();
                                }

                                Console.WriteLine("Введите название тарифа:");
                                string name = Console.ReadLine();

                                myCompany.AddTarif(new(mass, name));
                                break;
                            }
                        case 3:
                            {
                                int number1;

                                Console.WriteLine("Введите номер изменяемого тарифа:");
                                str = Console.ReadLine();

                                while (!int.TryParse(str, out number1) || number1 < 0 || number1 >= Company.tarife.Count)
                                {
                                    Console.WriteLine("Введите номер изменяемого тарифа:");
                                    str = Console.ReadLine();
                                }

                                Console.WriteLine("Введите цену за тонну груза:");
                                str = Console.ReadLine();

                                while (!int.TryParse(str, out cost))
                                {
                                    Console.WriteLine("Введите цену за тонну груза:");
                                    str = Console.ReadLine();
                                }

                                Company.tarife[number1].cost = cost;
                                break;
                            }
                        case 4:
                            int number;

                            Console.WriteLine("Введите номер тарифа:");
                            str = Console.ReadLine();

                            while (!int.TryParse(str, out number) || number < 0 || number >= Company.tarife.Count)
                            {
                                Console.WriteLine("Введите номер изменяемого тарифа:");
                                str = Console.ReadLine();
                            }

                            Console.WriteLine("Введите скидку:");
                            str = Console.ReadLine();

                            while (!int.TryParse(str, out cost))
                            {
                                Console.WriteLine("Введите скидку:");
                                str = Console.ReadLine();
                            }

                            myCompany.AddDiscount(number, cost);
                            break;
                        case 5:
                            Console.WriteLine(myCompany.minCost);
                            break;

                        default:
                            break;
                    }
                }
            }
            catch(Exception ex) { Console.WriteLine(ex.ToString()); } 
        }
    }
}
