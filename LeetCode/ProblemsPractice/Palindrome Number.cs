using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Palindrome_Number
    {
        public bool IsPalindrome(int x)
        {
            int revNum = 0, originalNum = x;
            if (x < 0)
                return false;

            while (x > 0)
            {
                revNum *=  10 + (x % 10);
                x /= 10;
            }

            if (revNum == originalNum)
                return true;
            else
                return false;
        }
    }
}
