using System;
using System.Linq;

namespace ProblemsPractice
{
    class Program
    {
        static void Main(string[] args)
        {
            

            string j = "aA";
            string s = "LLLLRRRR";

            var simpleArray = new int[]
            {
                3,1,2,4
            };

            var twoDimensionalJaggedArray = new int[][]
            {
                new int[] {5,8,2},
                new int[] {3,9,2},
                new int[] {5,12,2}
            };
            string str = "MCMXCIV";
            string s2 = "c";

            var cls = new Longest_Common_Prefix();
            var a = cls.LongestCommonPrefix(new string[] { "flower", "flow", "floight" });
            Console.WriteLine(a);
        }
    }
}
