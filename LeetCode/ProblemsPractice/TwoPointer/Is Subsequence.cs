using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.TwoPointer
{
    public class Is_Subsequence
    {
        public bool IsSubsequence(string s, string t)
        {
            if (string.IsNullOrEmpty(s)) return true;
            int i = 0;
            foreach (char c in t)
            {
                if (i >= s.Length) break;
                else if (c == s[i]) i++;
            }

            return s.Length == i;
        }

        
    }
}
