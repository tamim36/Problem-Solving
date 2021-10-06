using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.SlidingWindow
{
    public class Substrings_of_Size_Three
    {
        public int CountGoodSubstrings(string s)
        {
            int count = 0;

            for (int i=1; i < s.Length - 1; i++)
            {
                if (s[i - 1] != s[i] && s[i] != s[i + 1] && s[i - 1] != s[i + 1])
                    count++;
            }
            return count;
        }
    }
}
