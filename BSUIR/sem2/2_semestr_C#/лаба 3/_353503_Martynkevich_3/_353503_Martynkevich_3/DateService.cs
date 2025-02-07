using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace _353503_Martynkevich_3
{
    internal class DateService
    {
        public string GetDay(string date)
        {
            int day = (date[0] - 48) * 10 + date[1] - 48;
            int month = (date[3] - 48) * 10 + date[4] - 48;
            int year = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;

            int YY = year % 100;
            int year_code = (YY + (YY / 4)) % 7;
            IDictionary<int, int> month_codes = new Dictionary<int, int> { { 1, 0 }, { 2, 3 }, { 3, 3 }, { 4, 6 }, { 5, 1 }, { 6, 4 }, { 7, 6 }, { 8, 2 }, { 9, 5 }, { 10, 0 }, { 11, 3 }, { 12, 5 } };

            int month_code = month_codes[month];

            int century_code = ((year / 100) % 20 - 3) * (-2);
            int date_number = day;
            bool leap_year_code = (IsLeap(year) && (month == 1 || month == 2));
            int dayOfWeek =  (year_code + month_code + century_code + date_number - Convert.ToInt32(leap_year_code)) % 7;

            switch (dayOfWeek)
            {
                case 0:
                    return "Воскресенье";
                case 1:
                    return "Понедельник";
                case 2:
                    return "Вторник";
                case 3:
                    return "Среда";
                case 4:
                    return "Четверг";
                case 5:
                    return "Пятница";
                case 6:
                    return "Суббота";
                default:
                    return "Ошибка";
            }
        }

        public int GetDaysSpan(string date)
        {

            int day = (date[0] - 48) * 10 + date[1] - 48;
            int month = (date[3] - 48) * 10 + date[4] - 48;
            int year = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;

            DateTime currentDate = DateTime.Now;

            int start_year = Math.Min(year, currentDate.Year);
            int days1 = DayOfYear(day, month, year), days2 = currentDate.DayOfYear;
            for (int i = start_year; i < year; i++)
            {
                days1 += (IsLeap(i) ? 366 : 365);
            }

            for (int i = start_year; i < currentDate.Year; i++)
            {
                days2 += (IsLeap(i) ? 366 : 365);
            }
            return Math.Abs(days2 - days1);
        }


        public bool IsLeap(int year)
        {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public int DayOfYear(int day, int month, int year)
        {
            int count = day;
            for (int i = 1; i < month; i++)
            {
                count += DaysInMonth(i, year);
            }
            return count;
        }

        public int DaysInMonth(int month, int year)
        {
            HashSet<int> day31 = new HashSet<int>{ 1, 3, 5, 7, 8, 10, 12 };

            if (month == 2)
            {
                return (IsLeap(year) ? 29 : 28);
            }
            else if (day31.Contains(month))
            {
                return 31;
            }
            else
            {
                return 30;
            }
        }
    }
}
