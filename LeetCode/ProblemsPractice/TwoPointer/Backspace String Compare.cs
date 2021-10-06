using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.TwoPointer
{
    public class Backspace_String_Compare
    {
        public bool BackspaceCompare(string s, string t)
        {
            int i = s.Length-1, j = t.Length-1, spaceS = 0, spaceT = 0;

            while (i >= 0 || j >= 0)
            {
                if (i >= 0 && s[i] == '#')
                {
                    i--;
                    spaceS++;
                }
                else if (j >= 0 && t[j] == '#')
                {
                    j--;
                    spaceT++;
                }
                else if (spaceS > 0)
                {
                    i--;
                    spaceS--;
                }
                else if (spaceT > 0)
                {
                    j--;
                    spaceT--;
                }
                else if ((i <= -1 || j <= -1) && i != j)
                {
                    return false;
                }
                else if (s[i] != t[j])
                {
                    return false;
                }
                else
                {
                    i--; j--;
                }
            }

            return true;
        }
    }
}
