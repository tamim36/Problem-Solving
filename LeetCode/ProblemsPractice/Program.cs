using ProblemsPractice.Arrays;
using ProblemsPractice.Contests;
using ProblemsPractice.EasyProblems;
using ProblemsPractice.Greedy;
using ProblemsPractice.MasterCodingInterviewUdemy;
using ProblemsPractice.TwoPointer;
using System;
using System.Collections;
using System.Linq;

namespace ProblemsPractice
{
    class Program
    {
        static void Main(string[] args)
        {
            string j = "aA";
            string s = "bb";

            var num1 = new int[]
            {
               1
            };
            var num2 = new int[]
            {
               1,2,3,4,5,6,7,8
            };

            var twoDimensionalJaggedArray = new int[][]
            {
                new int[] {0,0,1,1},
                new int[] {1,0,1,0},
                new int[] {1,1,0,0}
            };
            string str = "b ";
            string s2 = "p#######";
            var strAra = new string[] { "flower", "flow", "floight" };

            var cls = new Weekly_Contest_261();
            //var a = cls.FindCommon(new char[] { 'a', 'b', 'c', 'x'}, new char[] { 'y', 'z', 'n' });
            var a = cls.Construct2DArray(num1, 1, 1);

            Console.WriteLine(a);



        }
    }
}
