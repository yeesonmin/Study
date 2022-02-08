using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 시간_차이_TimeSpan
{
    internal class Program
    {
        static void Main(string[] args)
        {
            TimeSpan timeSpan;
            DateTime t1 = DateTime.Now;
            Thread.Sleep(5000);
            DateTime t2 = DateTime.Now;

            timeSpan = t2.Subtract(t1);
            Console.WriteLine(timeSpan.ToString());

        }
    }
}
