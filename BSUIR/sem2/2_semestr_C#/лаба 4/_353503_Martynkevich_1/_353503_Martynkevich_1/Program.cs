namespace _353503_Martynkevich_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string nameCompany, str;
            int cost, mass;
            Console.WriteLine("Введите название компании:");
            nameCompany = Console.ReadLine();

            Console.WriteLine("Введите цену за тонну груза:");
            str = Console.ReadLine();

            while (!int.TryParse(str, out cost))
            {
                Console.WriteLine("Введите цену за тонну груза:");
                str = Console.ReadLine();
            }

            Console.WriteLine("Добавьте массу груза:");
            str = Console.ReadLine();

            while (!int.TryParse(str, out mass))
            {
                Console.WriteLine("Добавьте массу груза:");
                str = Console.ReadLine();
            }

            Company myCompany = Company.GetInstance(nameCompany, cost);
            myCompany.AddTarif(new(mass));

            while (true)
            {
                Console.WriteLine("выберите или нажмите любую другую кнопку чтобы выйти:\n" +
               
                "1 - информация о компании \n" +
                "2 - добавить транспорт \n" +
                "3 - изменить тариф");

                str = Console.ReadLine();

                switch (int.Parse(str))
                {
                    case 1:
                        {
                            myCompany.GetInformation();
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("Добавьте массу груза:");
                            str = Console.ReadLine();

                            while (!int.TryParse(str, out mass))
                            {
                                Console.WriteLine("Добавьте массу груза:");
                                str = Console.ReadLine();
                            }

                            myCompany.AddTarif(new(mass));
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("Введите цену за тонну груза:");
                            str = Console.ReadLine();

                            while (!int.TryParse(str, out cost))
                            {
                                Console.WriteLine("Введите цену за тонну груза:");
                                str = Console.ReadLine();
                            }

                            myCompany.SetCostPerTonn(cost);
                            break;
                        }
                    default:
                        Environment.Exit(0);
                        break;
                }
            }
        }
    }
}
