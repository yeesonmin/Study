using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LINQ
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] vs = { 1, 2, 3 };
            int sum = vs.Sum();
            int cnt = vs.Count();
            double avg = vs.Average();
            int max = vs.Max();
            int min = vs.Min();

            Console.WriteLine(sum);
            Console.WriteLine(cnt);
            Console.WriteLine(avg);
            Console.WriteLine(max);
            Console.WriteLine(min);

            int[] vs2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            List<int> vs3 =vs2.Where(x => x > 3 && x % 2 == 0).ToList();
            
            Console.WriteLine();
            foreach (var item in vs3)
            {
                Console.WriteLine(item);
            }

            int[] vs4 = { 2, 4, 6, 8 };
            if(vs4.All(x => x % 2 == 0))
            {
                Console.WriteLine("True");
            }
            else
            {
                Console.WriteLine("False");
            }

            int[] vs5 = { 1, 2, 4, 6, 8 };
            if (vs5.Any(x => x % 2 == 1))
            {
                Console.WriteLine("True");
            }
            else
            {
                Console.WriteLine("False");
            }

            var d1 = Enumerable.Range(0, 100);//0~99
            foreach (var item in d1.Take(5))
            {
                Console.WriteLine(item.ToString());//앞에서 5개 출력
            }

            foreach (var item in d1.Where(x=> x%2 == 0).Take(5))
            {
                Console.WriteLine(item.ToString());//앞에서 짝수 5개 출력
            }
            foreach (var item in d1.Where(x => x % 2 == 0).Skip(10).Take(5))
            {
                Console.WriteLine(item.ToString());//앞에서 짝수 10개 넘어가고 5개 출력
            }

            List<int> d2 = Enumerable.Repeat(3, 5).ToList();//3 5개 저장
            List<int> result = d2.Distinct().ToList();
            foreach (var item in result)
            {
                Console.WriteLine(item.ToString());
            }

            List<string> name  = new List<string>() { "Apple", "Candy", "Grape" };
            List<string> resultname = name.Where(x => x.ToUpper().Contains("E")).ToList();//대문자로 변환해서 E가 있는 값
            foreach (var item in resultname)
            {
                Console.WriteLine(item.ToString());
            }

            int[] num = { 1, 2, 3, 4, 5 };
            var nums = num.Select(x => x * x);//제곱함.
            foreach (var item in nums)
            {
                Console.WriteLine(item.ToString());
            }
        }
    }
}
