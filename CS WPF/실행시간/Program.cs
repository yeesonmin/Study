using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 실행시간
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Stopwatch timer = new Stopwatch();
            timer.Start();
            Thread.Sleep(1000);
            timer.Stop();
            Console.WriteLine(timer.Elapsed.ToString());
        }
    }
}
