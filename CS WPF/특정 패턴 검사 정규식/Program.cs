using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace 특정_패턴_검사_정규식
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Regex regex = new Regex(@"^([0-9a-zA-Z]+)@([0-9a-zA-Z]+)(\.[0-9a-zA-Z]+){1,}$");
            string email = "yeesonmin@naver.com";
            string email2 = "yeesonmin@navercom";

            if (regex.IsMatch(email))
            {
                Console.WriteLine("true");
            }
            else
            {
                Console.WriteLine("False");
            }

            if (regex.IsMatch(email2))
            {
                Console.WriteLine("true");
            }
            else
            {
                Console.WriteLine("False");
            }
        }
    }
}
