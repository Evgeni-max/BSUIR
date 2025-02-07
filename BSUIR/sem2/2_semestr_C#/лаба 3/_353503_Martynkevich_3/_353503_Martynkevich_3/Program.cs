using System.Globalization;

namespace _353503_Martynkevich_3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            DateService dateService = new DateService();
            DateTime dateValue;

            string str;

            do
            {
                Console.WriteLine("Введите дату в формате dd:MM:yyyy ");
                str = Console.ReadLine();

            } while (!DateTime.TryParseExact(str, "dd:MM:yyyy", CultureInfo.InvariantCulture, DateTimeStyles.None, out dateValue));


            Console.WriteLine(dateService.GetDaysSpan(str));

            Console.WriteLine(dateService.GetDay(str));
        }
    }
}
