using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Minimum_Number_of_Steps
    {
        public int MinSteps(string s, string t)
        {
            int steps = s.Length;

            int[] sChar = new int[26];

            foreach (char c in s)
            {
                sChar[c - 'a']++;
            }

            foreach (char c in t)
            {
                if (sChar[c - 'a'] > 0)
                {
                    sChar[c - 'a']--;
                    steps--;
                }
            }

            return steps;
        }
    }
}
