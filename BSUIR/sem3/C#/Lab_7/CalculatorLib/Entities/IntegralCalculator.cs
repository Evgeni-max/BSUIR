using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace CalculatorLib.Entities
{
    public class IntegralCalculator
    {
        private static Semaphore _semaphore = new Semaphore(2, 5);
        public event Action<int, byte>? EventCalculation;
        public event Action<int, long, double>? EventFinish;
        public double CalculateSin(double firstBorder, double secondBorder, double step)
        {
            _semaphore.WaitOne();
            Stopwatch sw = Stopwatch.StartNew();
            double sin = 0;
            int counter = 0;
            while (firstBorder <= secondBorder)
            {
                firstBorder += step;
                sin += firstBorder * step;
                for (int i = 0; i < 100; ++i);
                if (counter % 1000 == 0)
                {
                    EventCalculation?.Invoke(Thread.CurrentThread.ManagedThreadId,
                                             (byte)(firstBorder * 100 / secondBorder));
                }
                ++counter;
            }
            sw.Stop();
            EventFinish?.Invoke(Thread.CurrentThread.ManagedThreadId,sw.ElapsedMilliseconds, sin);
            _semaphore.Release();
            return sin;
        }

        public void createNewSemaphore(int x, int y)
        {
            if (x < y) { x = y; }
            _semaphore = new Semaphore(y, x);
        }
    }
}
