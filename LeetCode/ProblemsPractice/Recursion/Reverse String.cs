using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Recursion
{
    public class Reverse_String
    {
        public void ReverseString(char[] s)
        {
            int i = 0, j = s.Length-1;
            Solve(s, i, j);
        }

        private void Solve(char[] s, int i, int j)
        {
            if (i >= j)
                return;
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            Solve(s, ++i, --j);
        }
    }
}
