using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 형식변환_as
{
    internal class Program
    {
        static void Main(string[] args)
        {
            object o = "1234";
            string n = o as string;

            Console.WriteLine(n);
        }
    }
}
