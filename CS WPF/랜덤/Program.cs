using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 랜덤
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Random rand = new Random();
            
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(rand.Next(1, 10));//1~10
            }
        }
    }
}
