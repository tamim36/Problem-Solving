using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    // 2186
    public class Minimum_Number_of_Steps_to_Make_Two_Strings_Anagram_II
    {
        public int MinSteps(string s, string t)
        {
            int sCount = s.Length, tCount = 0;

            int[] sAra = new int[130];
            foreach (char c in s)
            {
                sAra[c]++;
            }

            foreach (char c in t)
            {
                if (sAra[c] > 0)
                {
                    sCount--;
                    sAra[c]--;
                }
                else
                {
                    tCount++;
                }
            }

            return sCount + tCount;
        }
    }
}
