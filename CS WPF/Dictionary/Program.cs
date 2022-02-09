using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dictionary
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Dictionary<int,string> dic = new Dictionary<int,string>();
            Dictionary<string,int > dic2 = new Dictionary<string, int>();
            dic.Add(1, "선민");
            dic2.Add("선민2",2 );

            Console.WriteLine(dic[1]);
            Console.WriteLine(dic2["선민2"]);
        }
    }
}
