using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 형식_비교
{
    internal class Program
    {
        static void Main(string[] args)
        {
            object o = 123;

            if (o is int)
            {
                Console.WriteLine("int");
            }
            else if (o is double)
            {
                Console.WriteLine("double");
            }
        }
    }
}
