using System;
using System.Linq;

namespace ProblemsPractice
{
    class Program
    {
        static void Main(string[] args)
        {
            var cls = new To_Lower_Case();

            string j = "aA";
            string s = "LLLLRRRR";

            var gas = new int[]
            {
                3,3,4
            };

            var cost = new int[]
            {
                3,4,4
            };
            string str = "AbCdE";
            string s2 = "c";

            var a = cls.ToLowerCase(str);
            Console.WriteLine(a);
        }
    }
}
