using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 열거형
{
    enum MyEnum
    {
        가 = 1,
        나,
        다,
        라
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = (int)MyEnum.가;
            string s = MyEnum.라.ToString();
            Console.WriteLine("{0} {1}",n,s);

        }
    }
}
