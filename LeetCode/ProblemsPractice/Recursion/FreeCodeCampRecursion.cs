using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Recursion
{
    public class FreeCodeCampRecursion
    {
        public int Recursion(int someVal)
        {
            if (someVal == 10)
                return someVal;

            return Recursion(someVal + 1);
        }

        public string ReverseString(string input)
        {
            if (string.IsNullOrEmpty(input))
                return "";
            return ReverseString(input.Substring(1)) + input[0];
        }
    }
}
