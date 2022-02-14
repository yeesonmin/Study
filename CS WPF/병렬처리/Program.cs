using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 병렬처리
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // 1. 순차적 실행
            // 동일쓰레드가 0~999 출력
            //
            Stopwatch timer = new Stopwatch();
            timer.Start();
            for (int i = 0; i <10_000; i++)
            {
               Console.WriteLine("{0}: {1}", Thread.CurrentThread.ManagedThreadId, i);
            }
            timer.Stop();
            Console.WriteLine(timer.Elapsed.ToString());
            Console.Read();

            // 2. 병렬 처리
            // 다중쓰레드가 병렬로 출력
            // 만약, 작업량이 적고 백그라운드로 진행한다면 순차가 더 빠를 수 있다.
            timer.Reset();
            Console.WriteLine("");
            timer.Start();
            Parallel.For(0, 10_000, (i) => {
                Console.WriteLine("{0}: {1}", Thread.CurrentThread.ManagedThreadId, i);
            });

            timer.Stop();
            Console.WriteLine(timer.Elapsed.ToString());
        }
    }
}
