namespace Problem
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string nameCompany, str, f, i, nameOfZakaz;
            int cost, mass;
            Console.WriteLine("Введите название компании:");
            nameCompany = Console.ReadLine();

            Company myCompany = Company.GetInstance();
            myCompany.SetCompanyName(nameCompany);

            Console.WriteLine("Пройдите регистрацию:");
            Console.WriteLine("1. Введите фамилию:");
            f = Console.ReadLine();
            Console.WriteLine("2. Введите имя:");
            i = Console.ReadLine();

            Person person = new(f, i);

            while (true)
            {
                Console.WriteLine("выберите или нажмите любую другую кнопку чтобы выйти:\n" +

                "1 - информация о компании \n" +
                "2 - добавить тариф компании \n" +
                "3 - изменить тариф\n" +
                "4 - информация о заказчике \n" +
                "5 - добавить заказ \n");

                str = Console.ReadLine();

                if (str != "1" && str != "2" && str != "3" && str != "4" && str != "5") Environment.Exit(0);

                switch (int.Parse(str))
                {
                    case 1:
                        {
                            myCompany.GetInformation();
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

                            myCompany.AddTarif(new(mass));
                            break;
                        }
                    case 3:
                        {
                            int number;

                            Console.WriteLine("Введите номер изменяемого тарифа:");
                            str = Console.ReadLine();

                            while (!int.TryParse(str, out number) || number < 0 || number >= Company.tarife.Count)
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

                            Company.tarife[number].cost = cost;
                            break;
                        }
                    case 4:
                        person.GetInformation();
                        break;
                    case 5:
                        Console.WriteLine("Добавьте массу груза:");
                        str = Console.ReadLine();

                        while (!int.TryParse(str, out mass))
                        {
                            Console.WriteLine("Добавьте массу груза:");
                            str = Console.ReadLine();
                        }

                        Console.WriteLine("Введите номер тарифа: ");

                        for (int j = 0; j < Company.tarife.Count; ++j)
                        {
                            Console.WriteLine(j + " : " + Company.tarife[j].cost);
                        }

                        int buffer = Convert.ToInt32(Console.ReadLine());

                        if (buffer < 0 || buffer >= Company.tarife.Count)
                        {
                            Console.WriteLine("Ошибка ");
                        }
                        else
                            person.AddZakaz(mass, Company.tarife[buffer]);
                        break;

                    default:
                        break;
                }
            }
        }
    }
}
