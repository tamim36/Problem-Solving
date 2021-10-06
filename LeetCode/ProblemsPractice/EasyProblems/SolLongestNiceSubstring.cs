using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    // https://leetcode.com/problems/longest-nice-substring/
    public class SolLongestNiceSubstring
    {
        public string LongestNiceSubstring(string s)
        {
            string ans = string.Empty;
            string temp = string.Empty;
            int ansLength = 0;

            for (int i = 0; i < s.Length - 1; i++)
            {
                for (int j = i + 1; j <= s.Length; j++)
                {
                    int substringLength = j - i;
                    if (substringLength > ansLength)
                    {
                        temp = s.Substring(i, substringLength);
                        if (isNice(temp))
                        {
                            ans = temp;
                            ansLength = ans.Length;
                        }
                    }
                }
            }

            return ans;
        }

        private static bool isNice(string s)
        {
            int upper = 0;
            int lower = 0;

            foreach (var c in s)
            {
                if (c < 'a')
                {
                    upper |= 1 << (c - 'A');
                }
                else
                {
                    lower |= 1 << (c - 'a');
                }
            }

            return (upper ^ lower) == 0;
        }
    }
}
