using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class Minimum_Number_of_Swaps_to_Make_the_String_Balanced
    {
        public int MinSwaps(string s)
        {
            int stk = 0, count = 0;

            foreach (char c in s)
            {
                if (c == '[')
                    stk++;
                else if (stk > 0 && c == ']')
                {
                    count++;
                    stk--;
                }
            }

            return (int)Math.Ceiling((decimal)(s.Length / 2 - count) / 2);
        }
    }
}
